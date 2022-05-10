# 一、导入依赖

```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-web</artifactId>
    <version>2.4.3</version>
</dependency>
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-test</artifactId>
    <version>2.4.3</version>
</dependency>
<!-- https://mvnrepository.com/artifact/io.springfox/springfox-boot-starter -->
<dependency>
    <groupId>io.springfox</groupId>
    <artifactId>springfox-boot-starter</artifactId>
    <version>3.0.0</version>
</dependency>
<dependency>
    <groupId>io.springfox</groupId>
    <artifactId>springfox-swagger2</artifactId>
    <version>3.0.0</version>
</dependency>
<dependency>
    <groupId>io.springfox</groupId>
    <artifactId>springfox-swagger-ui</artifactId>
    <version>3.0.0</version>
</dependency>
```

# 二、编写配置

```java
@Configuration
@EnableSwagger2
public class Swagger2Config {

    @Bean
    public Docket registerDocket(){
        Docket docket = new Docket(DocumentationType.OAS_30);

        return docket;
    }
    
    // docket 可以改设置，比如apiInfo,点源码即可配置
    
}
```

# 三、启动访问

```
http://localhost:9999/swagger-ui/index.html
```

# 四、其他

## 1. 只在开发和测试环境下生效

> 在配置文件中禁用

```yaml
springfox:
  documentation:
    swagger:
      v2:
        enabled: false
    swagger-ui:
      enabled: false
```

