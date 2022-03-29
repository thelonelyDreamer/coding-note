### 1. Java 中的异常体系

Java 中的所有异常都来自顶级父类Throwable

Throwable 有两个子类Exception和Error

Exception 分为RunTimeException 和CheckedException

RunTimeException 只会导致当前线程失败

CheckedExceptin 是编译过程中的异常



### 2. GC 如何判断对象可以被回收的

引用计数法：

可达性分析法：从GC root  开始向下开始搜索，当一个对象跟GC root没有联系，可被回收



GC root 

- 虚拟机栈中引用的对象
- 方法区静态属性引用的对象
- 方法区常量引用的对象
- 本地方法栈中引用的对象



### 3. 说一下 哪些是共享区，那些是GC root

方法区和堆，虚拟机栈和本地方法栈和程序计数器不可以共享

方法区静态属性引用的对象，本地方法栈，正在运行的线程



### 4. 线程的生命周期

新建，就绪，终止，运行，有限等待，无限等待

wait() 会放弃所有资源

lock()进入当前

### 5. sleep(),wait(),join(),yield()区别

yield ()只是放弃CPU 的执行资格

 

### 6. 说说对线程安全的理解





### 7.  Thread 和 Runnable 的区别





