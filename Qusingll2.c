#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
}*front=NULL,*rear=NULL;
int Enqueue(int);
int Dequeue();
int main(int argc,char* argv[]){
	int option,data;
	while(1){
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Exit\n");
		printf("Enter option\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter data:");
				scanf("%d",&data);
				data=Enqueue(data);
				if(data==-1)printf("unable to Enqueue\n");
				printf("Succesfully Enqueue\n");
				break;
			case 2:
				data=Dequeue();
				if(data==-1){
					printf("Queue is empty\n");
				}
				printf("Dequeue data=%d\n",data);
				break;
			case 3:
				exit(0);
			default:
				printf("Invalid option\n");
		}
	}
}
int Enqueue(int data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)return -1;
	temp->data=data;
	temp->next=NULL;
	if(front==NULL && rear==NULL){
		front=temp;
		rear=temp;
		return 1;
	}
	rear->next=temp;
	rear=rear->next;
	return 1;
}
int Dequeue(){
	struct node* temp;
	temp=front;
	if(front==NULL && rear==NULL)return -1;
	front=temp->next;
	int x=temp->data;
	temp->next=NULL;
	free(temp);
	if(front==NULL)rear=NULL;
	return x;
}
