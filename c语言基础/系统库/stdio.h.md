## 一、定义函数

### 1.1 格式化输入输出函数

| 函数名     | 函数定义格式                                   | 函数功能                                    | 返回值                        |
| ------- | ---------------------------------------- | --------------------------------------- | -------------------------- |
| printf  | int printf(char* format,输出表)             | 安照串format 给出的输出格式，把输出表各表达式的值，输出到标准输出文件。 | 成功返回：输出的字符数<br/>失败：EOF（-1） |
| scanf   | int scanf(char* format,输入项地址列表)          | 从标准输入文件读取数据，格式安照format                  | 成功：输入数据的个数<br/>失败：EOF      |
| sprintf | int sprintf(char* s,chra* format,输出表)    | 功能同printf,输出源为字符串s                      |                            |
| sscanf  | int sscanf(char* s,char* format，输入项地址列表) | 功能同sscanf,输入源为字符串s                      |                            |

### 1.2 字符串输入输出函数

| 函数名     | 函数定义格式                                | 函数功能 | 返回值 |
|:------- | ------------------------------------- | ---- | --- |
| getchar | `int getchar()`                       |      |     |
| putchar | `int putchar(char ch)`                |      |     |
| gets    | `char* gets(char* s)`                 |      |     |
| puts    | `int puts(char* s)`                   |      |     |
| fgetc   | `int fgetc(FILE* fp)`                 |      |     |
| fputc   | `int putc(char ch,FILE* fp)`          |      |     |
| fgets   | `char* fgets(char* s,int n,FILE* fp)` |      |     |
| fputs   | `int* fputs(char* s,FILE* fp)`        |      |     |

### 1.3 文件操作函数

| 函数名    | 函数定义 | 函数功能 | 返回值 |
| ------ | ---- | ---- | --- |
| fopen  |      |      |     |
| fclose |      |      |     |
| feof   |      |      |     |
| fread  |      |      |     |
| fwrite |      |      |     |
| rewind |      |      |     |
| fseek  |      |      |     |
| ftell  |      |      |     |
| remove |      |      |     |
