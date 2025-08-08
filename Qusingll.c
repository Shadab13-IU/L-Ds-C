#include<stdio.h>
#include<stdlib.h>
 struct node{
        int data;
        struct node* next;
 }*front=NULL,*rear=NULL;

 int enqueue(int);
 int dequeue();

 int main(int argc,char*argv[]){
     int option, data;
     printf("Enter option\n");
     scanf("%d",&option);
     switch(option){
	   case 1:
                printf(	"Enqueue\n");
                printf("enter data\n");
                scanf("%d",&data);
                enqueue(data);
                break;
           case 2:
                printf("Dequeue\n");
                dequeue();
                break;
           case 3:
                exit(0);
     }
 }

 int enqueue(int data){
     		
     struct node* temp=(struct node*)malloc(sizeof(struct node));
	    
     if(temp==NULL){
       return 0;
     }
     temp->data=10;
     temp->next=NULL;

     if(front==NULL && rear==NULL){
       front=temp;
       rear=temp;
       return 1;
    }
    rear->next=temp;
    rear=temp;
    return 1;
 }
 
 int dequeue(){
     if(front==NULL && rear==NULL)return -1;
       struct node* temp=front;
       front=temp->next;
       temp->next=NULL;
       int x=temp->data;
       free(temp);
       if(front==NULL) rear=NULL;
       return x;
 }

