1. 下载
   
   官网可下

2. 上传 并解压缩
   
   ```
   tar -zvxf 压缩包 -C 安装路径
   ```

3. 新建数据目录和存储目录
   
   ```bash
   mkdir conf/single 
   mkdir -p data/single/db
   mkdir -p log/single
   ```

4. 新建并修改配置文件
   
   ```
   vi conf/single/mongod.conf
   ```

5. 启动
   
   ```
   bin/mongod  -f conf/single/mongod.conf 
   ```

6. 测试
   
   ```
   bin.mongo --host host --port port
   ```
