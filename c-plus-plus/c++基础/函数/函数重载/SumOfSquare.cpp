#include<iostream>
using namespace std;

int sumOfSquare(int a,int b){
	return a*a+b*b;
}

// 重载看参数个数或者类型，函数名要相同
// 习惯上将功能相同的两个函数重载，其他函数不要重载，以免误用 
double sumOfSquare(double a,double b){
	return a*a+b*b;
}

int main(){
	int m,n;
	cout<<"Enter two integer:"<<endl;
	cin>>m>>n;
	cout<<"Their sum of square: "<<sumOfSquare(m,n)<<endl;
	
	double x,y;
	cout<<"Enter two real numble:"<<endl;
	cin>>x>>y;
	cout<<"Their sum of square: "<<sumOfSquare(x,y)<<endl;
	
	return 0;
	
}
