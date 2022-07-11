# 一、jQuery概述

1.1 jQuery 简介

> jQuery是一个快速、简洁的JavaScript框架，是继Prototype之后又一个优秀的JavaScript代码库（*或JavaScript框架*）。jQuery设计的宗旨是“write Less，Do More”，即倡导写更少的代码，做更多的事情。它封装JavaScript常用的功能代码，提供一种简便的JavaScript设计模式，优化HTML文档操作、事件处理、动画设计和Ajax交互。
> 
> jQuery的核心特性可以总结为：具有独特的链式语法和短小清晰的多功能接口；具有高效灵活的css选择器，并且可对CSS选择器进行扩展；拥有便捷的插件扩展机制和丰富的插件。jQuery兼容各种主流浏览器，如IE 6.0+、FF 1.5+、Safari 2.0+、Opera 9.0+等。

1.2 jQuery的功能

> 1. HTML 元素选取
> 2. HTML 元素操作
> 3. CSS 操作
> 4. HTML 事件函数
> 5. Javascripts 特效和动画
> 6. HTML DOM 遍历和修改
> 7. Ajax
> 8. Utilities

1.3 为什么要用jQuery

> 1. jQuery 是目前最流行的Javascript框架，提供了大量的扩展
> 2. 许多公司都在用

# 二、jQuery的安装

> 1.CDN(Corporate Data Network)
> 
> 推荐网址：https://www.bootcdn.cn/jquery/
> 
> 当然还有很多方式,如官网下载

# 三、jQuery的语法

3.0 jQuery 基础语法

>  jQuery 语法
> 
> jQuery 语法是为 HTML 元素的选取编制的，可以对元素执行某些操作。
> 
> 基础语法是：*$(selector).action()*
> 
> - 美元符号定义 jQuery
> - 选择符（selector）“查询”和“查找” HTML 元素
> - jQuery 的 action() 执行对元素的操作
> 
> 实例：
> 
> $(this).hide() - 隐藏当前元素
> 
> $("p").hide() - 隐藏所有段落
> 
> $(".test").hide() - 隐藏所有 class="test" 的所有元素
> 
> $("#test").hide() - 隐藏所有 id="test" 的元素

3.1 jQuery 选择器

1. 元素选择器
   
   ```javascript
   $(document).ready(function(){
       $("button").click(function(){
           $("p").hide();
       });
   });
   ```

2. id选择器
   
   ```javascript
   $(document).ready(function(){
       $("button").click(function(){
           $("#test").hide();
       });
   });
   ```

3. class选择器
   
   ```javascript
   $(document).ready(function(){
       $("button").click(function(){
           $(".test").hide();
       });
   });
   ```

4. 组合使用
   
   ```javascript
   $(document).ready(function(){
       $("button").click(function(){
           $("p.test").hide();
       });
   });
   $(document).ready(function(){
       $("button").click(function(){
           $("p#test").hide();
       });
   });
   ```

5. 其他

3.2 jQuery事件及常用的事件方法

> - 什么是事件？
>   - ​    页面对不同访问者的响应
> 
> 事件处理程序：发生事件时所调用的方法
> 
> - 实例：
>   - 在元素上移动鼠标
>   - 选取单选按钮

| 鼠标事件       | 键盘事件     | 表单事件   | 文档/窗口事件 |
| ---------- | -------- | ------ | ------- |
| click      | keypress | submit | load    |
| dbclick    | keydown  | change | resize  |
| mouseenter | keyup    | focues | scroll  |
| mouseleave |          | blur   | unload  |
