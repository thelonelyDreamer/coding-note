# 一、事务的基本概念

## 1. 什么是事务

> - 事务是数据库操作的最基本的单元，逻辑上一组操作

## 2.事务的四个特性

> - 原子性
>   - 一组操作全都成功，或者全都失败
> - 一致性
>   - 事务执行后，数据库状态与其它业务规则保持一致。如转账业务，无论事务执行成功与否，参与转账的两个账号余额之和应该是不变的。
> - 隔离性
>   - 多个事务操作一个记录，彼此不会产生影响
> - 持久性
>   - 一旦事务提交成功，事务中所有的数据操作都必须被持久化到数据库中，即使提交事务后，数据库马上崩溃，在数据库重启时，也必须能保证通过某种机制恢复数据。

# 二、 实现事务的方式

## 1. 编程式

```java
@Sevice
public void UserService(){
    try{
        // 开启事务
        // 进行业务操作
        // 提交事务
    }catch(){
        // 事务回滚
    }finally{
        //关闭一些资源
    }
}
```

## 2. 声明式

> 使用AOP

### 2.1 导入相关依赖

```xml
<dependency>
    <groupId>org.springframework</groupId>
    <artifactId>spring-tx</artifactId>
    <version>5.3.4</version>
</dependency>
<dependency>
    <groupId>org.springframework</groupId>
    <artifactId>spring-aspects</artifactId>
    <version>5.3.4</version>
</dependency>
```

### 2.2 修改配置文件

```xml
<bean id="transactionManager" class="org.springframework.jdbc.datasource.DataSourceTransactionManager">
    <property name="dataSource" ref="dataSource"></property>
</bean>
<tx:annotation-driven transaction-manager="transactionManager"></tx:annotation-driven>
```

### 2.3 添加注解

> @Transactional ,添加到需要事务管理的类或者方法上

```java
public @interface Transactional {
    // 事务管理器
    @AliasFor("transactionManager")
    String value() default "";
    @AliasFor("value")
    String transactionManager() default "";

    String[] label() default {};	
    // 事物的传播行为
    Propagation propagation() default Propagation.REQUIRED;
	// 隔离级别
    Isolation isolation() default Isolation.DEFAULT;
	// 超时时间 设置事务的提交时间
    int timeout() default -1;
    String timeoutString() default "";
	// 是否只读
    boolean readOnly() default false;
    // 根据异常回滚或者不回滚
    // 回滚
    Class<? extends Throwable>[] rollbackFor() default {};
    String[] rollbackForClassName() default {};
    // 不回滚
    Class<? extends Throwable>[] noRollbackFor() default {};
    String[] noRollbackForClassName() default {};
}
```

### 2.4 xml 配置事务

```xml
<bean id="transactionManager" class="org.springframework.jdbc.datasource.DataSourceTransactionManager">
    <property name="dataSource" ref="dataSource"></property>
</bean>
<tx:advice id="txadvice">
    <tx:attributes>
        <tx:method name="get" propagation="REQUIRED"/>
    </tx:attributes>
</tx:advice>
<aop:config>
    <aop:pointcut id="pt" expression="execution(* com.felixwc.*.*(..))"/>
    <aop:advisor advice-ref="txadvice" pointcut-ref="pt"></aop:advisor>
</aop:config>
```

### 2.5 通过配置类

```java
@Configuration
@ComponentScan({"com"})
@EnableTransactionManagement
public class MyConfig {
    // 事务管理器 数据源 连接模板
}
```



## 3. 事务的传播行为

> 多事物方法直接调用，这个过程中是如何进行管理的
>
> - PROPAGATION_REQUIRED	
>   - 支持当前事务，假设当前没有事务。就新建一个事务
> - PROPAGATION_SUPPORTS	
>   - 支持当前事务，假设当前没有事务，就以非事务方式运行
> - PROPAGATION_MANDATORY	
>   - 支持当前事务，假设当前没有事务，就抛出异常
> - PROPAGATION_REQUIRES_NEW	
>   - 新建事务，假设当前存在事务。把当前事务挂起
> - PROPAGATION_NOT_SUPPORTED	
>   - 以非事务方式运行操作。假设当前存在事务，就把当前事务挂起
> - PROPAGATION_NEVER	
>   - 以非事务方式运行，假设当前存在事务，则抛出异常
> - PROPAGATION_NESTED	
>   - 如果当前存在事务，则在嵌套事务内执行。如果当前没有事务，则执行与PROPAGATION_REQUIRED类似的操作。

## 4. 事物的隔离级别

> 不考虑隔离性，会产生以下问题
>
> - 脏读：一个事务读取到另外一个事务未提交的数据
> - 不可重复读：不可重复读指的是在同一事务内，不同的时刻读到的同一批数据可能是不一样的，可能会受到其他事务的影响，比如其他事务改了这批数据并提交了。
> - 幻读（虚读）：一个未提交的事物读到了另外一个已经提交事务中添加的数据

![image-20210817170702038](spring-%E5%A3%B0%E6%98%8E%E5%BC%8F%E4%BA%8B%E5%8A%A1.assets/image-20210817170702038.png)

