## 一、收参

### 1. 普通参数

```html
# 测试URL
http://localhost:8080/hello2/test1?id=1&name=richter&gender=true&bitrh=2022/04/12
```

```java
    @RequestMapping("test1")
    public String test1(Integer id, String name, Boolean gender, Date bitrh) {
        System.out.println(id+name+gender+bitrh);
        return "hello.html";
    }
```

- 基本类型要用包装器类型。如果没有接收到参数会赋予null.如果采用基本类型，要是没有参数，会报错
- 常见的类型会自动转换，日期类型要bitrh=2022/04/12%2012:12:12
- 可以定义解析器

### 2. 对象收参

```html
http://localhost:8080/hello2/test1?id=1&name=richter&gender=true&bitrh=2022/04/12
```

> 要有set get 方法 无参构造
>
> 可以实现serializable 也可以不实现
>
> 不能实现容器或者框架的接口

```java
public class User {
    private Integer id;
    private String name;
    private Boolean gender;
    private Date birth;
}
```

```java
@RequestMapping("test2")
public String test2(User user) {
    System.out.println(user);
    return null;
}
```
- 前后端参数名字一样

```
@RequestMapping("test2")
public String test2(User user,String name) {
    System.out.println(user);
    return null;
}
```

- name和user.name 会收到参数

### 3. 数组参数

   <form action="${pageContext.request.contextPath}/hello2/test3">
        <input type="checkbox" name="hobby" value="eat"/>吃吃吃
        <input type="checkbox" name="hobby" value="play"/>玩玩玩
        <input type="checkbox" name="hobby" value="sleep"/>睡睡睡
        <br/>
        <input type="submit" value="提交"/>
    </form>
```http
/hello2/test3？hobby=1&hobby=2
```

    @RequestMapping("test3")
    public String test3(String[] hobby) {
        for (String s : hobby) {
            System.out.println(s);
        }
        return null;
    }
### 4. 集合收参

```html
 <form action="${pageContext.request.contextPath}/hello2/test4" method="post">
        ID：<input type="text" name="user[0].id"/><br/>
        Name：<input type="text" name="user[0].name"/><br/>
        Gender：<input type="text" name="user[0].gender"/><br/>
        <br/>
        ID：<input type="text" name="user[1].id"/><br/>
        Name：<input type="text" name="user[1].name"/><br/>
        Gender：<input type="text" name="user[1].gender"/><br/>
        <br/>
        <input type="submit" value="提交"/>
    </form>
```

实体：

```
public class UserList {
    private User[] user;
}
```

    @RequestMapping("test4")
    public String test4(UserList userList) {
        for (User user : userList.getUser()) {
            System.out.println(user);
        }
        return null;
    }
### 5. 路径收参

```java
    @RequestMapping("/test5/{id}")
    public String test5(@PathVariable("id") Integer id) {
        System.out.println(id);
        return null;
    }
```

---

## 二、相关注解

### 1. @RequestParam

**请求参数和形参类型不一致**

```java
	@RequestMapping("test1")
    public String test1( @RequestParam("n")String name) {
        return "hello.html";
    }
	// id<=10
	@RequestMapping("test2")
    public String test1( @RequestParam("id<")String id) {
        return "hello.html";
    }
```

```java
@RequstParam String name; // 默认为 name;
```

使用@RequestParam 修饰的注解必须传递参数 否则反射

不能这样用，会报400

```
@RequestParam User user
```

**相关属性**

```
required = true ||false 参数是否需要
defaultValue = "123" 默认参数 required 改为false 
```

```
@RequestParam(defaultValue = "123")int value;
@RequestParam(defaultValue = "1",value="pageNum") Integer pageNum
```



---

## 乱码解决

```bash
#html
<meta charset="UTF-8">
#jsp
<%@page pageEncoding="utf-8 %>
# tomcat
URIEncoding=utf-8
#web.xml
<filter>
    <filter-name>encoding</filter-name>
    <filter-class>org.springframework.web.filter.CharacterEncodingFilter</filter-class>
    <init-param>
        <param-name>encoding</param-name>
        <param-value>utf-8</param-value>
    </init-param>
</filter>
<filter-mapping>
    <filter-name>encoding</filter-name>
    <url-pattern>/*</url-pattern>
</filter-mapping>
```

