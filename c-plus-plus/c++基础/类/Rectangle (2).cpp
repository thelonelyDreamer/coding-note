#include<iostream>

using namespace std;

class Rectangle{
	private:
		float length;
		float width;
	public:
		Rectangle(float length,float width){
			this->length=length;
			this->width=width;
		}
		~Rectangle(){
			
		}
		
		float getArea(){
			return this->length*this->width;
		}
};

int main(void){
	float length,width;
	cout<<"请输入矩形的长度：";
	cin>>length;
	cout<<"请输入矩形的宽度：";
	cin>>width; 
	Rectangle retangle(length,width);
	cout<<"面积为："<<retangle.getArea()<<endl;
	
	getchar();
	return 0; 
}
