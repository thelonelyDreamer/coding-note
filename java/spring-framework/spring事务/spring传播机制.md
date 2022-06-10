## 一、源码

```java
package org.springframework.transaction.annotation;

public enum Propagation {
    REQUIRED(0),
    SUPPORTS(1),
    MANDATORY(2),
    REQUIRES_NEW(3),
    NOT_SUPPORTED(4),
    NEVER(5),
    NESTED(6);

    private final int value;

    private Propagation(int value) {
        this.value = value;
    }

    public int value() {
        return this.value;
    }
}
```

## 二、详解

### 0. REQUIRED(0)

默认的spring事务传播级别，使用该级别的特点是，如果上下文中已经存在事务，那么就加入到事务中执行，如果当前上下文中不存在事务，则新建事务执行。

### 1. SUPPORTS(1)

可以支持事务，如果当前方法在事务环境中运行，则以事务形式运行，否则以非事务运行。

### 2. MANDATORY(2)

必须在一个事务中运行,当前方法只能在已有事务的方法中被调用，如果当前事物不存在，会抛异常。

### 3. REQUIRES_NEW(3)

总是会创建一个新事务（包括物理事务），该传播级别的特点是，每次都会新建一个事务，并且同时将上下文中的事务挂起，执行当前新建事务完成以后，上下文事务恢复再执行。

### 4. NOT_SUPPORTED(4)

不支持事务，当处于存在事务的上下文环境中运行时，当前方法会暂停当前已开启的事务，意味着a.save()的事务被挂起直当前方法以非事务方法运行完毕后，a.save()的事务继续执行。

### 5. NEVER(5)

绝不能在事务环境中运行，如果a.save()里声明了使用事务，而b.save()的事务类型声明为never，那么只能以抛异常告终。

### 6. NESTED(6)

嵌套事务支持。该传播级别特征是，如果上下文中存在事务，则嵌套事务执行，如果不存在事务，则新建事务。

Nested和RequiresNew的区别：

- RequiresNew每次都创建新的独立的物理事务，而Nested只有一个物理事务；Nested嵌套事务回滚或提交不会导致外部事务回滚或提交，但外部事务回滚将导致嵌套事务回滚，而RequiresNew由于都是全新的事务，所以之间是无关联的  
  Nested使用JDBC 3的保存点实现，即如果使用低版本驱动将导致不支持嵌套事务

- 使用嵌套事务，必须确保具体事务管理器实现的nestedTransactionAllowed属性为true，否则不支持嵌套事务，如DataSourceTransactionManager默认支持，而HibernateTransactionManager默认不支持，需要我们来开启。


