# javadoc

javadoc是Sun公司提供的一个技术，它从程序[源代码](https://baike.baidu.com/item/%E6%BA%90%E4%BB%A3%E7%A0%81/3969)中抽取类、方法、成员等注释形成一个和源代码配套的API帮助文档。也就是说，只要在编写程序时以一套特定的标签作注释，在程序编写完成后，通过Javadoc就可以同时形成程序的开发文档了。

javadoc命令是用来生成自己[API](https://baike.baidu.com/item/API/10154)文档的，使用方式：使用命令行在目标文件所在目录输入javadoc +文件名.java。

## 目录

1. 1 [常用标记](https://baike.baidu.com/item/javadoc/4640765?fr=aladdin#1)
2. 2 [命令格式](https://baike.baidu.com/item/javadoc/4640765?fr=aladdin#2)

## 常用标记

 播报

| 标签               | 说明                                                   | JDK 1.1 doclet | 标准doclet  | 标签类型               |
| ---------------- | ---------------------------------------------------- | -------------- | --------- | ------------------ |
| @author 作者       | 作者标识                                                 | √              | √         | 包、 类、接口            |
| @version 版本号     | 版本号                                                  | √              | √         | 包、 类、接口            |
| @param 参数名 描述    | 方法的入参名及描述信息，如入参有特别要求，可在此注释。                          | √              | √         | 构造函数、 方法           |
| @return 描述       | 对函数返回值的注释                                            | √              | √         | 方法                 |
| @deprecated 过期文本 | 标识随着程序版本的提升，当前API已经过期，仅为了保证兼容性依然存在，以此告之开发者不应再用这个API。 | √              | √         | 包、类、接口、值域、构造函数、 方法 |
| @throws异常类名      | 构造函数或方法所会抛出的异常。                                      | <br>           | √         | 构造函数、 方法           |
| @exception 异常类名  | 同@throws。                                            | √              | √         | 构造函数、 方法           |
| @see 引用          | 查看相关内容，如类、方法、变量等。                                    | √              | √         | 包、类、接口、值域、构造函数、 方法 |
| @since 描述文本      | API在什么程序的什么版本后开发支持。                                  | √              | √         | 包、类、接口、值域、构造函数、 方法 |
| {@link包.类#成员 标签} | 链接到某个特定的成员对应的文档中。                                    | <br>           | √         | 包、类、接口、值域、构造函数、 方法 |
| {@value}         | 当对常量进行注释时，如果想将其值包含在文档中，则通过该标签来引用常量的值。                | <br>           | √(JDK1.4) | 静态值域               |

此外还有@serial、@serialField、@serialData、{@docRoot}、{@inheritDoc}、{@literal}、{@code} {@value arg}几个不常用的标签，由于不常使用，我们不展开叙述，感兴趣的读者可以查看帮助文档。

## 命令格式

 播报

Javadoc命令格式如下：

javadoc [选项] [软件包名称] [[源文件](https://baike.baidu.com/item/%E6%BA%90%E6%96%87%E4%BB%B6)]

其中选项有：

-overview <文件> 读取 HTML 文件的概述文档

-public 仅显示公共类和成员

-protected 显示受保护/公共类和成员（默认）

-package 显示软件包/受保护/公共类和成员

-private 显示所有类和成员

-help 显示命令行选项并退出

-doclet <类> 通过替代 doclet 生成输出

-docletpath <路径> 指定查找 doclet 类文件的位置

-sourcepath <路径列表> 指定查找[源文件](https://baike.baidu.com/item/%E6%BA%90%E6%96%87%E4%BB%B6)的位置

-classpath <路径列表> 指定查找用户类文件的位置

-exclude <软件包列表> 指定要排除的软件包的列表

-subpackages <子软件包列表> 指定要递归装入的子软件包

-breakiterator 使用 BreakIterator 计算第 1 句

-bootclasspath <路径列表> 覆盖引导类加载器所装入的类文件的位置

-source <版本> 提供与指定版本的源兼容性

-extdirs <目录列表> 覆盖安装的扩展目录的位置

-verbose 输出有关 Javadoc 正在执行的操作的消息

-locale <名称> 要使用的语言环境，例如 en_US 或 en_US_WIN

-encoding <名称> 源文件编码名称

-quiet 不显示状态消息

-J<标志> 直接将 <标志> 传递给运行时系统



[javadoc_百度百科](https://baike.baidu.com/item/javadoc/4640765?fr=aladdin)
