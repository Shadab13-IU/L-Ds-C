#include<stdio.h>
#include<stdlib.h>
static int top=-1;
#define	LENGTH 10
static int stack[LENGTH];
int push(int);
//int pop();
int main(int argc,char* argv[]){
	int option,data;
	while(1){
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("enter option:");
		scanf("%d",&option);
		switch(option){
			case 1:
			printf("Data:");
			scanf("%d",&data);
			data=push(data);
			if(data==-1){
				printf("Stack is overflow\n");
			}
			printf("%d\n",data);
			break;
			/*case 2:
			data=pop();
			if(data=-1){
				printf("Stack underflow\n");
			}else{
				printf("Popped data=%d\n",data);
			}
			break;*/
			case 3:
				exit(0);
			default:
				printf("Invalid option\n");
		}
	}
	return 0;
}
int push(int data){
	if(top==10){
		printf("Stack overflow\n");
	}
	stack[++top]=data;
}
/*int pop(){
	if(top==-1){
		return -1;
	}
	return stack[top--];
}
*/
