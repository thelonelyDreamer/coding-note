# 一、spring 5 整合 Junit 4

## 1. 整合步骤

### 1. 导入依赖

```xml
<!-- https://mvnrepository.com/artifact/org.springframework/spring-test -->
<dependency>
    <groupId>org.springframework</groupId>
    <artifactId>spring-test</artifactId>
    <version>5.3.4</version>
    <scope>test</scope>
</dependency>
<dependency>
    <groupId>org.junit.jupiter</groupId>
    <artifactId>junit-jupiter-engine</artifactId>
    <version>5.7.1</version>
    <scope>test</scope>
</dependency>
<dependency>
    <groupId>junit</groupId>
    <artifactId>junit</artifactId>
    <version>4.13</version>
    <scope>test</scope>
</dependency>
```

### 2. 编码测试

```java
@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("classpath:application.xml")
public class JDBCApplicationTest {
    @Autowired
    private DataSource dataSource;

    @Test
    public void getDataSource(){
        System.out.println(dataSource);
    }
}
```

##  2. 相关注解

> @Before：初始化方法
> @After：释放资源
> @Test：测试方法，在这里可以测试期望异常和超时时间
> @Ignore：忽略的测试方法
> @BeforeClass：针对所有测试，只执行一次，且必须为static void
> @AfterClass：针对所有测试，只执行一次，且必须为static void
> 一个JUnit4 的单元测试用例执行顺序为：
> @BeforeClass –> @Before –> @Test –> @After –> @AfterClass
> 每一个测试方法的调用顺序为：
> @Before –> @Test –> @After



# 二、spring 5 整合 Junit 5

## 1. 整合步骤

### 1. 导入依赖

```xml
<dependency>
    <groupId>org.springframework</groupId>
    <artifactId>spring-test</artifactId>
    <version>5.3.4</version>
    <scope>test</scope>
</dependency>
<!-- https://mvnrepository.com/artifact/org.junit.jupiter/junit-jupiter-api -->
<dependency>
    <groupId>org.junit.jupiter</groupId>
    <artifactId>junit-jupiter-api</artifactId>
    <version>5.7.0</version>
    <scope>test</scope>
</dependency>
```

### 2. 编码测试

```java
@ExtendWith(SpringExtension.class)
@ContextConfiguration("classpath:application.xml")
// 复合注解
//@SpringJUnitConfig(locations ="classpath:application.xml")
public class JDBCApplicationTest {
    @Autowired
    private DataSource dataSource;

    @Test
    public void getDataSource(){
        System.out.println(dataSource);
    }
}
```

## 2. 相关注解

> - Junit 5常用注解
>   @Test	表示方法是一种测试方法。与 JUnit 4 的@Test 注解不同，此注释不会声明任何属性
>   @BeforeEach	表示方法在每个测试方法运行前都会运行
>   @AfterEach	表示方法在每个测试方法运行之后都会运行
>   @BeforeAll	表示方法在所有测试方法之前运行，注意使用该注解的方法必须返回 void、访问级别不允许为 private，且必须声明为静态 (static) 方法
>   @AfterAll	表示方法在所有测试方法之后运行，而且该注解的使用限制与 @BeforeAll 一致
>   @ParameterizedTest	表示方法是参数化测试
>   @RepeatedTest	表示方法是重复测试模板
>   @TestFactory	表示方法是动态测试的测试工程
>   @TestInstance	用于配置测试实例生命周期
>   @TestTemplate	表示方法是为多次调用的测试用例的模板
>   @DisplayName	为测试类或者测试方法自定义一个名称
>   @Nested	表示带注解的类是嵌套的非静态测试类，@BeforeAll 和 @AfterAll 方法不能直接在 @Nested 测试类中使用，除非修改测试实例生命周期
>   @Tag	用于在类或方法级别声明用于过滤测试的标记
>   @Disabled	用于禁用测试类或测试方法
>   @ExtendWith	用于注册自定义扩展，该注解可以继承
>   官方网址：https://junit.org/junit5/docs/current/user-guide/
> - 断言常用方法
>   assertAll	分组断言，执行其中包含的所有断言
>   assertEquals	判断断言预期值和实际值是否相等
>   assertNotEquals	判断断言预期值和实际值是否不相等
>   assertArrayEquals	判断断言预期数组和实际数组相等
>   assertTrue	判断断言条件是否为真
>   assertFalse	判断断言条件是否为假
>   assertNull	判断断言条件是否为空
>   assertNotNull	判断断言条件是否不为空
>   assertSame	判断两个对象引用是否指向同一个对象
>   assertTimeout	断言超时
>   fail	使单元测试失败
>   官方网址：https://junit.org/junit5/docs/5.2.0/api/org/junit/jupiter/api/Assertions.html
> - 假设测试常用方法
>   assumeFalse	假设为 false 时才会执行，如果为 true，那么将会直接停止执行
>   assumeTrue 	假设为 true 时才会执行，如果为 false，那么将会直接停止执行
>   assumingThat	assumingThat 接受一个函数式接口 Executable，假设为 true 时执行，将会执行 Executable，否则不会执行 Executable。
> - 条件测试常用注解
>   - 操作系统条件	
>     - @EnabledOnOs 、
>     - @DisabledOnOs	
>     - 值：LINUX、WINDOWS、 MAC 和 OTHER
>   - Java 运行环境条件	
>     - @EnabledOnJre 、
>     - @DisabledOnJre	
>     - 值：JAVA_8、JAVA_9、JAVA_10 和 OTHER
>   - 系统属性条件	
>     - @EnabledIfSystemProperty 、
>     - @DisabledIfSystemProperty	
>     - 值：named(参数名称) 和 matches(正则)
>   - 环境变量条件	
>     - @EnabledIfEnvironmentVariable 、
>     - @DisabledIfEnvironmentVariable	
>     - 值：named 和 matches
> - 参数化测试参数源
>   - @ValueSource	
>     - 允许指定原生类型的数组，并且只能用于为每个参数化测试调用提供单个参数
>   - @EnumSource	
>     - 提供了一种使用 Enum 常量的便捷方法
>   - @MethodSource	
>     - 允许引用测试类或外部类的一个或多个工厂方法。这个方法必须是 static ，返回值必须是一个 Stream、Iterable、Iterator 或者参数数组。并且这些方法不能有参数。外部类的方法则必须是 static 的。
>   - @CsvSource	
>     - 允许将参数列表定义为以逗号分隔的值（即 String 类型）
>   - @ArgumentsSource	
>     - 可用于指定自定义，可重用 ArgumentsProvider。自定义时需要实现 ArgumentsProvider 接口，并且必须将实现声明为 public 类或 static 嵌套类