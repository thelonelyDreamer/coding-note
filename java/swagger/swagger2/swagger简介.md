# Swagger简介

## 1. 为什么要学Swagger

> 前后端分离的沟通问题

- 制定先指定的schema[计划的提纲]，实时更新最新的API，降低集成的风险
- 前端测试后端接口：postman
- 后端提供接口，实时更新最新的消息及改动

## 2. swagger特点

- 号称世界上最流行的api 框架
- Restful 文档在线自动生成工具=》API文档与API定义同步更新
- 直接运行，可以在线测试API接口
- 支持多语言

## 3. swagger资源

官网: http://swagger.io



## 4. 在项目中使用swagger

相关依赖

```xml
<!-- https://mvnrepository.com/artifact/io.springfox/springfox-swagger2 -->
<dependency>
    <groupId>io.springfox</groupId>
    <artifactId>springfox-swagger2</artifactId>
    <version>3.0.0</version>
</dependency>
<!-- https://mvnrepository.com/artifact/io.springfox/springfox-swagger-ui -->
<dependency>
    <groupId>io.springfox</groupId>
    <artifactId>springfox-swagger-ui</artifactId>
    <version>3.0.0</version>
</dependency>

```

配置swagger

Swagger 的实例bean 为docket

```java
@Configuration
@EnableSwagger2
public class SwaggerConfig {
    //配置作者信息，页面信息
    Docket docket = new Docket(DocumentationType.SWAGGER_2);
        ApiInfo apiInfo = new ApiInfo("Api Documentation",
                "Api Documentation",
                "1.0",
                "urn:tos",
                new Contact("wangchao", "", ""),
                "Apache 2.0",
                "http://www.apache.org/licenses/LICENSE-2.0",
                new ArrayList());

        docket.apiInfo(apiInfo);
    	
    	        //配置要扫描接口的方式
//        docket.select().apis(RequestHandlerSelectors.basePackage("com.felixwc.swagger.controller")).build();
//        docket.select().apis(RequestHandlerSelectors.withClassAnnotation(RestController.class)).build();
        docket.select().apis(RequestHandlerSelectors.withMethodAnnotation(GetMapping.class)).paths(PathSelectors.ant("/com/felixwc/swagger/**")).build();
        //是否启动swagger
        docket.enable(false);
    
        return docket;
    
    //配置分组
    docket.groupName("test");
}
```

测试运行 http://localhost:8080/swagger-ui.html

http://localhost:8080/swagger-ui/index.html

## 5. swagger常用注解

见另一篇文档

## 6.swagger 总结

- 添加注解
- 接口文档实时更新
- 可以在线测试

