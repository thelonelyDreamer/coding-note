## 一、Session

### 1. 常见操作

#### 1.0 获取Sesssion对象

```java
// 方式一
@RequestMapping("get")
public void get(HttpSession session) {
}
// 方式二
@RequestMapping("get")
public void get(HttpServletRequest request) {
    HttpSession session = request.getSession();
}
// 方式三
@Autowired
private HttpServletRequest request;
@GetMapping("/test")
private String test(){
    ServletContext servlet = request.getServletContext();
    return null;
}
// 方式四

```

#### 1.1 取值取值

**servlet 方法**

```java

```

**springmvc方法**

```

```

## 二、Request

```java
@RequestMapping("get")
public void get(HttpSession session) {
}
```

## 三、Application