# 一、SpringMVC

## 1.1 引言

> **Java 开源框架，SpringFramework的一个独立模块**
>
> MVC框架，在项目中开辟MVC层次结构
>
> 采用工厂模式， 对控制器中的功能包装，简化，践行工厂模式

## 1.2 MVC架构

> MVC： Model View Controller  模型 视图 控制器
>
> 模型：即业务模型，负责完成数据中的数据通信处理，对应项目中的sevice和dao
>
> 视图：渲染数据，生成页面，对应项目中的JSP
>
> 控制器：直接对接请求，调度模型，选择视图，对应项目中的servlet

> MVC是现在软件开发中的最流行的代码结构形态；
>
> 人们根据负责的不同逻辑，将项目中的代码分成MVC3个层次；
>
> 层次内部职责单一，层次之间的耦合度低；
>
> 符合低耦合，高内聚的设计理念，也有利于项目的长期维护。



# 二、简单开发流程

## 2.1 导入依赖

## 2.2 配置核心（前端）控制器

## 2.3 后端控制器

## 2.4 配置文件

### 2.4.0 Spring 默认xml头文件

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:context="http://www.springframework.org/schema/context"
       xmlns:mvc="http://www.springframework.org/schema/mvc"
       xsi:schemaLocation="http://www.springframework.org/schema/beans 			 http://www.springframework.org/schema/beans/spring-beans.xsd
       http://www.springframework.org/schema/context http://www.springframework.org/schema/context/spring-context.xsd
       http://www.springframework.org/schema/mvc http://www.springframework.org/schema/mvc/spring-mvc.xsd ">
</beans>
```

### 2.4.1 使用注解开发

```xml
    <!-- 注解扫描 -->
    <context:component-scan base-package="com.wangchao.spring_mvc.controller">	             </context:component-scan>
    <!-- 注解驱动 -->
    <mvc:annotation-driven></mvc:annotation-driven>
	<!-- 处理静态资源 -->
	<mvc:default-servlet-handler />
    <!--  视图解析器
        1.捕获后端控制器的返回值  eg: "index"
        2.解析 在返回值的前后 拼接字符串 eg： "/index.jsp"
    -->
    <bean class="org.springframework.web.servlet.view.InternalResourceViewResolver">
    <!--  前后缀  -->
        <property name="prefix" value="/jsp/"></property>
        <property name="suffix" value=".jsp"></property>
    </bean>
```



## 2.5 访问

# 三、原理解读

## 3.1 核心部件

> 前端控制器、处理映射器、处理适配器、视图解析器

# 四、知识点详解

## 4.1 收参

### 4.1.1 Get请求

## 4.2 传值和跳转

# 五、应用