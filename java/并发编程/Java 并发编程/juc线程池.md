# 一、基本框架（java8)

## 接口

![image-20210820182846239](juc%E7%BA%BF%E7%A8%8B%E6%B1%A0.assets/image-20210820182846239.png)

> 三接口三实现

### 1.1 Executor接口

| Modifier and Type | Method and Description                                       |
| ----------------- | ------------------------------------------------------------ |
| `void`            | `execute(Runnable command)`  在将来的某个时间执行给定的命令。 |

### 1.2 ExecutorService接口

| 方法                  | 解释                                                         |
| --------------------- | ------------------------------------------------------------ |
| `boolean`             | `awaitTermination(long timeout,  TimeUnit unit)`  阻止所有任务在关闭请求完成后执行，或发生超时，或当前线程中断，以先到者为准。 |
| `<T> List<Future<T>>` | `invokeAll(Collection<? extends Callable<T>> tasks)`  执行给定的任务，返回持有他们的状态和结果的所有完成的期货列表。 |
| `<T> List<Future<T>>` | `invokeAll(Collection<? extends Callable<T>> tasks,  long timeout, TimeUnit unit)`  执行给定的任务，返回在所有完成或超时到期时持有其状态和结果的期货列表，以先发生者为准。 |
| `<T> T`               | `invokeAny(Collection<? extends Callable<T>> tasks)`  执行给定的任务，返回一个成功完成的结果（即没有抛出异常），如果有的话。 |
| `<T> T`               | `invokeAny(Collection<? extends Callable<T>> tasks,  long timeout, TimeUnit unit)`  执行给定的任务，返回一个已经成功完成的结果（即，不抛出异常），如果有的话在给定的超时之前过去。 |
| `boolean`             | `isShutdown()`  如果此执行者已关闭，则返回 `true` 。         |
| `boolean`             | `isTerminated()`  如果所有任务在关闭后完成，则返回 `true` 。 |
| `void`                | `shutdown()`  启动有序关闭，其中先前提交的任务将被执行，但不会接受任何新任务。 |
| `List<Runnable>`      | `shutdownNow()`  尝试停止所有主动执行的任务，停止等待任务的处理，并返回正在等待执行的任务列表。 |
| `<T> Future<T>`       | `submit(Callable<T> task)`  提交值返回任务以执行，并返回代表任务待处理结果的Future。 |
| `Future<?>`           | `submit(Runnable task)`  提交一个可运行的任务执行，并返回一个表示该任务的未来。 |
| `<T> Future<T>`       | `submit(Runnable task, T result)`  提交一个可运行的任务执行，并返回一个表示该任务的未来。 |

### 1.3 ScheduledExecutorService

| Modifier and Type        | Method and Description                                       |
| ------------------------ | ------------------------------------------------------------ |
| `<V> ScheduledFuture<V>` | `schedule(Callable<V> callable,  long delay, TimeUnit unit)`  创建并执行在给定延迟后启用的ScheduledFuture。 |
| `ScheduledFuture<?>`     | `schedule(Runnable command, long delay, TimeUnit unit)`  创建并执行在给定延迟后启用的单次操作。 |
| `ScheduledFuture<?>`     | `scheduleAtFixedRate(Runnable command, long initialDelay,  long period, TimeUnit unit)`  创建并执行在给定的初始延迟之后，随后以给定的时间段首先启用的周期性动作;  那就是执行将在`initialDelay`之后开始，然后是`initialDelay+period`  ，然后是`initialDelay + 2 * period` ，等等。 |
| `ScheduledFuture<?>`     | `scheduleWithFixedDelay(Runnable command, long initialDelay,  long delay, TimeUnit unit)`  创建并执行在给定的初始延迟之后首先启用的定期动作，随后在一个执行的终止和下一个执行的开始之间给定的延迟。 |

## 实现类

### 1.4 ForkJoinPool

**特点**

拆分任务，用闲置线程执行，适用于计算密集型

### 1.5 ScheduledThreadPoolExecutor

定时执行任务

### 1.6 ThreadPoolExecutor

这是ExecutorService 的基本实现类，灵活稳定的线程池，可个性化配置

Executors为其提供了以下的实例等

- FixedThreadPool
- ScheduledThreadPool
- SingleThreadExecutor
- SingleThreadScheduledExecutor
- WorkStealingPool



# 二、性能指标





