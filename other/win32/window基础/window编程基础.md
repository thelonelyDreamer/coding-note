# 一、应用程序分类

## 1.1 控制台程序（console application）

> Dos 程序，本身没有窗口，通过windows Dos 窗口运行		

## 1.2 窗口程序

> 拥有自己的窗口，可以与用户交互

## 1.3 库程序

> 存放代码、数据的程序，执行文件可以从中取出代码执行和获取数据。

> - 静态库程序
>   - 扩展名：lib
>   - 在编译链接程序时，将代码放到执行文件中
> - 动态库程序
>   - 扩展名dll
>   - 在执行文件时从中获取代码
>   - 有入库函数，不能直接形成

# 二、编译工具

## 2.1 编译器

> - cl.exe

## 2.2 链接器

> - link.exe

## 2.3 资源编译器

> - rc.exe

# 三、库文件和头文件

> - Windwos库
>   - kernel32.dll 
>     - 提供核心API，例如进程/线程/内存管理等。
>   - user32.dll
>     - 提供了窗口/消息等API
>   - gdi32.dll 
>     - 绘图相关的API
>   - 路径：
>     - c:\windows\System32
> - 头文件
>   - windef.h
>     - windows数据类型
>   - winbase.h
>     - kernel32的api
>   - wingdi.h
>     - gdi32的API
>   - winuser.h
>     - user32的API
>   - winnt.h
>     - UNICODE 字符集的支持
>   - windows.h
>     - 所有windows头文件的集合
>   - 路径
>     - 

# 四、相关函数

