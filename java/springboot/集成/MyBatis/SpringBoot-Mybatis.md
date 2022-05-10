## 一、初步集成

### 1. 依赖

```xml
<dependency>
    <groupId>mysql</groupId>
    <artifactId>mysql-connector-java</artifactId>
</dependency>
<dependency>
    <groupId>com.alibaba</groupId>
    <artifactId>druid</artifactId>
    <version>1.2.6</version>
</dependency>
<dependency>
    <groupId>com.baomidou</groupId>
    <artifactId>mybatis-plus-boot-starter</artifactId>
    <version>3.4.2</version>
</dependency>
```

### 2. 配置

```yml
server:
  port: 9999
spring:
  application:
    name: mybatis-druid-mysql
  datasource:
    type: com.alibaba.druid.pool.DruidDataSource
    url: jdbc:mysql://localhost:3306/test?useUnicode=true&characterEncoding=UTF-8&serverTimezone=GMT%2B8
    username: root
    password: wangchao
mybatis:
  type-aliases-package: com.felixwc.mybatis.druid.mysql.pojo
  mapper-locations: mapper/*.xml

```

### 3. 写接口和mapper.xml，或者使用注解

```java
@Mapper
@Repository
public interface UserDaoMapper {
    List<User> getAllUser();
}
```

```xml
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.felixwc.mybatis.druid.mysql.mapper.UserDaoMapper">
    <select id="getAllUser" resultType="User">
        select id,name,address from test
    </select>

</mapper>
```

这样在spring工厂中就有一个接口类型的实例Bean



## 二、配置文件写法 也可在yml 中配置

### 1. application.yml

```yml
mybatis:
  #别名
  type-aliases-package: com.felixwc.mybatis.druid.mysql.pojo
  #mapper文件的位置
  mapper-locations: classpath:mapper/*.xml
```

### 2. mybatis-config.xml

```xml
<!DOCTYPE configuration
        PUBLIC "-//mybatis.org//DTD Config 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-config.dtd">
<configuration>
    <settings>
        <setting name="cacheEnabled" value="true"/>
        <setting name="lazyLoadingEnabled" value="true"/>
        <setting name="multipleResultSetsEnabled" value="true"/>
        <setting name="useColumnLabel" value="true"/>
        <setting name="useGeneratedKeys" value="false"/>
        <setting name="autoMappingBehavior" value="PARTIAL"/>
        <setting name="autoMappingUnknownColumnBehavior" value="WARNING"/>
        <setting name="defaultExecutorType" value="SIMPLE"/>
        <setting name="defaultStatementTimeout" value="25"/>
        <setting name="defaultFetchSize" value="100"/>
        <setting name="safeRowBoundsEnabled" value="false"/>
        <setting name="mapUnderscoreToCamelCase" value="false"/>
        <setting name="localCacheScope" value="SESSION"/>
        <setting name="jdbcTypeForNull" value="OTHER"/>
        <setting name="lazyLoadTriggerMethods" value="equals,clone,hashCode,toString"/>
    </settings>
</configuration>  
```

[官网](https://mybatis.org/mybatis-3/zh/configuration.html#settings)

### 3. mapper.xml

```xml
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.felixwc.mybatis.druid.mysql.mapper.UserDaoMapper">
    <select id="getAllUser" resultType="User">
        select id,name,address from test
    </select>
</mapper>
```

[官网](https://mybatis.org/mybatis-3/zh/)











