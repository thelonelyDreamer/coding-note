# spring-security原理

## 一、spring-security的本质

> 过滤器链

### 1. FilterSecurityInterceptor

> 方法级过滤器，位于过滤链的最低部



### 2. ExceptionTranslationFilter

> 是个异常过滤器，用来处理在认证授权过程中抛出的异常

### 3. UsernamePasswordAuthenticationFilter

> 对Post,校验用户名和密码



## 二、过滤器加载过程

###  1、使用SpringSecurity配置过滤器

​			*DelegatingFilterProxy

## 三、重要的接口

### 1. @UserDetailsSevice

> 1. 创建一个过滤器继承UsernamePasswordAuthenticationFilter，重写三个方法
> 2. 创建一个实现类 实现@UserDetailsSevice 查询数据库中的密码

```java
public class UserUsernamePasswordAuthenticationFilter extends UsernamePasswordAuthenticationFilter {
    @Override
    public Authentication attemptAuthentication(HttpServletRequest request, HttpServletResponse response) throws AuthenticationException {
        return super.attemptAuthentication(request, response);
    }

    @Override
    protected void successfulAuthentication(HttpServletRequest request, HttpServletResponse response, FilterChain chain, Authentication authResult) throws IOException, ServletException {
        super.successfulAuthentication(request, response, chain, authResult);
    }

    @Override
    protected void unsuccessfulAuthentication(HttpServletRequest request, HttpServletResponse response, AuthenticationException failed) throws IOException, ServletException {
        super.unsuccessfulAuthentication(request, response, failed);
    }
}
```

### 2. @PasswordEncoding

> 对密码加密，用于返回密码的加密