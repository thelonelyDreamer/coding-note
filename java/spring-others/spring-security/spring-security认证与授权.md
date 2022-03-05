# spring-security认证与授权

## 一、认证

### 1. 用配置文件

```yaml
spring:
  security:
    user:
      name: user
      password: 123456
      roles: vip1,vip2
```

### 2.使用配置类

```java
@Configuration
public class SecurityConfig extends WebSecurityConfigurerAdapter {
    @Override
    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
        BCryptPasswordEncoder bCryptPasswordEncoder = new BCryptPasswordEncoder();
        String wangchao = bCryptPasswordEncoder.encode("wangchao");
        auth.inMemoryAuthentication().withUser("wangchao").password(wangchao).roles("admin");
    }
}
@Bean
public PasswordEncoder passwordEncoder(){
    return  new BCryptPasswordEncoder();
}
```

### 3. 自定义配置类（实际操作)

```java
@Configuration
public class SecurityConfig extends WebSecurityConfigurerAdapter {
    @Autowired
    private UserDetailsService userDetailsService;
    @Override
    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
        auth.userDetailsService(userDetailsService).passwordEncoder(passwordEncoder())
    }
    @Bean
    public PasswordEncoder passwordEncoder(){
        return  new BCryptPasswordEncoder();
    }
}
```

```java

```

## 二、授权

