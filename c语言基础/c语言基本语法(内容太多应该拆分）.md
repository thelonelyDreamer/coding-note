# 一、基本概念

## 1. 关键字

> asm 			auto 			break 			case 			const 	
>
> continue	do 				double 	 	  else 			enum 	
>
> extern 		for				goto 				if				 mutable 			
>
> register		return 		signed 			sizeof 		static 					
>
> struct 		  switch 		typedef   	 	union 		unsigned 
>
> signed 		while 			volatile 			_Bool 		_Complex 
>
> _Imaginary restrict 		inline 				_Alignas 	_Alignof 
>
> _Atomic		_Static_assert  					_Noreturn  
>
> _Thread_local	_Generic

## 2. 标识符

> - 字母、数字和下划线
> - 第一个字符必须是字母或者下划线
> - 区分大小写

## 3. 常量

### 3.1 整型常量

> - 按进制
>   - 16进制
>     - 0x1AF
>     - 0XFA
>   - 8进制
>     - 071
>   - 10进制
>     - 1129
>   - 2进制(暂无)
> - 按数据类型
>   - 234LL
>   - 234L
>   - 234
>   - 234ull
>   - 234ul
>   - 234u
> - 两者可以结合

### 3.2 字符常量

> - 示例
>   - 'a'
>   - '1'
>   - 65(不建议这么表示)
>   - 'abcd ' 表示'd'
>   - \n(有各种转义字符)
>   - \017或者\xF或者\XF

## 4. 变量

> - 声明变量
>   - 格式： 数据类型 变量名[,变量名];
>   - 示例：int a; int a,b;
> - 初始化变量
>   - 方法一：赋值
>     - int dog =11;
>     - int dog=11,cat=12;
>     - 注意不要把未赋值的变量和已经赋值的变量反正同一个语句里面
>   - 方法二：操作变量地址
>     - int a; sancf("%d\n",&a);
> - 

## 5. 基本数据类型 

### 5.1 整型

> - 有符号整数类型(在任何有符号类型前面添加关键字signed,可强调使用有符号类型的意图)
>   - long long int 或者long long (C99)
>     - 后缀：ll或者LL
>   - long int 或者long 
>     - 后缀：l或者L
>   - int 
>   - short int 或者short
> - 无符号整数类型
>   - unsigned long long int 或者unsigned long long (C99)
>     - 后缀：ull或者ULL或者llu或者LLU
>   - unsigned long int 或者unsigned long (C90)
>     - 后缀：ul或者UL或者lu或者LU
>   - unsigned int 
>   - unsigned short int 或者unsigned short(C90)

### 5.2 字符类型

> - char
>   - char a;

### 5.3 

# 二、输入输出

## 1. 控制台输入输出

### 1.1 scanf()和printf()

> - 整数
>   - printf("%d,%o,%x",xxx);分别表示十进制、八进制和十六进制
>   - printf("%d,%#o,%#x",xxx);分别表示十进制、带前缀的八进制和十六进制
>   - scanf("%d %o %x",&a,&b,&c);分别接收不带前缀的数
>   - scanf("%d 0%o 0x%x",&a,&b,&c);分别接收带前缀的数
>   - printf("%lld,%ld,%d,%hd"),打印有符号数
>   - printf("%llu,%lu,%u,%hu"),打印无符号数
>   - printf("%ho,%hd,%hx",a,b,c)，打印short
>   - printf("%lo,%ld,%lx",a,b,c)，打印long
> - 字符
>   - prinf("%c",ch);
> - 浮点型
>   - printf("%lf",ld);

## 2. 文件输入输出

## 3. 数据库输入输出

# 4. 网络输入输出



# 三、流程控制

## 1. 顺序结构

## 2. 分支结构

## 3. 循环结构

# 四、函数

# 五、指针

# 六、结构体

