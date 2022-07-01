### 1. example-1

```cpp
#include<iostream>
using namespace std;
double add(double,double);
double substract(double,double);
double calculate(double,double,double (*)(double,double));

int main(int argc,char* argv[]){
    double q = calculate(2.5,10.4,add);
    cout<<q<<endl;
    double t = calculate(2.5,10.4,substact);
    cout<<t<<endl;
}

double add(double x,double y){
    return x+y;
}
double substract(double x,double y){
    return x-y;
}

double calculate(double x,double y,double (*pf)(double x1,double x2)){
    return pf(x,y);
}
```
