# 一、makefile简介

> makefile定义了一系列的规则来指定，哪些文件需要先编译，哪些文件需要后编译，哪些文件需要重新编译，甚至于进行更复杂的功能操作，因为 makefile就像一个Shell脚本一样，其中也可以执行操作系统的命令。
>
> ​	Make工具最主要也是最基本的功能就是通过makefile文件来描述源程序之间的相互关系并自动维护编译工作。而makefile 文件需要按照某种语法进行编写，文件中需要说明如何编译各个源文件并连接生成可执行文件，并要求定义源文件之间的依赖关系。makefile 文件是许多编译器--包括 Windows NT 下的编译器--维护编译信息的常用方法，只是在集成开发环境中，用户通过友好的界面修改 makefile 文件而已。
>
> ​	在 [UNIX ](http://www.yiibai.com/unix/)系统中，习惯使用 Makefile 作为 makefile 文件。如果要使用其他文件作为 makefile，则可利用类似下面的 make 命令选项指定 makefile 文件。
>
> ​		一个文件，指示程序如何编译和链接程序。makefile文件的默认名称是名副其实的Makefile，但可以指定一个命令行选项的名称。

# 二、makefile 语法

## 1. 显示规则

### 1.1 单文件

```c
# hello.c
#include<stdio.h>
int main(void){
    return 0;
}
```



```makefile
# 注释
# 目标文件：依赖文件
# [TAB] 指令
# 第一个目标文件是最终目标，最后一个是第一个目标
hello:hello.c
	gcc -o hello
```

**示例**

```makefile
hello:hello.o
	gcc hello.o -o hello
hello.o:hello.s
	gcc -c hello.s -o hello.o
hello.s:hello.i
	gcc -S hello.i -o hello.s
hello.i:hello.c
	gcc -E hello.c -o hello.i
	
.PHONY
clear:
	rm -rf hello.o hello.s hello.i hello
```

```makefile
#.PHONY 伪目标
.PHONY
clear:
	rm -rf hello.o hello.s hello.i hello
```

```bash
make clear
```

### 1.2 多文件

```makefile
# circle.c circle.h cube.c cube.h main.c
test:circle.o cube.o main.o
	gcc circle.o cube.o main.o -o test
circle.o:circle.c
	gcc -c circle.c -o circle.o
cube.o:cube.c
	gcc -c cube.c -o cube.o
main.o:main.c
	gcc -c main.c -o main.o
.PHONY
clearall:
	rm -fr main.o circle.o cube.o test
clear:
	rm -fr main.o circle.o cube.o
```

## 2. 变量

```makefile
# 变量 =（替换） +=（追加） :=(恒等于)常量
TAR = test
CC := gcc
# 取变量
${TAR}
${CC}
```

## 3. 隐含规则

```makefile
# %.c %.o 表示任意的一个文件
%.c:%o
	gcc -c %.c -o %.o
# .c *.o 表示所有的文件
clear:
	rm -fr *.o
```

## 4. 常见的自动变量

```bash
# 不包含扩展名的目标文件名称
$*       		
# 所有的依赖文件,以空格分开,并以出现的先后为序,可能包含 重复的依赖文件
$+       			
# 第一个依赖文件的名称
$<     		   
#所有时间戳比目标文件晚的依赖文件,并以空格分开
$? 	       
# 目标文件的完整名称 
$@ 
# 所有不重复的依赖文件,以空格分开 
$^         		    
# 如果目标是归档成员,则该变量表示目标的归档成员名称
$%
```

```makefile
OBJS = kang.o yul.o
    CC = Gcc
    CFLAGS = -Wall -O -g
    sunq : $(OBJS)
          $(CC) $^ -o $@
    kang.o : kang.c kang.h
          $(CC) $(CFLAGS) -c $< -o $@
    yul.o : yul.c yul.h
          $(CC) $(CFLAGS) -c $< -o $@
```

## 5. 其他

```makefile
# .DEFAULT
all:gao
    @echo "final"
.DEFAULT:
@echo "In default"
# 由于 gao 是一个前提条件，但是 makefile中没有一个名字为 gao的目的。
# 所以符合 .DEFAULT 目的的执行条件。
# 故执行结果为:
# In default
# final
```

``` makefile
# echo 和 @echo的区别
echo: 会在shell中显示echo这条命令和后面要输出的内容
 
@echo:  不会显示echo这条命令，只会显示后面要输出的内容
 
#例如：
 
echo “hello”  输出为：echo "hello"  hello
 
@echo "hello" 输出为：hello
 
# make在执行命令之前会把要执行的命令进行输出，称之为回显
 
# 如果要执行的命令以字符@开始，则不会回显
```

