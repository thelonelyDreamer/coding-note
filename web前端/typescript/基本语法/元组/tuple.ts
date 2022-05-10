// 声明 初始化
console.log("声明 初始化")
let tupleA = ["abc",12,12.4,true,[1,3]];

// 声明 初始化
let tupleB = [];
tupleB[0]="afc";
tupleB[1]= false;

// 遍历和访问
console.log("console.log("")")
for(let val in tupleB){
	console.log(tupleB[val]);
}

// 元组的操作
console.log("---元组的操作")
var mytuple = [10,"Hello","World","typeScript"]; 
console.log("添加前元素个数："+mytuple.length)    // 返回元组的大小
 
mytuple.push(12)                                    // 添加到元组中
console.log("添加后元素个数："+mytuple.length) 
console.log("删除前元素个数："+mytuple.length) 
console.log(mytuple.pop()+" 元素从元组中删除") // 删除并返回删除的元素
        
console.log("删除后元素个数："+mytuple.length)

// 元组的更新
var mytuple = [10, "Runoob", "Taobao", "Google"]; // 创建一个元组
console.log("元组的第一个元素为：" + mytuple[0]) 
 
// 更新元组元素
console.log("---更新元组元素")
mytuple[0] = 121     
console.log("元组中的第一个元素更新为："+ mytuple[0])

// 解构元组
console.log("---解构元组")
var a =[10,"Runoob"] 
var [b,c] = a 
console.log( b )    
console.log( c )