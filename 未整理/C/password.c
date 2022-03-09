#include<stdio.h>
#include<stdlib.h>

// 13*23=299 22*12=264
#define RSA_N 299
// 5*53=265
#define RSA_E 53
#define RSA_D 5

typedef struct Node{
	unsigned char app[20];
	unsigned char username[32];
	unsigned char password[32];
	unsigned char comment[32];
	struct Node * next;
}Node,* NodePtr;

typedef struct AllNode{
	int length;
	unsigned char pass[32];
	struct Node *next;
}AllNode,* AllNodePtr;

//文件的内存形式相关的函数
void initAllNode(AllNodePtr allnodePtr);
void destroyAllNode(AllNodePtr allnodePtr);

//整数的加密和解密
int encryptInt(int num);
int decryptInt(int num);

//一行数据的加密和存储
void encryptAndStore(FILE * fp,unsigned char *str,int length);
//一行数据的读取和解密
void decryptAndRead(FILE * fp,unsigned char *str,int length);

//文件操作
//关闭文件
void closeFile(FILE *fp);

// 验证两个字符串是否相同，相同返回1，不同返回0
int strIsSame(unsigned char a[], unsigned char b[],int length);

// 验证是否为本系统合法用户
void login(AllNodePtr allnodePtr);
//显示菜单
void showMenuAndHandle(AllNodePtr allnodePtr);

//存储文件函数
void saveEverything(AllNodePtr allnodePtr);
//读取文件函数
void readEverything(AllNodePtr allnodePtr);

// 增加一条记录
void addRecord(AllNodePtr allnodePtr);

// 删除一条记录
void deleteRecord(AllNodePtr allnodePtr);

// 根据应用名删除一组记录
void deleteRecordByGroup(AllNodePtr allnodePtr);

// 根据用户名显示一条记录
void showRecordByName(AllNodePtr allnodePtr);

// 根据应用名显示一组记录
void showRecordByApp(AllNodePtr allnodePtr);

// 更新一条记录
void updateRecode(AllNodePtr allnodePtr);

// 单纯显示一条记录
void showRecord(NodePtr node);
// 显示所有的记录
void showAllRecord(AllNodePtr allnodePtr);
// 形成短暂暂停并清空缓冲区
void suspend();


int main(void){
	
	FILE *fp; // 文件指针
	fp = fopen("./pass.txt","r");//打开存储文件
	
	//文件的内存形式
	AllNode fileData;
	
	initAllNode(&fileData);
	// 如果没有存储文件，则创建一个，初始化系统
	if(NULL == fp){
		fp = fopen("./pass.txt","w");
		fprintf(fp,"%d\n",encryptInt(0));
		unsigned char c[32] = "123456";
		encryptAndStore(fp,c,32);
		fprintf(fp,"\n");
	}
	closeFile(fp);
	readEverything(&fileData);
	
	login(&fileData);
	fflush(stdin);
	showMenuAndHandle(&fileData);
	
	printf("Bye!");
	return 0;
}


//文件的内存形式相关的函数
void initAllNode(AllNodePtr allnodePtr){	
	allnodePtr->length = 0;
	allnodePtr->next = NULL;
}

void destroyAllNode(AllNodePtr allnodePtr){
	NodePtr nodeTemp = NULL;
	NodePtr temp = allnodePtr->next;
	while(NULL != temp){
		nodeTemp = temp;
		temp = temp->next;
		free(nodeTemp);
	}
}

//一行数据的加密和存储
void encryptAndStore(FILE * fp,unsigned char *str,int length){
	int result,temp;
	for(int i = 0;i<length;i++){
		temp = (unsigned int)str[i];
		result =1;
		for(int j = 0;j<RSA_E;j++)
			result = result*temp % RSA_N;
		fprintf(fp,"%d ",result);
	}	
}
//一行数据的读取和解密
void decryptAndRead(FILE * fp,unsigned char *str,int length){
	int temp,result;
	for(int i = 0;i<length;i++){
		fscanf(fp,"%d",&temp);
		result =1;
		for(int j = 0;j<RSA_D;j++)
			result = result*temp% RSA_N;
		str[i]=result;
	}
}
//整数的加密和解密
int encryptInt(int num){
	int temp = 2154148466;
	return num^temp;
}
int decryptInt(int num){
	int temp = 2154148466;
	return num^temp;
}

//关闭文件
void closeFile(FILE *fp){
	if(fclose(fp)){
		printf("Can not close file,restart please");
		getchar();
		exit(0);
	}
}

