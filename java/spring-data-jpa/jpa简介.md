### q1: 这么是jpa

> Java Persistence API

### q2: jpa 和jdbc 的关系

1. **相同处**

    > 1. 都是操作数据库的一组接口规范，jpa 是jdbc的升级版

2. **不同处**

    > 1. jdbc是由各个关系型数据库实现的 ，jpa 是由orm框架实现的
    > 2. jdbc是由SQL语句和数据库通信的，jpa 采用面向对象的方式，由orm框架来生成sql，进行操作
    > 3.  jpa 是在jdbc 上的，jpa依赖jdbc 才能操作数据库

###  q3: Hibernate、JPA、MyBatis 关系

> 1. JPA 是一种规范 Hibernate是JPA 的一种实现
> 2. mybatis: 半自动，小巧、高效，简单，直接
> 3. hibernate: 强大，方便，高效，全自动，绕弯子

