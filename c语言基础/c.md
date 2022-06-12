```c
#include<stdio.h> 
#include<math.h>
#define PI 3.1415926535

void calculate(int selection);
double find_volumn_ball(void);
double find_volumn_cylinder(void);
double find_volumn_cone(void);

int main(void){
	int selection;
	while(1){
		printf(" 1-计算球体的体积");
		printf(" 2-计算圆柱体的体积"); 
		printf(" 3-计算圆锥体的体积"); 
		printf(" 0-退出程序\n"); 
		printf(" 请输入计算命令：");  
		scanf("%d",&selection);
		if(selection<0||selection>3){
			printf("输入有误，请重新输入\n");
			continue; 
		}else if(0==selection){
			break;
		}else{
			calculate(selection);
		} 
	}
	
	return 0;
}


void calculate(int selection){
	switch(selection){
		case 1:
			printf("The volumn of the ball is %.2f\n",find_volumn_ball());
			break;
		case 2:
			printf("The volumn of the cylinder is %.2f\n",find_volumn_cylinder());
			break;
		case 3:
			printf("The volumn of the cone is %.2f\n",find_volumn_cone());
			break;			
	}
}

// 计算球体的体积 
double find_volumn_ball(void){
	double r;
	printf("input the radius of the ball: ");
	scanf("%lf",&r);
	return (4.0/3.0*PI*r*r*r);
}

// 计算圆柱体的体积 
double find_volumn_cylinder(void){
	double r,h;
	printf("input the radius and the height of the cylinder: ");
	scanf("%lf%lf",&r,&h);
	return (PI*r*r*h);
}

// 计算圆锥体的体积 
double find_volumn_cone(void){
	double r,h;
	printf("input the radius and the height of the cone: ");
	scanf("%lf%lf",&r,&h);
	return (PI*r*r*h/3.0);
}

```





```c

```