// 显示主餐单
void showMenuAndHandle(AllNodePtr allnodePtr){
	while(1){
		printf("#####################################################\n");
		printf("## Welcome to password management system.\n");
		printf("## please input your commoand.\n");
		printf("-- type a to add a record\n");
		printf("-- type d to delete a record\n");
		printf("-- type e to delete a group of record\n");
		printf("-- type s to show a record by username and appName\n");
		printf("-- type t to show records by app type\n");
		printf("-- type u to update a record\n");
		printf("-- type r to show all record\n");
		printf("-- type q to quit\n");
		printf("#####################################################\n");
		char choose=getchar();
		int flag = 0;
		switch(choose){
			case 'a':
				addRecord(allnodePtr);
				break;
			case 'd':
				deleteRecord(allnodePtr);
				break;
			case 'e':
				deleteRecordByGroup(allnodePtr);
				break;
			case 's':
				showRecordByName(allnodePtr);
				break;
			case 't':
				showRecordByApp(allnodePtr);
				break;
			case 'u':
				updateRecode(allnodePtr);
				break;
			case 'r':
				showAllRecord(allnodePtr);
				break;
			case 'q':
				printf("## Bye\n");
				printf("## enter any key to quit\n");
				fflush(stdin);
				getchar();
				exit(0);
		}
		if(flag) break;
	}
}

// 验证两个字符串是否相同，相同返回1，不同返回0
int strIsSame(unsigned char a[], unsigned char b[],int length){
	int i =0;
	while(1){
		if(a[i]!=b[i]) return 0;
		if('\0'==a[i]) break;
		i++;
	}
	return 1;
}

// 验证是否为本系统合法用户
void login(AllNodePtr allnodePtr){
	unsigned char temp[32],again[32];
	int same=-1;
	while(1){
		printf("#####################################################\n");
		printf("## welcome to password management system.\n");
		printf("## please input your commoand.\n");
		printf("-- type i for login\n");
		printf("-- type u for update password\n");
		printf("-- type g for forget password\n");
		printf("-- type q for quit\n");
		printf("#####################################################\n");
		char choose = getchar();
		switch(choose){
			case 'i':
				printf("## please input this system password:");
				scanf("%s",temp);
				same = strIsSame(temp,allnodePtr->pass,32);
				break;
			case 'q':
				printf("## Bye\n");
				printf("## enter any key to quit\n");
				fflush(stdin);
				getchar();
				exit(0);
			case 'g':
				printf("## this function is not developed\n");
				printf("## you can write email to 2316700204@qq.com for help\n");
				break;
			case 'u':
				printf("## pleaese input your old password:\n");
				scanf("%s",temp);
				same = strIsSame(temp,allnodePtr->pass,32);
				if(same){
					while(1){
						printf("## pleaese input your new password:\n");
						scanf("%s",temp);
						printf("## pleaese input your new password again:\n");
						scanf("%s",again);
						same = strIsSame(temp,again,32);
						if(same) {
							for(int t =0;t<32;t++){
								allnodePtr->pass[t] = again[t]; 
							}
							saveEverything(allnodePtr);
							same = -1;
							printf("update password seccessufully\n");
							break;
						}
						else printf("## the password is not same,please try again\n");
					}
						
				}else{
					printf("## please try again\n");
					same = 0;
				}
				break;
			default:
				suspend();
		}
		if(same==1)
			break;
		if(same ==0) 
			printf("## error password,please try again\n");
		suspend();
	}
	
}

//存储文件
void saveEverything(AllNodePtr allnodePtr){
	FILE * fp = fopen("./pass.txt","w");
	fprintf(fp,"%d\n",encryptInt(allnodePtr->length));
	encryptAndStore(fp,allnodePtr->pass,32);
	fprintf(fp,"\n");
	NodePtr temp = allnodePtr->next;
	while(temp!=NULL){
		encryptAndStore(fp,temp->app,20);
		encryptAndStore(fp,temp->username,32);
		encryptAndStore(fp,temp->password,32);
		encryptAndStore(fp,temp->comment,32);
		temp = temp->next;
	}
	closeFile(fp);
	readEverything(allnodePtr);
}

//读取文件函数
void readEverything(AllNodePtr allnodePtr){
	destroyAllNode(allnodePtr);
	initAllNode(allnodePtr);
	FILE * fp = fopen("./pass.txt","r");
	fscanf(fp,"%d",&allnodePtr->length);
	allnodePtr->length=decryptInt(allnodePtr->length);
	decryptAndRead(fp,allnodePtr->pass,32);
	for(int i=0;i<allnodePtr->length;i++){
		NodePtr temp = (NodePtr)malloc(sizeof(Node));
		decryptAndRead(fp,temp->app,20);
		decryptAndRead(fp,temp->username,32);
		decryptAndRead(fp,temp->password,32);
		decryptAndRead(fp,temp->comment,32);
		temp->next = allnodePtr->next;
		allnodePtr->next = temp;
	}	
	closeFile(fp);
}

// 增加一条记录
void addRecord(AllNodePtr allnodePtr){
	NodePtr temp = (NodePtr)malloc(sizeof(Node));
	printf("please input app name. make sure length less than 19 Byte.\n");
	scanf("%s",temp->app);
	printf("please input username. make sure length less than 31 Byte.\n");
	scanf("%s",temp->username);
	NodePtr p = allnodePtr->next;
	while(p!=NULL){
		if(strIsSame(p->app,temp->app,20)&&strIsSame(p->username,temp->username,20))break;
		p=p->next;
	}
	if(p!=NULL){
		printf("---------------------------------------------------------------\n");
		printf("record already exists\n");
		printf("---------------------------------------------------------------\n");
		suspend();
		return;
	}
	printf("please input password. make sure length less than 31 Byte.\n");
	scanf("%s",temp->password);
	printf("please input comment. make sure length less than 31 Byte.\n");
	scanf("%s",temp->comment);
	temp->next=allnodePtr->next;
	allnodePtr->next = temp;
	allnodePtr->length++;
	printf("you have added a record:\n");
	showRecord(temp);
	saveEverything(allnodePtr);
	suspend();
	return;
}

