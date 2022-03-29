## 一、 搭建步骤

#### 1. 倒入相关依赖

```xml
 <dependency>
 	<groupId>mysql</groupId>
 	<artifactId>mysql-connector-java</artifactId>
 </dependency>
 <dependency>
 	<groupId>org.hibernate</groupId>
	 <artifactId>hibernate-core</artifactId>
 </dependency>
```



#### 2. 创建Hibernate 配置文件

```xml
<?xml version="1.0" encoding="GBK"?>
<!-- 指定Hibernate配置文件的DTD信息 -->
<!DOCTYPE hibernate-configuration PUBLIC
        "-//Hibernate/Hibernate Configuration DTD 3.0//EN"
        "http://www.hibernate.org/dtd/hibernate-configuration-3.0.dtd">
<!-- hibernate- configuration是连接配置文件的根元素 -->
<hibernate-configuration>
    <session-factory>
        <!-- 指定连接数据库所用的驱动 -->
        <property name="connection.driver_class">com.mysql.cj.jdbc.Driver</property>
        <!-- 指定连接数据库的url，hibernate连接的数据库名 -->
        <property name="connection.url">jdbc:mysql://localhost/test</property>
        <!-- 指定连接数据库的用户名 -->
        <property name="connection.username">root</property>
        <!-- 指定连接数据库的密码 -->
        <property name="connection.password">wangchao</property>
        <!-- 指定连接池里最大连接数 -->
        <property name="hibernate.c3p0.max_size">20</property>
        <!-- 指定连接池里最小连接数 -->
        <property name="hibernate.c3p0.min_size">1</property>
        <!-- 指定连接池里连接的超时时长 -->
        <property name="hibernate.c3p0.timeout">5000</property>
        <!-- 指定连接池里最大缓存多少个Statement对象 -->
        <property name="hibernate.c3p0.max_statements">100</property>
        <property name="hibernate.c3p0.idle_test_period">3000</property>
        <property name="hibernate.c3p0.acquire_increment">2</property>
        <property name="hibernate.c3p0.validate">true</property>
        <!-- 指定数据库方言 -->
        <property name="dialect">org.hibernate.dialect.MySQL8Dialect</property>
        <!-- 根据需要自动创建数据表 -->
        <property name="hbm2ddl.auto">update</property>
        <!-- 显示Hibernate持久化操作所生成的SQL -->
        <property name="show_sql">true</property>
        <!-- 将SQL脚本进行格式化后再输出 -->
        <property name="hibernate.format_sql">true</property>
        <!-- 罗列所有的映射文件 -->
        <mapping resource=""/>
    </session-factory>
</hibernate-configuration>
```

> 核心配置： session-factory
>
> SessionFactory: 针对单个数据库映射经过编译的内存镜像文件，将数据库转换为一个Java 可以识别的镜像文件.
>
> 构建SessionFactory 非常耗费资源，一个工程只要有一个sessionFactory就可以了

#### 3. 创建实体类

1. Customer.class

```java
@Data
public class Customer {
    private Integer id;
    private String name;
    private Set<Order> orders;
}
```

2. Order.class

```java
@Data
public class Order {
    private Integer id;
    private String name;
    private Customer customer;
}
```

#### 4. 创建实体类-关系映射文件

```xml
<?xml version="1.0" encoding="GBK"?>
<!-- 指定Hibernate配置文件的DTD信息 -->
<!DOCTYPE hibernate-mapping PUBLIC
        "-//Hibernate/Hibernate Configuration DTD 3.0//EN"
        "http://www.hibernate.org/dtd/hibernate-mapping-3.0.dtd">
<hibernate-mapping>
    <class name="com.felixwc.java8.frame.hibernate.pojo.Person" table="person">
        <id name="id" type="java.lang.Integer">
            <column name="id"></column>
            <generator class="identity"></generator>
        </id>
        <property name="name" type="java.lang.String">
            <column name="name"></column>
        </property>
        <property name="weight" type="java.lang.Double">
            <column name="weight"></column>
        </property>
    </class>
</hibernate-mapping>
```

#### 5. 调用 Hibernate API 完成操作

```
Configuration configure = new Configuration().configure();
SessionFactory sessionFactory = configure.buildSessionFactory();
Session session = sessionFactory.openSession();
Person person = new Person();
person.setName("123");
person.setWeight(12.33);
person.setId(1);
session.save(person);
session.beginTransaction().commit();
session.close();
```

---

## 二、级联关系

### 2.1 一对多

### 2.2 多对一

### 2.3 多对多

---

## 三 

