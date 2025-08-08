#include<stdio.h>
#include<stdlib.h>
#include"stackll.h"
int main(int argc,char* argv[]){
	int option,data;
	while(1){
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.exit\n");
		printf("Enter option:");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter data:");
				scanf("%d",&data);
				data=push(data);
				if(data==0){
				printf("stack is overflow\n");
				}else{
				printf("stack created\n");
				}
				break;
			case 2:
				data=pop();
				if(data==-1){
					printf("Stack underflow\n");
				}else{
					printf("data=%d\n",data);
				}
				break;
			case 3:
				exit(0);
			default:
				printf("invalid option\n");
		}
	}
	return 0;
}
/*int push(int data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)return 0;
	temp->data=data;
	temp->next=NULL;
	if(top==NULL)top=temp;
	else{
		temp->next=top;
		top=temp;
	}
	return 1;
}

int pop(){
	if(top==NULL)return -1;
	struct node* temp=top;
	top=temp->next;
	temp->next=NULL;
	int data=temp->data;
	free(temp);
	return data;
}*/



