## 一、简介

通过OpenJDK官方提供的JOL(Java Object Layout)工具，我们即可很方便分析、了解一个Java对象在内存当中的具体布局情况

![preview](jol-core%E4%BD%BF%E7%94%A8.assets/v2-961b928cf04da5ce629ee08fd767191e_r-16488350608132.jpg)



## 二、使用方法

**Note**：

在64位的HotSpot虚拟机下，类型指针、引用类型需要占8个字节。显然这大大增加了内存的消耗和占用。为此从JDK 1.6开始，64位的JVM支持UseCompressedOops选项。其可对OOP(Ordinary Object Pointer，普通对象指针)进行压缩，使其只占用4个字节，以达到节约内存的目的。在JDK 8下，该选项默认启用。当然也可以通过添加JVM参数来显式进行配置

```java
-XX:+UseCompressedOops  // 开启指针压缩
-XX:-UseCompressedOops  // 关闭指针压缩
```

### 2.1 引入Jar

```xml
<!-- https://mvnrepository.com/artifact/org.openjdk.jol/jol-core -->
<dependency>
    <groupId>org.openjdk.jol</groupId>
    <artifactId>jol-core</artifactId>
    <version>0.16</version>
    <scope>provided</scope>
</dependency>
```

### 2.2 编码

#### 2.2.1 分析普通对象

```Java
Object o = new Object;
System.out.println(ClassLayout.parseInstance(o).toPrintable());
```

```txt
java.lang.Object object internals:
OFF  SZ   TYPE DESCRIPTION               VALUE
  0   8        (object header: mark)     0x0000000000000001 (non-biasable; age: 0)
  8   8        (object header: class)    0x0000000019791c00
Instance size: 16 bytes
Space losses: 0 bytes internal + 0 bytes external = 0 bytes total
```

#### 2.2.2 分析数组对象

```java
int[] o = {1,3,2,4,5};
System.out.println(ClassLayout.parseInstance(o).toPrintable());
```

```
[I object internals:
OFF  SZ   TYPE DESCRIPTION               VALUE
  0   8        (object header: mark)     0x0000000000000001 (non-biasable; age: 0)
  8   8        (object header: class)    0x0000000019360b68
 16   4        (array length)            5
 16   8        (alignment/padding gap)   
 24  20    int [I.<elements>             N/A
 44   4        (object alignment gap)    
Instance size: 48 bytes
Space losses: 8 bytes internal + 4 bytes external = 12 bytes total

```

