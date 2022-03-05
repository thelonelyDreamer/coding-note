一、通过docker-compose 安装

```yml
version: '3.3'
services:
 mysql:
  # 启动容器名称mysql
  container_name: mysql
  # 使用mysql 8.0.19的镜像
  image: mysql:8.0.19
  # 自启动
  restart: always
  command:
   # mysql默认使用utf8mb4编码
   - --character-set-server=utf8mb4
   - --collation-server=utf8mb4_general_ci
   # mysql时间加8个小时
   - --default-time_zone=+8:00
  environment:
   # 服务器时区使用上海 
   TZ: Asis/Shanghai
   # mysql初始化密码
   MYSQL_ROOT_PASSWORD: xxxxxx
  ports:
   # 容器3306端口映射到宿主机3306端口
   - "3306:3306"
  volumes:
   # mysql相关数据存储在宿主机/data/docker/mysql文件夹
   - ./data/mysql:/var/lib/mysql
 
```

```yml
version: '3.3'
services:
 mysql:
  container_name: mysql
  image: mysql:8.0.19
  restart: always
  command:
   - --character-set-server=utf8mb4
   - --collation-server=utf8mb4_general_ci
   - --default-time_zone=+8:00
  environment:
   TZ: Asis/Shanghai
   MYSQL_ROOT_PASSWORD: wangchao
  ports:
   - "3306:3306"
  volumes:
   - ./data/mysql:/var/lib/mysql

```

