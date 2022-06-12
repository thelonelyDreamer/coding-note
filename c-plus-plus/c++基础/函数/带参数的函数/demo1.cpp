#include<iostream>

using namespace std;
//有默认值得参数必须在最后 
int add(int x ,int y=4, int z=3);
int main(){
	cout<<add(4)<<endl; 
	cout<<add(4,2)<<endl;
	cout<<add(3,2,1)<<endl;
	return 0;
} 

// 在相同的作用域内，不允许在同一个函数的 多个声明中对参数的默认值重复定义
// 一般像这样注释 
int add (int x , int y /*=4*/,int z /*=3*/){
	return x+y+z;
}
