## 一、简单使用步骤

### 1. 引入依赖

```xml
<dependency>
    <groupId>com.baomidou</groupId>
    <artifactId>mybatis-plus-boot-starter</artifactId>
    <version>3.4.3</version>
</dependency>
<dependency>
    <groupId>mysql</groupId>
    <artifactId>mysql-connector-java</artifactId>
</dependency>
<dependency>
    <groupId>com.alibaba</groupId>
    <artifactId>druid-spring-boot-starter</artifactId>
</dependency>
```

### 2. 编码

#### 2.1 配置包扫描,以继承方式写不用scan

```
@MapperScan("包路径") // 配置类上
```

#### 2.2 实体类

#### 2.3 Mapper接口

```java
@Repository
public interface UserMapper extends BaseMapper<User> {

}
```

### 3. test

```java
@SpringBootTest
class UserMapperTest {
    @Autowired
    private UserMapper mapper;
    @Test
    void test() {
        List<User> users = mapper.selectList(null);
        users.stream().forEach(System.out::println);
    }
}
```

### 4. 注意点

#### 4.1 自动装配

- 要有数据源