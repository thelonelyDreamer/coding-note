### 1. 日志级别以及用处

- error: 错误日志，指程序发生错误或严重影响业务流程的错误，可以搭配监控使用；

- warn: 警告日志，一般级别的错误，不会影响到程序和整体流程；

- info: 信息日志，记录程序流程、步骤信息，用户行为等；

- debug: 调试日志，用于记录开发调试信息，如接口调用、相应信息，运行时间等；

- trace: 跟踪日志，记录较为详细的日志信息，一般只用于记录到日志文件中。

### 2. debug 或者trace 日志的记法

```java
if(log.isDebugEnabled()){
    log.debug("there is no token in the heads.");
}
if(log.isTraceEnabled()){
    log.trace("");
}
```

### 3. 使用占位符打印

```java
log.debug("the {} is {}",key,value);
```

### 4. 打印异常信息

#### 4.1 打印指定长度的异常

```java
int length = e.getStackTrace().length>15?15:e.getStackTrace().length;
StringBuilder stringBuilder = new StringBuilder(e.getMessage());
stringBuilder.append(logPrefix).append(e.getClass());
for (int i = 0; i < length; i++) {
    stringBuilder.append(logPrefix).append(e.getStackTrace()[i]);
}
log.warn(stringBuilder.toString());
```

#### 4.2 不允许打印完日志，又抛出异常

### 5. 使用日志门面的api，不要使用底层实现的api

### 6. 日志答应的过程中不允许出现异常，特别是空指针

```java
log.info("{}",Objects.isnon(user)?"":user.getId)
```

### 7. 不要打印毫无意义的语句

例如

```java
log.info("进入方法")
```
