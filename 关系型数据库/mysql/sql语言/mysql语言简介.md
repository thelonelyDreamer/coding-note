## 一 SQL (**结构化查询语言**)

### 1.1 概述

​        结构化查询语言(Structured Query Language)简称SQL，结构化查询语言是一种数据库查询和程序设计语言，用于存放数据以及查询、更新和管理关系数据库系统；同时也是数据库脚本文件的扩展名。结构化查询语言是高级的非过程化编程语言，允许用户在高层数据结构上工作。它不要求用户指定对数据的存放方法，也不需要用户了解具体的数据存放方式，所以具有完全不同底层结构的不同数据库系统，可以使用相同的结构化查询语言作为数据输入与管理的接口。结构化查询语言语句可以嵌套，这使它具有极大的灵活性和强大的功能。



## 二 SQL 分类

### 2.1 数据查询语言（DQL）

数据查询语言（Data Query Language, DQL）是SQL语言中，负责进行数据查询而不会对数据本身进行修改的语句，这是最基本的SQL语句。保留字SELECT是DQL（也是所有SQL）用得最多的动词，其他DQL常用的保留字有FROM，WHERE，GROUP BY，HAVING和ORDER BY。这些DQL保留字常与其他类型的SQL语句一起使用。

### 2.2 数据定义语言（DDL）

数据定义语言 (Data Definition Language, DDL) 是SQL语言集中，负责数据结构定义与数据库对象定义的语言，由CREATE、ALTER与DROP三个语法所组成，最早是由 Codasyl (Conference on Data Systems Languages) 数据模型开始，现在被纳入 SQL 指令中作为其中一个子集。

### 2.3 数据操纵语言（DML）

数据操纵语言（Data Manipulation Language, DML）是SQL语言中，负责对数据库对象运行数据访问工作的指令集，以INSERT、UPDATE、DELETE三种指令为核心，分别代表插入、更新与删除。

### 2.4 数据控制语言（DCL）

数据控制语言 (Data Control Language) 在SQL语言中，是一种可对数据访问权进行控制的指令，它可以控制特定用户账户对数据表、查看表、预存程序、用户自定义函数等数据库对象的控制权。由 GRANT 和 REVOKE 两个指令组成。DCL以控制用户的访问权限为主，GRANT为授权语句，对应的REVOKE是撤销授权语句。

### 2.5 指针控制语言（CCL）

它的语句，像DECLARE CURSOR，FETCH INTO和UPDATE WHERE CURRENT用于对一个或多个表单独行的操作。

### 2.6 事务处理语言（TPL）

它的语句能确保被DML语句影响的表的所有行及时得以更新。TPL语句包括BEGIN TRANSACTION，COMMIT和ROLLBACK。
