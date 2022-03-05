# 一、控制反转（IOC）概述

## 1. 什么是IOC（Inversion of Control)

> **控制反转**（Inversion of Control，缩写为**IoC**），是[面向对象编程](https://baike.baidu.com/item/面向对象编程/254878)中的一种设计原则，可以用来减低计算机[代码](https://baike.baidu.com/item/代码/86048)之间的[耦合度](https://baike.baidu.com/item/耦合度/2603938)。其中最常见的方式叫做**[依赖注入](https://baike.baidu.com/item/依赖注入/5177233)**（Dependency Injection，简称**DI**），还有一种方式叫“依赖查找”（Dependency Lookup）。通过控制反转，对象在被创建的时候，由一个调控系统内所有对象的外界实体将其所依赖的对象的引用传递给它。也可以说，依赖被注入到对象中。
>
> - **控制**：创建对象，对象属性辅助，对象直接的关系管理
> - **反转**：把原来开发人员创建对象的权限转移给代码之外的容器实现，开发人员主动管理对象
> - **正转**：由开发人员创建对象，主动管理对象
> - **容器**：一个服务软件，一个框架

> - **依赖查找：**容器提供回调接口和上下文条件给组件。EJB和Apache Avalon 都使用这种方式。这样一来，组件就必须使用容器提供的API来查找资源和协作对象，仅有的控制反转只体现在那些回调方法上（也就是上面所说的 类型1）：容器将调用这些回调方法，从而让应用代码获得相关资源。
>
>   **依赖查找还不明白!!!**
>
> - **依赖注入：**组件不做定位查询，只提供普通的Java方法让容器去决定依赖关系。容器全权负责的组件的装配，它会把符合依赖关系的对象通过JavaBean属性或者[构造函数](https://baike.baidu.com/item/构造函数)传递给需要的对象。通过JavaBean属性注射依赖关系的做法称为设值方法注入(Setter Injection)；将依赖关系作为构造函数参数传入的做法称为[构造器](https://baike.baidu.com/item/构造器)注入（Constructor Injection）

> spring 框架使用依赖注入（DI）来实现控制反转，把对象交给容器管理！

## 2. Java 中创建对象的方式

### 2.1 静态编码编译（构造方法）

```java
Person shine = new Person();
Person shine = new Person("shine",18);
```

### 2.2 反射

#### 2.2.1 通过类对象的newInstance()方法

```java
Person person =(Person)Class.forName("classname").newInstance();
object obj = Class.forName("classname").newInstance();
Mehtod m =  Class.forName("classname").getMethod("hello");
m.invoke(obj);
```

#### 2.2.1 通过构造器

```java
 // 可以选择构造函数getConstructor() 方法有不定参数
Constructor<Cat> constructor = Cat.class.getConstructor();
Cat cat= constructor.newInstance();
```

> 应用场景
>
> - 数据库连接
> - 数组扩充
> - 动态执行方法
> - JSON 和Java对象互转
> - Tomcat的Servlet 创建
> - MyBatis 的 ORM 
> - Spring Framework的Bean容器

### 2.3 序列化

```java
public class Cat implements Serializable {
    private  static  final long serialVersionUID=1L;
}
public static void main(String[] args){
   		Cat cat = new Cat();
        ObjectOutputStream objectOutputStream = new ObjectOutputStream(new 				FileOutputStream("data.obj"));
        objectOutputStream.writeObject(cat);
        objectOutputStream.close();

        ObjectInputStream objectInputStream = new ObjectInputStream(new FileInputStream("data.obj"));
        Cat cat1 = (Cat) objectInputStream.readObject();
        objectInputStream.close();
}
```

### 2.4 克隆

```java
public class Person implements Cloneable {
    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}
	Person person = new Person();
    Person clone =(Person) person.clone();
```

### 2.5 IOC(基于反射)

### 2.6 动态代理（基于反射）

## 3. Spring容器创建Bean的几种方式

### 3.1 构造注入

#### 3.1.1 无参构造器注入

```java
<bean id="user" class="wangchao.Cat"></bean>
```

#### 3.1.2 有参构造器注入

```xml
<bean id="zhangsan" class="wangchao.Author">
    <constructor-arg name="name" value="shine"></constructor-arg>
    <constructor-arg name="age" value="12"></constructor-arg>
    <constructor-arg name="birthday" value="2012/12/12"></constructor-arg>
    
    
    <constructor-arg name="authors">
        <array>
            <value>"张三"</value>
            <value>"张三"</value>
        </array>
    </constructor-arg>
    
    <constructor-arg name="books">
        <set>
            <value>"sdf"</value>
        </set>
    </constructor-arg>
    
    <constructor-arg name="hobby">
        <list>
            <value>"basketball"</value>
        </list>
    </constructor-arg>
    
    <constructor-arg name="education">
        <map>
            <entry key="ssdf" value="sdfs"></entry>
        </map>
    </constructor-arg>
    
    <constructor-arg name="prop">
        <value>
            k1=k2
            k2=k3
        </value>
    </constructor-arg>
</bean>
```

### 3.2 set 方法注入

```xml
<!-- 其他注入如上 -->
<bean id="zhangsan" class="wangchao.Author">
    <property name="name" value="lisi"></property>
</bean>
```

### 3.3 p名称空间注入（set 注入的简化）

```xml
xmlns:p="http://www.springframework.org/schema/p"
```

```java
<bean id="sdf" class="wangchao.Author" p:name="sdf"></bean>
```

### 3.4 c名称空间注入（构造方法的简化）

```xml
xmlns:c="http://www.springframework.org/schema/c"
```

```java
<bean id="sdf" class="wangchao.Author" c:name="sdf"></bean>
```

### 3.5 空值注入

```xml
<property name="name" >
    <null></null>
</property>
```

### 3.6 特殊符合注入

> xml 符号转义

```xml
<property name="name" >
    <value>
        <![CDATA[<<NAFJING>>]]>
    </value>
</property>
```

### 3.7 注入其他bean

#### 3.7.1 注入外部Bean

```xml
<property name="obj" ref="idofobj"></property>
```

####  3.7.2 注入内部Bean

```xml
<property name="dept">
    <!-- 按正常的bean 写 -->
	<bean id="" class="">
        
    </bean>
</property>
```

#### 3.7.3  级联赋值

```xml
<property name="dept" ref=""></property>
<property name="dept.name" value="sfs"></property>
```



## 4. Spring 容器的Bean的类型

### 4.1 普通Bean和工厂Bean

> 定义什么类型，就返回什么类型

> 1. 创建工厂Bean 实现FactoryBean接口
>
> 2. 返回工厂中的类型

```java
public class CarFactory implements FactoryBean {
    @Override
    public Object getObject() throws Exception {
        return new Car();
    }

    @Override
    public boolean isSingleton() {
        return false;
    }

    @Override
    public Class<?> getObjectType() {
        return Car.class;
    }
}
```

## # 4.2 单实例和多实例

> - scope  属性指定
> - singleton 
>   - 单实例
>   - 加载配置文件时创建
> - prototype
>   - 多实力
>   - 获取时创建
> - request
>   - 一次请求
> - session
>   - 一次会话

## 5. Bean的生命周期

### 5.1 Bean 的生命周期

> 1. 通过构造器创建bean 实例（无惨构造器构造）
> 2. 为bean的属性设置值（）
> 3. 把Bean 实例 传递给后置处理器方法
> 4. 调用初始化方法
> 5. 把Bean 实例 传递给后置处理器方法
> 6. 获取使用Bean
> 7. 销毁bean

### 5.2 Bean 添加后置处理器

```xml
<bean id="myBeanPost" class="wangchao.MyBeanPost"></bean>
```

```java

public class MyBeanPost implements BeanPostProcessor {
    @Override
    public Object postProcessBeforeInitialization(Object bean, String beanName) throws BeansException {
        return bean;
    }

    @Override
    public Object postProcessAfterInitialization(Object bean, String beanName) throws BeansException {
        return bean;
    }
}
```

## 6. 自动装配

```xml
<!-- 属性名称和要装配的名称一样 -->
<bean id="myBeanPost" class="wangchao.MyBeanPost" autowire="byName"></bean>
<!-- 属性类型 -->
<bean id="myBeanPost" class="wangchao.MyBeanPost" autowire="byType"></bean>
```

## 7. 引入外部文件

```xml
<context:property-placeholder location="classpath:jdbc.properties" />
```

## 8. 相关注解

```xml
<context:component-scan base-package="wangchao"></context:component-scan>
<!--自定义规则 -->
 <context:component-scan base-package="wangchao" use-default-filters="false">
        <context:include-filter type="" expression=""/>
        <context:exclude-filter type="" expression=""/>
    </context:component-scan>
```

### 8.1 @Component

### 8.2 @Service

### 8.3 @Controller

### 8.4 @Repository

### 8.5 @AutoWired

> 根据属性类型进行自动注入

```java
@AutoWired
private UserDao userDao;
```

### 8.6 @Qualifier

> 根据属性名称进行注入

```java
@AutoWired
@Quelifier("id")
private UserDao userDao;
```

### 8.7 @Resource

> 根据属性名称或者属性类型注入
>
> (javax.annotation.Resource)

```java
@Resource
private UserDao userDao;
@Resourve(name = "id");
private UserDao userDao;
```

### 8.8 @Value

> 注入普通类型

### 8.9 @Nullable

> 是否为空
>
> @Target({ElementType.METHOD, ElementType.PARAMETER, ElementType.FIELD})

### 8.10 使用配置类

```java
@Configuration
@ComponentScans({
        @ComponentScan(includeFilters = {})
})
public class SpringConfig {
    
}
```

### 8.11 @import

```java
@Import({TestA.class,TestB.class})
@Configuration
public class SpringConfig {
    
}
```

