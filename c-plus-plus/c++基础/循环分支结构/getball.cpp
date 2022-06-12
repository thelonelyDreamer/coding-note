#include<iostream>

using namespace std;

int main()
{
	enum color{
		red,yellow,blue,white,black
	};
	enum color pri;
	int i,j,k,loop,n=0;
	for(i=red;i<=black;i++)
		for(j=red;j<=black;j++)
		if(i!=j){
			for(k=red;k<=black;k++)
			 	if(k!=i&&k!=j){
			 		n+=1;
			 		cout.widen(4);
			 		cout<<n;
			 		for(loop=1;loop<=3;loop++){
			 			switch(loop){
			 				case 1:pri = (enum color) i; break;
			 				case 2:pri = (enum color) j; break;
			 				case 3:pri = (enum color) k; break;
			 				default:break;
						}
						switch(pri){
							case red:cout<<" \tred";break;
							case yellow:cout<<"\tyellow";break;
							case blue:cout<<"\tblue";break;
							case white:cout<<"\twhite";break;
							case black:cout<<"\tblack";break;
							default:break;
						}
					 }
			 		cout<<endl; 
				 } 
		}
	cout<<"total: "<<n<<endl;
	
	return 0;
}
