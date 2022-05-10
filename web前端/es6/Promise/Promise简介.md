## 一、前言

### 1. 实例对象与函数对象

```javascript
function Fn(){};
const fn = new Fn(); //实例对象fn
Fn.prototype
Fn.call({}) // Fn 就称为函数对象
```



### 2. 两种类型的回调函数

同步回调：执行完才往下走

```javascript
const arr=[1,3,5]
arr.forEach(item=>{console.log(item)});
console.log("forEach()之后")
// 1 3 5 forEach()之后
```

异步回调

```javascript
setTimeout(()=>{
	console.log("timeout callback()");
},0);
cosole.log("setTimeout()之后");
// setTimeout()之后 timeout callback()
```

### 3. 错误的类型

通过**Error**的构造器可以创建一个错误对象。当运行时错误产生时，Error的实例对象会被抛出。Error对象也可用于用户自定义的异常的基础对象。下面列出了各种内建的标准错误类型。

```
new Error([message[, fileName[,lineNumber]]])
```

参数

- `message`

  可选。人类可阅读的错误描述信息。

- `fileName `

  可选。被创建的Error对象的fileName属性值。默认是调用Error构造器代码所在的文件 的名字。

- `lineNumber `

  可选。被创建的Error对象的lineNumber属性值。默认是调用Error构造器代码所在的文件的行号。

```
// this:
const x = Error('I was created using a function call!');
// has the same functionality as this:
const y = new Error('I was constructed via the "new" keyword!');
```

**Error 类型**

除了通用的Error构造函数外，JavaScript还有6个其他类型的错误构造函数。更多客户端异常,详见 [Exception Handling Statements](https://developer.mozilla.org/en-US/JavaScript/Guide/Statements#exception_handling_statements)。

- **[`EvalError`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/EvalError)**

  创建一个error实例，表示错误的原因：与 [`eval()`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/eval) 有关。

- **[`InternalError`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/InternalError)** 

  创建一个代表Javascript引擎内部错误的异常抛出的实例。 如: "递归太多".

- **[`RangeError`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/RangeError)**

  创建一个error实例，表示错误的原因：数值变量或参数超出其有效范围。

- **[`ReferenceError`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/ReferenceError)**

  创建一个error实例，表示错误的原因：无效引用。

- **[`SyntaxError`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/SyntaxError)**

  创建一个error实例，表示错误的原因：[`eval()`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/eval)在解析代码的过程中发生的语法错误。

- **[`TypeError`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/TypeError)**

  创建一个error实例，表示错误的原因：变量或参数不属于有效类型。

- **[`URIError`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/URIError)**

  创建一个error实例，表示错误的原因：给 [`encodeURI()`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/encodeURI)或 [`decodeURI()`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/decodeURI)传递的参数无效。



## 二、 Promise

### 1. 简介

#### 1.1 抽象表达

Promise 是JS中进行异步编程的新的解决方案

#### 1.2 具体表达

（1）从语法来来说，Promise是一个构造函数

（2）从功能上来说，promise对象用来封装一个异步操作并可以获取其结果

### 2. 状态

1. pending变为resolved
2. pending变为rejected

说明：

- 只有这两种变化，并且只能改变一次，三种状态

- 无论变为成功还是失败，都会有一个结果数据
- 成功的结果数据一般称为 value，失败的结果数据一般称为 reason

### 3. promise 的基本流程

![image-20210817234201449](Promise%E7%AE%80%E4%BB%8B.assets/image-20210817234201449.png)

### 4. 基本使用

```javascript
//1.创建一个Promise对象
let promise = new Promise((resolve, reject) => {
  //执行器函数，同步回调
  let time = new Date();
  setTimeout(function () {
    if (time % 2) {
      resolve("promise成功状态" + time);
    } else {
      reject("promise失败时间" + time);
    }
  }, 1000);
});
promise.then(
  //接收得到成功的value值
  (value) => {
    console.log(value);
  },
  (reason) => {
    console.log(reason);
  }
);
```

### 5. 使用Promise的原因

#### 5.1 指定回调函数的方式更加灵活

- 旧的: 启动异步任务前指定
- 新的：可以在异步任务之后指定，也可以在之前指定

### 5.2 支持链式调用，可以解决回调地狱问题

回调地狱：多个异步操作，后面的操作取决于前一个的结果

asysc await

```
doSomething().then(function(result){
	return doSomething(result);
}).then({
	return doThirdthing
}).then({
	console.log("success")
}).catch(failureCallback)
```

```javascript
async function request(){
	try{
		const result = await doSomething();
		const newResult = await doSomethingElse(result);
		const finalResult = await doThirdThing(newResult);
		console.log(finalResul);
	}catch(error){
		failureCallback(error);
	}
}
```

### 6. api

- Promise 构造函数：Promise（excutor）{}

  ​	excutor 函数：同步执行 （resolve,reject）=>{}
  ​	resolve 函数：内部定义成功时我们调用的函数 value=>{}
  ​	reject 函数：内部定义失败时我们调用的函数 reason=>{}

- Promise.prototype.then 方法：（onResolved,onRejected）=>{}

  ​	onResolved 函数：成功的回调函数(value)=>{}

  ​	onRejected 函数：失败的回调函数(reason)=>{}

  ​	说明：指定用于得到成功 value 的成功回调和用于得到失败 reason 的失败回调，返回一个新的 promise 对象

- Promise.prototype.catch 方法：（onRejected）=>{}

  ​	onRejected 函数：失败的回调函数(reason)=>{}

  ​	说明：then()语法糖，相当于：then(undefined,onRejected)

- Promise.resolve 方法：(value)=>{}

  value:成功的数据或 promise 对象

  说明：resolve 方法返回一个成功/失败的 promise 对象Promise.reject 方法:(reason)=>{}

- reason:失败的原因
  说明：返回一个失败的 promise 对象

- Promise.all 方法：(promises)=>{}

  promises：包含 n 个 promise 数组

  说明：返回一个新的 promise，只有所有的 promise 都成功才成功，只要有一个失败了就直接失败

- Promise.race 方法：(promises)=>{}

  promises:包含 n 个 promise 的数组

  说明：返回一个新的 promise，最先完成的 promise 的结果状态就是最终的结果状态
  

7.



https://blog.csdn.net/sinat_30491515/article/details/114624762