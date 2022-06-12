#include<iostream>

using namespace std;

class Rectangle{
	private:
		int top,buttom,left,right;
		
	public:
		Rectangle(int top, int left,int buttom,int right);
		~Rectangle(){
		}
		
		int getArea() const{
			return (right-left)*(top-buttom);
		}
};

Rectangle::Rectangle(int top, int left,int buttom,int right){
	this->top=top;
	this->left=left;
	this->buttom=buttom;
	this->right=right;
}

int main(void){
	Rectangle rectangle(100,20,50,80);
	cout<<"Area: "<<rectangle.getArea();
	
	getchar();
	return 0;
}
