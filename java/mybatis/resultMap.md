# ResultMap 的写法

## 一、xml

### 1. 一个对象中有另外一个对象,所有属性在同一个表或者关联查询

```
@Data
@NoArgsConstructor
@AllArgsConstructor
@Accessors(chain = true)
public class School {
    private long id;
    private String name;
    private Address address;
}
```

```yml
@Data
@NoArgsConstructor
@AllArgsConstructor
@Accessors(chain = true)
public class Address {
    private String zone;
    private String detail_address;
}
```

```xml
<resultMap id="schoolResultMap" type="School">
    <id column="school_id" property="id"></id>
    <result column="school_name" property="name"></result>
    <result column="created_time" property="createdTime"></result>
    <result column="updated_time" property="updatedTime"></result>
    <result column="deleted_flag" property="deletedFlag"></result>
    <association property="address" javaType="Address">
        <result property="zone" column="school_zone"></result>
        <result property="detail_address" column="column_detail_zone"></result>
    </association>
</resultMap>
<select id="getById" resultMap="schoolResultMap" >
    select school_id,school_name,school_zone,school_detail_address,
    created_time,updated_time,deleted_flag
    from t_school
</select>
```



### 2. 一个对象中有一个集合

```xml
<resultMap id="schoolResultMap" type="School">
    <id column="school_id" property="id"></id>
    <result column="school_name" property="name"></result>
    <result column="created_time" property="createdTime"></result>
    <result column="updated_time" property="updatedTime"></result>
    <result column="deleted_flag" property="deletedFlag"></result>
    <collection property="teachers">
            <id></id>
            <result></result>
            <association></association>
            <collection></collection>
     </collection>
</resultMap>
```

注： collection 和association 有一个子属性select 可以关联子查询，javaType 指明属性

### 3. Map和set的处理

- 转化为json存储,自定义处理器，基础BaseType类Handler

### 4. 注意点

- 每个标签均可配置typehandler
- xml 也可配置全局的typehandler



二、注解

@results

@result

@one

@many

@resultMap

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
            @Result(property = "address",column = "school_id",one = @One(select = "getAddress"))
    })
    @Select("select school_id,school_name,\n" +
            "created_time,updated_time,deleted_flag\n" +
            "from t_school")
    List<School> getByIds();
}
```

```java
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
```

