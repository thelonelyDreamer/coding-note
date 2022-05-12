## 一、 http 请求类型

### 1.1 GET 请求

### 1.2 POST 请求

### 1.3 PUT 请求

### 1.4 DELETE 请求

### 二、http 报文格式

#### 2.1 请求报文

请求报文一般包括：请求行(request line)、请求头部(header)、空行和请求数据(request data)

```http
请求方法 url 协议/r/n
头部字段名:值/r/n
...
头部字段名:值/r/n
/r/n
请求体
```

### 2.2 响应报文

响应一般包括：状态行（status line）、响应头部（headers）、空行（blank line）和响应数据（也叫响应体或响应正文）（response body）4个部分组成。

```http
协议版本 状态码 状态码描述/r/n
头部字段名:值/r/n
...
头部字段名:值/r/n
/r/n
响应数据
```

**状态行**

状态行由3部分组成，分别为：协议版本、状态码、状态码描述。其中协议版本与请求报文一致，状态码描述是对状态码的简单描述。

**响应头部**

| 字段名            | 描述           | 示例  |
|:--------------:| ------------ | --- |
| Server         | HTTP服务器的软件信息 |     |
| Date           | 响应报文的时间      |     |
| Expires        | 指定缓存过期时间     |     |
| Set-Cookie     | 设置Cookie     |     |
| Last-Modified  | 资源最后修改时间     |     |
| Content-Type   | 响应的类型和字符集    |     |
| Content-Length | 内容长度         |     |
| Connection     | keep-Alive   |     |
| Location       | 指明重定向的位置     |     |
