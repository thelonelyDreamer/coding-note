## 一、责任链模式

### 1.1  目的

责任链模式可以让处理器按照以下方式处理请求：如果它需要进行处理该请求则处理该请求，否则传递给下一个处理器处理

### 1.2 实现

![设计模式责任链插图](https://gimg2.baidu.com/image_search/src=http%3A%2F%2Fimages0.cnblogs.com%2Fblog2015%2F467583%2F201507%2F311127036422527.jpg&refer=http%3A%2F%2Fimages0.cnblogs.com&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=auto?sec=1656833356&t=92e86d8dff061f2f0d600faab340ffeb)

客户端：实例化一个处理器的chain,然后调用第一个处理器的handleRequest()

处理器：规范处理器的处理方法

具体处理器：提供处理的具体方法，如果处理不了，则交给下一个处理器

### 1.3 适用情况

需要的功能太多，可以用不同的类来负责不同的请求。让代码解耦合，符合单一职责原则

### 1.4 示例

1. javax.servlet.Filter:doFilter 方法把过滤器链作为一个参数，用来传递请求
