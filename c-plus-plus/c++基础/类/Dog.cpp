#include<iostream>
using namespace std;

class Dog{
	public:
		Dog(int initialAge=0,int initialWeight =5);
		~Dog();
		int getAge(){
			return this->age;
		}
		void setAge(int age){
			this->age=age;
		} 
		int getWeight(){
			return this->weight;
		}
		void setWeight(int weight){
			this->weight=weight;
		}
	private:
		int age;
		int weight;
}; 
Dog::Dog(int initialAge,int initialWeight){
	this->age=initialAge;
	this->weight=initialWeight;
} 

Dog::~Dog(){
}

int main(void){
	Dog jack(2,10);
	cout<<"Jack is a Dog who is "<<jack.getAge()<<" years old and "<<jack.getWeight()<<" pounds weight"<<endl;
	jack.setAge(7);
	jack.setWeight(20);
	cout<<"Now Jack is "<<jack.getAge()<<" years old and "<<jack.getWeight()<<" pounds weight"<<endl;
	
	getchar(); 
	return 0;
}















