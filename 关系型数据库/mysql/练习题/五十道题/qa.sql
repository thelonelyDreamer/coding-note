-- 1. 时间日期相关

-- 1.1 查询本月过生日的同学

-- 1.2 查询下个月过生日的同学

-- 1.3 查出每个学生的年纪


-- 2. 聚合函数
-- 查询姓李的老师的数量
SELECT COUNT(1) FROM teacher WHERE t_name LIKE '李%' ;


-- 3. 自连接查询
-- 查询既有课程1 又有课程2成绩的同学
SELECT t1.s_id as id from score as t1,score as t2
WHERE t1.c_id = 2 and t2.c_id=3 and t1.s_id = t2.s_id

-- 查询只选课程1，没选课程2成绩的同学


-- 4. 子查询


-- 5. 模糊查


-- 6. 集合并运算

