#include<stdio.h>
#include<stdlib.h>
   void create();
   void traverse();
   void insertion();
   struct node{
	  struct node* prev;
	  int data;
	  struct node* next;
   }*head=NULL;
    int main(int argc,char*argv[]){
	int option,pos;
	while(1){
		printf("1.Create\n");
		printf("2.Traverse\n");
	        printf("3.insert\n");
		printf("4.Exit\n");
		printf("Enter option\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("create\n");
				create();
				break;
			case 2:
				printf("Traverse\n");
				traverse();
				break;
			case 3:
				printf("Insert\n");
				printf("Enter pos\n");
				scanf("%d",&pos);
				insertion(pos);
				break;

			case 4:
				exit(0);
			default:
				printf("Wrong option\n");
		}
	}
   }

   void create(){
	int non;
	printf("Enter non\n");
        scanf("%d",&non);
	struct node* p;
	for(int i=1; i<=non; i++){
	   struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->next=NULL;
		temp->prev=NULL;
		printf("ENter data\n");
		scanf("%d",&(temp->data));
		if(i==1){
			head=temp;

		}else{
			p=head;
			while(p->next!=NULL)p=p->next;
			     p->next=temp;
			     temp->prev=p;

		}
	}
  }
  void traverse(){
  struct node* p=head;
   while(p->next!=NULL){
	 printf("%d\t",p->data);
         p=p->next;
   }

	printf("%d\n",p->data);
   while(p->prev!=NULL){
	 printf("%d\t",p->data);
         p=p->prev;
  }
   printf("%d\n",p->data);

 }

 void insertion(int pos){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->next=NULL;
		temp->prev=NULL;
		printf("Enter data\n");
		scanf("%d",&(temp->data));
	struct node*q=head;
	struct node*p=head;
	if(pos==1){
	  temp->next=p;
	  p->prev=temp;
	  head=temp;
	}else{
	     int count=1;
	     while(p->next!=NULL && count<pos-1){
		  p=p->next;
		  q=p;
	          count++;
	     }
	     if(p->next==NULL){
		temp->next=p->next;
		temp->prev=p;
	     }
	     q=q->next;
	     temp->next=p->next;
	     p->next=temp;
	     temp->prev=p;
	     q->prev=temp;
	 }
 }
