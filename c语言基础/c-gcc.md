# 一、C语言的编译过程

## 1. 单文件编译

```c
// hello.c
#include<stdio.h>
#define STR "Hello World!"
#define PRINTF printf
int main(void)
{
    PRINTF(STR);
    getchar();
    return 0;
}
```

### 1.1 预处理

> - 目的
>   - 宏替换
>   - 处理注释
>   - 文件包含
>   - 条件编译
>   - ···

```bash
 gcc -E hello.c -o hello.i
 ls
 hello.c  hello.i
```

**hello.i 文件的尾部**

```c
# 5 "hello.c"
int main(void)
{
    printf("Hello World!");
    getchar();
    return 0;
}
```

### 1.2 编译

> - 目的
>   - 对预处理文件进行语法分析、词法分析、语义分析
>     - 语法分析：分析表达式是否遵循语法规则
>     - 词法分析：分析关键字，标识符，立即数是否合法
>     - 词义分析：在语法分析基础上进一步分析表达式是否合法
>   - 分析结束后进行代码优化生成相应的汇编代码文件

```bash
gcc -S hello.i -o hello.s
```

**hello.s**

```asm
.file   "hello.c"
        .text
        .section        .rodata
.LC0:
        .string "Hello World!"
        .text
        .globl  main
        .type   main, @function
main:
.LFB0:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        movl    $.LC0, %edi
        movl    $0, %eax
        call    printf
        call    getchar
        movl    $0, %eax
        popq    %rbp
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE0:
        .size   main, .-main
        .ident  "GCC: (GNU) 9.3.1 20200408 (Red Hat 9.3.1-2)"
        .section        .note.GNU-stack,"",@progbits
```

### 1.3 汇编

> -  目的
>   - 汇编器将汇编代码转变为机器可以执行的指令，也就是机器指令
>   - 每条汇编指令几乎都对应一条机器指令

```bash
gcc -c hello.s -o hello.o
```

**hello.o文件已经不是普通人能读懂了**

### 1.4 连接

> - 链接是指将目标文件最终生成可执行文件
> - 根据链接方式的不同，链接过程可以分为：
>   - 静态链接：目标文件直接进入可执行文件
>     - 由链接器在链接时将库的内容直接加入到可执行程序中
>   - 动态链接：在程序启动后才动态加载目标文件
>     - 可执行程序在运行时才动态加载库进行连接
>     - 库的内容不会进入可执行程序   
>
> -    链接器的主要作用是把各个模块之间相互引用部分处理好，使得各个模块之间能够正确的链接

```bash
gcc hello.o -o hello
```

**hello 是一个可执行文件**