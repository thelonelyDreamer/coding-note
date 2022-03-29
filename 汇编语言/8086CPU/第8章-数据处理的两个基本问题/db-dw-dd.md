### 1. db-dw-dd 命令格式

#### 1.1 语法示例

```asm
data segment
db 1 ; 数据为01H，在data:0处，占一个字节
dw 1 ; 数据为0001H，在data:1处，占用一个字
dd 1 ; 数据为00000001H，在data:3处，占用两个字
data ends
```

#### 1.2 应用实例

```asm
data segment
  dd 1000001
  dw 100
  dw 0
data ends

codesg segment

start:
		;准备数据段
		mov ax,data
		mov ds,ax
		
		;代码段
		mov ax,data
		mov ds,ax
		mov ax,ds:[0]
		mov dx,ds:[2]
		div word ptr ds:[4]
		mov ds:[6],ax
	
	mov ax,4c00H
	int 21H
	
codesg ends

end start
```

