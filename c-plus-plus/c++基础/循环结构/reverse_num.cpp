#include<iostream>
using namespace std;

int main(){
	int n,right_digit,newnum=0;
	cout<<"Enter the number: ";
	cin>>n;
	do{
		right_digit=n%10;
		newnum = newnum*10+right_digit;
		n=n/10;
	}while(n!=0);
	
	cout<<"the num in reverse order is "<<newnum<<endl;
	
	return 0;
}
