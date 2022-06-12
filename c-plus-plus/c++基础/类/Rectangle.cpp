#include<iostream> 

using namespace std;

class Rectangle{
	public:
		Rectangle(int top,int left,int buttom,int right){
			this->top =top;
			this->left = left;
			this->buttom = buttom;
			this->right = right;
		}
		~Rectangle(){
		}
		int getTop()const{
			return top;
		}
		int getLeft()const{
			return left;
		}
		int getButtom()const{
			return buttom;
		}
		int getRight()const{
			return right;
		}
	
	int getArea() const;
	private:
		int top;
		int left;
		int buttom;
		int right;
};

int Rectangle::getArea() const{
	return (right-left)*(top-buttom);
}

int main(){
	Rectangle rect(100,20,50,80);
	cout<<"Area: "<<rect.getArea()<<endl;
	
	return 0;
}
















