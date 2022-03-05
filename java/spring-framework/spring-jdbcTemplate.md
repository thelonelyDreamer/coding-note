# 一、JDBC Template 简介

> JDBC已经能够满足大部分用户最基本的需求，但是在使用JDBC时，必须自己来管理数据库资源如：获取PreparedStatement，设置SQL语句参数，关闭连接等步骤。
>
>  JdbcTemplate是Spring对JDBC的封装，目的是使JDBC更加易于使用。JdbcTemplate是Spring的一部分。JdbcTemplate处理了资源的建立和释放。他帮助我们避免一些常见的错误，比如忘了总要关闭连接。他运行核心的JDBC工作流，如Statement的建立和执行，而我们只需要提供SQL语句和提取结果。
> Spring源码地址：https://github.com/spring-projects/spring-framework
> 在JdbcTemplate中执行SQL语句的方法大致分为3类：
>
> execute：可以执行所有SQL语句，一般用于执行DDL语句。
> update：用于执行INSERT、UPDATE、DELETE等DML语句。
> queryXxx：用于DQL数据查询语句。
>

# 二、如何使用

## 1. 导入依赖

```xml
<dependency>
    <groupId>mysql</groupId>
    <artifactId>mysql-connector-java</artifactId>
    <version>8.0.19</version>
</dependency>
<dependency>
    <groupId>com.alibaba</groupId>
    <artifactId>druid</artifactId>
    <version>1.2.4</version>
</dependency>
<dependency>
    <groupId>org.springframework</groupId>
    <artifactId>spring-jdbc</artifactId>
    <version>5.3.4</version>
</dependency>
<!-- 可以不导入，事务一般在service 层控制 -->
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

## 2. 编写配置文件

```xml
<context:property-placeholder location="classpath:jdbc-mysql.properties"></context:property-placeholder>
<bean id="dataSource" class="com.alibaba.druid.pool.DruidDataSource">
    <property name="driverClassName" value="${jdbc.driverClass}"></property>
    <property name="username" value="${jdbc.username}"></property>
    <property name="password" value="${jdbc.password}"></property>
    <property name="url" value="${mysql.url}"></property>
    <property name="initialSize" value="${jdbc.init}"></property>
    <property name="maxActive" value="${jdbc.maxActive}"></property>
</bean>
<bean id="jdbcTemplate" class="org.springframework.jdbc.core.JdbcTemplate">
    <property name="dataSource"ref="dataSource"></property>
</bean>
```

## 3. 编写代码

### 3.1 创建实体类

```java
public class Book {

}
```

### 3.2  创建dao层代码

```java
@Repository
public class BookDaoImpl implements BookDao {
    @Autowired
    private JdbcTemplate jdbcTemplate;

    @Override
    public Integer addBook(Book book) {
        return null;
    }
}
```

### 3.3 测试

```java
@SpringJUnitConfig(locations = "classpath:application.xml")
public class BookDaoTest {
    @Autowired
    private BookDao bookDao;
    @Test
    public void addBookTest(){
        bookDao.addBook(new Book("java"));
    }
}

```

# 三、增删查改

## 1. 增加一条数据

```java
public class BookDaoImpl implements BookDao {
    @Autowired
    private JdbcTemplate jdbcTemplate;

    @Override
    public Integer addBook(Book book) {
        String sql = "insert into t_book(b_name)values(?)";
        Object[] param = {book.getName()};
        int result = jdbcTemplate.update(sql,param);
        return null;
    }
}
```



## 2. 删除一条数据

```java
public class BookDaoImpl implements BookDao {
    @Autowired
    private JdbcTemplate jdbcTemplate;

    @Override
    public Integer deleteBook(Integer id) {
        String sql = "delete from t_book where b_id=? ";
        Object[] param = {id};
        int result = jdbcTemplate.update(sql,param);
        return null;
    }
}
```

## 3. 修改一条数据

```java
public class BookDaoImpl implements BookDao {
    @Autowired
    private JdbcTemplate jdbcTemplate;

    @Override
    public Integer updateBook(Book book) {
        String sql = "update t_book set b_name=? where t_id = ?";
        Object[] param = {book.getName(),book.getId()};
        int result = jdbcTemplate.update(sql,param);
        return null;
    }
}
```

## 4. 查询

```java
public class BookDaoImpl implements BookDao {
    @Autowired
    private JdbcTemplate jdbcTemplate;

    @Override
    public Integer selectBookById(Integer id) {
        String sql = "select b_name as name from t_book whele b_id = ?";
        Object[] param = {id};
        Book book = jdbcTemplate.update(sql,new BeanPropertyRowMapper<Book>(Book.class),param);
        return result;
    }
       
    public Integer findCount() {
        String sql = "select count(*) from t_book";
        int result = jdbcTemplate.queryForObject(sql,Integer.class);
        return result;
    }
    
    @Override
    public List<Book> queryAll() {
        String sql = "select * from t_book";
        List<Book> result = jdbcTemplate.query(sql, new BeanPropertyRowMapper<Book>(Book.class));
        return result;
    }
}
```

## 5. 批量删除

```java
// object[] 是sql参数 列表
public void bathAdd(List<Object[]> batchArgs){
    String sql = "delete from t_book where id = ?";
    jdbcTemplate.batchUpdate(sql,batchArgs);
}
```

## 6.  批量添加

```
// object[] 是sql参数 列表
public void bathAdd(List<Object[]> batchArgs){
    String sql = "???";
    jdbcTemplate.batchUpdate(sql,batchArgs);
}
```

## 7. 批量修改

> 跟 56 差不多