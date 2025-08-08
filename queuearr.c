#include<stdio.h>
#include<stdlib.h>
int a[5]={};
int len=sizeof(a)/sizeof(a[0]);
int front =-1;
int rear=-1;
int enqueue(int);
int dequeue();
int main(int argc,char*argv[]){
	int option,data;
	while(1){
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Exit\n");
		printf("Enter option:");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter data:");
				scanf("%d",&data);
				data=enqueue(data);
				if(data==-1){
					printf("Queue is full\n");
				}else{
					printf("queue is created\n");
				}
				break;
			case 2:
				data=dequeue();
				if(data==-1)printf("Queue is empty\n");
				break;
			case 3:
				exit(0);
			default:
				printf("Invslid option\n");
		}
	}
}
int enqueue(int data){
	if(rear==len-1)return -1;
	a[++rear]=data;
	if(front==-1)front++;
}
int dequeue(){
	if((front==-1 && rear==-1) || front>rear)return -1;
	return a[front++];
}
