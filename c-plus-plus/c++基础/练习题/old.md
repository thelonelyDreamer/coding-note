### 1. 输出九九乘法表

```cpp
//-----输出九九表----- 
#include<iostream>
#include<iomanip>        //manipulator(操纵器） 
using namespace std;

 int main(){
     int i,j;
     cout<<' ';
     for(i=1;i<10;i++)
         cout<<setw(4)<<i;
         cout<<endl;
     for(i=1;i<10;i++){
         cout<<i;
         for(j=1;j<10;j++)
         cout<<setw(4)<<(i*j);//设置域宽，当输出超过域宽时，则setw不起作用 
         cout<<endl;
     }
     return 0;
 } 
```

### 2. 颜色五选三

```cpp
//-----颜色五选三----- 
#include<iostream>
using namespace std;

int main(){
    enum color{red,yellow,blue,white,black};
    enum color pri;
    int n,loop,i,j,k;
    char c;
    n=0;
    for(i=red;i<=black;i++)
        for(j=red;j<=black;j++)
            if(i!=j)
            {
                for(k=red;k<=black;k++)
                if((k!=i)&&(k!=j)){
                    n=n+1;
                    cout.width(4);
                    cout<<n;
                    for(loop=1;loop<=3;loop++)
                    {
                        switch(loop)
                        {
                            case 1:pri=(enum color)i;break;
                            case 2:pri=(enum color)j;break;
                            case 3:pri=(enum color)k;break;
                            default:break;
                        }
                        switch(pri){
                            case red:cout<<"\tred";break;
                            case yellow:cout<<"\tyellow";break;
                            case blue: cout<<"\tblue";break;
                            case white:cout<<"\twhite";break;
                            case black:cout<<"\tblack" ;break;
                            default:break; 
                        }
                    }
                    cout<<endl;
                }
            }
    cout<<"total:"<<n<<endl;
    return 0;
} 
```
