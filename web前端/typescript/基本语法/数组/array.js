// 声明一个数组对象，同时指定其大小
console.log("声明数组对象，并指定其大小，初始化并使用");
var arr_names = new Array(4);
for (var i = 0; i < arr_names.length; i++) {
    arr_names[i] = i * 2;
    console.log(arr_names[i]);
}
var names = new Array("zhangsan", "lisi", "wangwu");
for (var i = 0; i < names.length; i++) {
    console.log(names[i]);
}
