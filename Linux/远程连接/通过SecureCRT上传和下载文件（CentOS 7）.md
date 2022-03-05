# 通过SecureCRT上传和下载文件（CentOS 7）

## 一、lrzsz简介

### 1.lrzsz是什么

> lrzsz是一款在linux里可代替ftp上传和下载的程序。

### 2.名称的解释

> - l :暂时不知道
> - rz : Receive ZMODEM
> - sz : Send ZMODEM

### 3.ZMODEM协议

> [https://baike.baidu.com/item/Zmodem%E5%8D%8F%E8%AE%AE/1444157?fr=aladdin](https://baike.baidu.com/item/Zmodem协议/1444157?fr=aladdin)

### 4.相关网址

> github 项目地址: https://github.com/jnavila/lrzsz

## 二、 安装方式

### 1. 通过yum安装

```bash
# 安装 (需要root权限)
yum install -y lrzsz
# 查看版本
rz --version
# rz (lrzsz) 0.12.20 (这应该是最后一个版本了)
```

## 三、使用方式

### 1. rz的使用

> Usage: rz [options] [filename.if.xmodem]
> Receive files with ZMODEM/YMODEM/XMODEM protocol
>     (X) = option applies to XMODEM only
>     (Y) = option applies to YMODEM only
>     (Z) = option applies to ZMODEM only
>   -+, --append                append to existing files
>   -a, --ascii                 ASCII transfer (change CR/LF to LF)
>   -b, --binary                binary transfer
>   -B, --bufsize N             buffer N bytes (N==auto: buffer whole file)
>   -c, --with-crc              Use 16 bit CRC (X)
>   -C, --allow-remote-commands allow execution of remote commands (Z)
>   -D, --null                  write all received data to /dev/null
>       --delay-startup N       sleep N seconds before doing anything
>   -e, --escape                Escape control characters (Z)
>   -E, --rename                rename any files already existing
>       --errors N              generate CRC error every N bytes (debugging)
>   -h, --help                  Help, print this usage message
>   -m, --min-bps N             stop transmission if BPS below N
>   -M, --min-bps-time N          for at least N seconds (default: 120)
>   -O, --disable-timeouts      disable timeout code, wait forever for data
>       --o-sync                open output file(s) in synchronous write mode
>   -p, --protect               protect existing files
>   -q, --quiet                 quiet, no progress reports
>   -r, --resume                try to resume interrupted file transfer (Z)
>   -R, --restricted            restricted, more secure mode
>   -s, --stop-at {HH:MM|+N}    stop transmission at HH:MM or in N seconds
>   -S, --timesync              request remote time (twice: set local time)
>       --syslog[=off]          turn syslog on or off, if possible
>   -t, --timeout N             set timeout to N tenths of a second
>   -u, --keep-uppercase        keep upper case filenames
>   -U, --unrestrict            disable restricted mode (if allowed to)
>   -v, --verbose               be verbose, provide debugging information
>   -w, --windowsize N          Window is N bytes (Z)
>   -X  --xmodem                use XMODEM protocol
>   -y, --overwrite             Yes, clobber existing file if any
>       --ymodem                use YMODEM protocol
>   -Z, --zmodem                use ZMODEM protocol
>
> short options use the same arguments as the long ones

> 命令格式：
>
> rz [选项]
>
> 选项说明：
>
> -+, --append:将文件内容追加到已存在的同名文件
>
> -a,--ascii:以文本方式传输
>
> -b, --binary:以二进制方式传输，推荐使用
>
> --delay-startup N:等待N秒
>
> -e, --escape:对所有控制字符转义，建议使用
>
> -E, --rename:已存在同名文件则重命名新上传的文件，以点和数字作为后缀
>
> -p, --protect:对ZMODEM协议有效，如果目标文件已存在则跳过 -
>
> -q, --quiet:安静执行，不输出提示信息
>
> -v, --verbose:输出传输过程中的提示信息
>
> -y, --overwrite:存在同名文件则替换
>
> -X, --xmodem:使用XMODEM协议
>
> --ymodem:使用YMODEM协议
>
> -Z, --zmodem:使用ZMODEM协议
>
> --version：显示版本信息
>
> --h, --help：显示帮助信息

### 2. sz 的使用

> sz version 0.12.20
> Usage: sz [options] file ...
>    or: sz [options] -{c|i} COMMAND
> Send file(s) with ZMODEM/YMODEM/XMODEM protocol
>     (X) = option applies to XMODEM only
>     (Y) = option applies to YMODEM only
>     (Z) = option applies to ZMODEM only
>   -+, --append                append to existing destination file (Z)
>   -2, --twostop               use 2 stop bits
>   -4, --try-4k                go up to 4K blocksize
>       --start-4k              start with 4K blocksize (doesn't try 8)
>   -8, --try-8k                go up to 8K blocksize
>       --start-8k              start with 8K blocksize
>   -a, --ascii                 ASCII transfer (change CR/LF to LF)
>   -b, --binary                binary transfer
>   -B, --bufsize N             buffer N bytes (N==auto: buffer whole file)
>   -c, --command COMMAND       execute remote command COMMAND (Z)
>   -C, --command-tries N       try N times to execute a command (Z)
>   -d, --dot-to-slash          change '.' to '/' in pathnames (Y/Z)
>       --delay-startup N       sleep N seconds before doing anything
>   -e, --escape                escape all control characters (Z)
>   -E, --rename                force receiver to rename files it already has
>   -f, --full-path             send full pathname (Y/Z)
>   -i, --immediate-command CMD send remote CMD, return immediately (Z)
>   -h, --help                  print this usage message
>   -k, --1k                    send 1024 byte packets (X)
>   -L, --packetlen N           limit subpacket length to N bytes (Z)
>   -l, --framelen N            limit frame length to N bytes (l>=L) (Z)
>   -m, --min-bps N             stop transmission if BPS below N
>   -M, --min-bps-time N          for at least N seconds (default: 120)
>   -n, --newer                 send file if source newer (Z)
>   -N, --newer-or-longer       send file if source newer or longer (Z)
>   -o, --16-bit-crc            use 16 bit CRC instead of 32 bit CRC (Z)
>   -O, --disable-timeouts      disable timeout code, wait forever
>   -p, --protect               protect existing destination file (Z)
>   -r, --resume                resume interrupted file transfer (Z)
>   -R, --restricted            restricted, more secure mode
>   -q, --quiet                 quiet (no progress reports)
>   -s, --stop-at {HH:MM|+N}    stop transmission at HH:MM or in N seconds
>       --tcp                   build a TCP connection to transmit files
>       --tcp-server            open socket, wait for connection
>   -u, --unlink                unlink file after transmission
>   -U, --unrestrict            turn off restricted mode (if allowed to)
>   -v, --verbose               be verbose, provide debugging information
>   -w, --windowsize N          Window is N bytes (Z)
>   -X, --xmodem                use XMODEM protocol
>   -y, --overwrite             overwrite existing files
>   -Y, --overwrite-or-skip     overwrite existing files, else skip
>       --ymodem                use YMODEM protocol
>   -Z, --zmodem                use ZMODEM protocol
>
> short options use the same arguments as the long ones

## 四、参考资料

1. [流光瞬息](https://www.cnblogs.com/leeyongbard/).[Linux命令之rz命令与sz命令](https://www.cnblogs.com/leeyongbard/p/9356760.html) :https://www.cnblogs.com/leeyongbard/p/9356760.html

## 五、 后记

暂时到这-2020-11-27











