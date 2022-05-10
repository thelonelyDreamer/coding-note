### 1. 依赖

```
<dependency>
    <groupId>org.mybatis</groupId>
    <artifactId>mybatis</artifactId>
    <version>3.5.7</version>
</dependency>
<dependency>
    <groupId>org.mybatis</groupId>
    <artifactId>mybatis-spring</artifactId>
    <version>2.0.6</version>
</dependency>
<dependency>
    <groupId>org.springframework</groupId>
    <artifactId>spring-jdbc</artifactId>
    <version>5.3.9</version>
</dependency>
```

### 2. 定义实体类 写接口

```xml
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.felixwc.mybatis22.dao.mapper.SchoolMapper">
    <resultMap id="schoolResultMap" type="School">
        <id column="school_id" property="id"></id>
        <result column="school_name" property="name"></result>
        <result column="created_time" property="createdTime"></result>
        <result column="updated_time" property="updatedTime"></result>
        <result column="deleted_flag" property="deletedFlag"></result>
        <association property="address" javaType="Address">
            <result property="zone" column="school_zone"></result>
            <result property="detailAddress" column="column_detail_zone"></result>
        </association>
    </resultMap>
    <select id="getById" resultMap="schoolResultMap" >
        select school_id,school_name,school_zone,school_detail_address,
        created_time,updated_time,deleted_flag
        from t_school
        where school_id= #{id}
    </select>

</mapper>
```

接口

```java
@Mapper
public interface SchoolMapper {

    School getById(@Param("id")Long id);

    @Results(id = "address",value = {
            @Result(property = "detailAddress",column = "school_detail_address"),
            @Result(property = "zone",column = "school_zone")
    })
    @Select("select school_detail_address,school_zone from t_school where school_id=#{id}")
    Address getAddress(@Param("id") Long id);

    @Results(id = "school",value = {
            @Result(property = "id",column = "school_id"),
            @Result(property = "name",column = "school_name"),
            @Result(property = "createdTime",column = "created_time"),
            @Result(property = "updatedTime",column = "updated_time"),
            @Result(property = "deletedFlag",column = "deleted_flag"),
            @Result(property = "address.zone",column = "school_zone"),
            @Result(property = "address.detailAddress",column = "school_detail_address")
    })
    @Select("select school_id,school_name,school_zone,school_detail_address,\n" +
            "created_time,updated_time,deleted_flag\n" +
            "from t_school")
    List<School> getByIds();
}
```

### 3.  全局的配置

```xml

<!DOCTYPE configuration
        PUBLIC "-//mybatis.org//DTD Config 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-config.dtd">
<configuration>

    <typeAliases>
        <package name="com.felixwc.mybatis22.pojo.dbo"/>
    </typeAliases>
    <typeHandlers>
        <typeHandler handler="org.apache.ibatis.type.EnumOrdinalTypeHandler" javaType="com.felixwc.mybatis22.enums.DeletedFlag"></typeHandler>
    </typeHandlers>
</configuration>  
   
```

```xml
<bean id="druidDataSource" class="com.alibaba.druid.pool.DruidDataSource" init-method="init" destroy-method="close">
        <property name="username" value="${jdbc.username}"/>
        <property name="driverClassName" value="${jdbc.driverClass}"/>
        <property name="url" value="${jdbc.url}"/>
        <property name="password" value="${jdbc.password}"/>
        <property name="initialSize" value="${jdbc.init}"/>
        <property name="minIdle" value="${jdbc.minIdle}"/>
        <property name="maxActive" value="${jdbc.maxActive}"/>
    </bean>
    <bean id="sqlSessionFactory" class="org.mybatis.spring.SqlSessionFactoryBean">
        <!-- 指定mybatis全局配置文件的位置 -->
        <property name="configLocation" value="classpath:xml/mybatis-config.xml"></property>
        <property name="dataSource" ref="druidDataSource"></property>
        <!-- 指定mybatis mapper文件的位置 -->
        <property name="mapperLocations" value="classpath:mapper/*.xml"></property>
    </bean>
    <!-- 配置扫描器 -->
    <bean class="org.mybatis.spring.mapper.MapperScannerConfigurer">
        <!-- 扫描素有的dao接口的实现，加入到容器中 -->
        <property name="basePackage" value="com.felixwc.mybatis22.dao.mapper"></property>
    </bean>
```

