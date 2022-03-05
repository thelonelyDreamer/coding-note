# 一、AOP 概述

## 1. 简介

> 在软件业，AOP为Aspect Oriented Programming的缩写，意为：[面向切面编程](https://baike.baidu.com/item/面向切面编程/6016335)，通过[预编译](https://baike.baidu.com/item/预编译/3191547)方式和运行期间动态代理实现程序功能的统一维护的一种技术。AOP是[OOP](https://baike.baidu.com/item/OOP)的延续，是软件开发中的一个热点，也是[Spring](https://baike.baidu.com/item/Spring)框架中的一个重要内容，是[函数式编程](https://baike.baidu.com/item/函数式编程/4035031)的一种衍生范型。利用AOP可以对业务逻辑的各个部分进行隔离，从而使得业务逻辑各部分之间的[耦合度](https://baike.baidu.com/item/耦合度/2603938)降低，提高程序的可重用性，同时提高了开发的效率。

## 2. 优点

> - 实现方法层面的解耦合
> - 将核心代码与辅助代码分开

## 3. 应用场景

> 日志记录，性能统计，安全控制，事务处理，异常处理等

# 二、AOP 基本概念

> - 连接点
>
>   - 类里面可以的增强的方法
>
> - 切入点
>
>   - 实际被增强的方法
>
>   - 切入点表达式 
>
>     - ```java
>       [权限修饰符][返回类型][类全路径][方法名称][参数列表]
>       	* Integer com.wangchao.Dao.add(..)
>           * Integer com.wangchao.Dao.*(..)
>           * Integer com.wangchao.*.add(..)
>           * Integer *..Dao.add(..)
>       ```
>
> - 通知
>
>   - 实现增强的逻辑
>   - 前置通知，后置通知 ，环绕通知、异常通知、最终通知
>
> - 切面
>
>   - 是通知应用到切入点的过程

# 三、AOP 底层原理

> 动态代理
>
> -  有接口,使用JDK动态代理
> -  没有接口，使用CGIB动态代理

> Spring 一般使基于AspectJ 实现AOP操作
>
> - ​	AspectJ 不是Spring 的一部分

## 1. 实现接口创建代理对象

```java
(接口对象)Proxy.newProxyInstance(类加载器，interfaces数组，new 代理器对象)
```

## 2.创建当前类型子类创建代理对象



# 四、相关注解

> 1. 开启注解扫描
>
>    ```
>    </context:component-scan>
>    ```
>
> 2. 创建User和UserProxy 对象
>
> 3. 使用@Aspect 
>
> 4. 配置不同类型的通知

```java
@Component
@Aspect
public class UserProxy {
    @Before(value = "execution(* * *..*.*(..))")
    public void before(){
        
    }
    
    @After()
    
    @Around()
    
}
```

> 可以在@Before同级包找其他注解
>
> @Before
>
> @After
>
> @Around
>
> @AfterThrowing
>
> @AfterReturn

**抽取相同注解**

```java
@Pointcut(value = "execution(* *..*.*(..))")
public void pointDemo(){
    
}

@Before(value = "pointDemo()")
public void before(){

}
```

**增强类优先级**

@Order(1)

**xml 配置**

```java
<aop:config>
    <aop:pointcut id="p" expression="execution(* wangchao.*.*(..))"/>
    <aop:aspect ref="userProxy">
        <aop:before method="before" pointcut-ref="p"></aop:before>
    </aop:aspect>
</aop:config>
```