// 删除一条记录
void deleteRecord(AllNodePtr allnodePtr){
	char app[20];
	char username[32];
	printf("please input app name. make sure length less than 19 Byte.\n");
	scanf("%s",app);
	printf("please input username. make sure length less than 31 Byte.\n");
	scanf("%s",username);
	NodePtr t = allnodePtr->next;
	NodePtr r,s= (NodePtr)malloc(sizeof(Node));
	s->next = t;
	r=s;
	while(NULL!=t){
		if(strIsSame(t->username,username,32)&&strIsSame(t->app,app,20)){
			r->next = t->next;
			allnodePtr->next = s->next;
			free(t);
			allnodePtr->length--;
			saveEverything(allnodePtr);
			printf("deleted a record\n");
			break;
		}	
		t=t->next;
		r=r->next;
	}
	if(t==NULL){
		printf("no this record\n");
	}
	free(s);
	suspend();
	return;
}

// 根据应用名删除一组记录
void deleteRecordByGroup(AllNodePtr allnodePtr){
	char appName[20];
	printf("please input app name. make sure length less than 19 Byte.\n");
	scanf("%s",appName);
	NodePtr t = allnodePtr->next;
	NodePtr r,s= (NodePtr)malloc(sizeof(Node));
	s->next = t;
	r=s;
	int i =0;
	while(NULL!=t){
		if(strIsSame(t->app,appName,20)){
			r->next = t->next;
			free(t);
			t=r->next;
			allnodePtr->length--;
			i++;
			printf("deleted the %drd record\n",i);
		}else{
			t=t->next;
			r=r->next;
		}	
		
	}
	
	if(i==0){
		printf("no this record\n");
	}else{
		allnodePtr->next = s->next;
		saveEverything(allnodePtr);
	}
	
	free(s);
	suspend();
	return;
}

// 根据用户名显示一条记录
void showRecordByName(AllNodePtr allnodePtr){
	char app[20];
	char username[32];
	printf("please input app name. make sure length less than 19 Byte.\n");
	scanf("%s",app);
	printf("please input username. make sure length less than 31 Byte.\n");
	scanf("%s",username);
	NodePtr t = allnodePtr->next;
	int i = 0;
	while(NULL!=t){
		if(strIsSame(t->username,username,32)&&strIsSame(t->app,app,20)){
			showRecord(t);
			i++;
			break;
		}	
		t=t->next;
	}
	if(i==0){
		printf("no this record\n");
	}
	suspend();
	return;
}

// 根据应用名显示一组记录
void showRecordByApp(AllNodePtr allnodePtr){
	char app[20];
	printf("please input app name. make sure length less than 19 Byte.\n");
	scanf("%s",app);
	NodePtr t = allnodePtr->next;
	int i=0;
	while(NULL!=t){
		if(strIsSame(t->app,app,20)){
			showRecord(t);
			i++;
		}	
		t=t->next;
	}
	if(i==0 ){
		printf("no this record\n");
	}
	suspend();
	return;
}

// 显示所有记录
void showAllRecord(AllNodePtr allnodePtr){
	printf("there is %d records\n",allnodePtr->length);
	NodePtr t = allnodePtr->next;
	int i =0;
	while(NULL!=t){
		showRecord(t);
		i++;
		t=t->next;
	}
	if(i==0 ){
		printf("no records\n");
	}
	suspend();
	return;
}

// 更新一条记录
void updateRecode(AllNodePtr allnodePtr){
	char app[20];
	char username[32];
	printf("please input app name. make sure length less than 19 Byte.\n");
	scanf("%s",app);
	printf("please input username. make sure length less than 31 Byte.\n");
	scanf("%s",username);
	NodePtr t = allnodePtr->next;
	while(NULL!=t){
		if(strIsSame(t->username,username,32)&&strIsSame(t->app,app,20)){
			printf("please input password. make sure length less than 31 Byte.\n");
			scanf("%s",t->password);
			printf("please input comment. make sure length less than 31 Byte.\n");
			scanf("%s",t->comment);
			printf("the new recode is: \n");
			showRecord(t);
			saveEverything(allnodePtr);
			break;
		}	
		t=t->next;
	}
	if(t==NULL){
		printf("no this record\n");
	}
	suspend();
	return;
}

// 单纯显示一条记录
void showRecord(NodePtr node){
	printf("---------------------------------------------------------------\n");
	printf("- app: %s\n",node->app);
	printf("- username: %s\n",node->username);
	printf("- password: %s\n",node->password);
	printf("- comment: %s\n\n",node->comment);
}

void suspend(){
	getchar();
	printf("enter any to menu\n");
	getchar();
	fflush(stdin);
}