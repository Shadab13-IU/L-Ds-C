#include<stdio.h>
#include<stdlib.h>
   void create();
   void traverse();
	struct node{
		struct node* prev;
		int data;
		struct node* next;
	}*head=NULL;
	int main(int argc,char* argv[]){
	    int option;
		while(1){
			printf("1.Create\n");
			printf("2.Traverse\n");
			printf("3.Exit\n");
			printf("Enter option\n");
			scanf("%d",&option);
			switch(option){
				case 1:
					printf("Create\n");
					create();
					break;
				case 2:
					printf("Traverse\n");
					traverse();
				case 3:
					exit(0);
			}
	       }
	}
	void create(){
		int non;
		printf("Enter non\n");
		scanf("%d",&non);
		struct node*p;
		for(int i=1; i<=non; i++){
		   struct node* temp=(struct node*)malloc(sizeof(struct node));
			temp->next=temp;
			temp->prev=temp;
			printf("Enter data\n");
			scanf("%d",&(temp->data));
			if(head==NULL){
			  head=temp;
			  p=head;
			}else{
			     while(p->next!=head)p=p->next;
			          p->next=temp;
					temp->prev=p;
					temp->next=head;
					head->prev=temp;
			 }
		}	
	}
	void traverse(){
		struct node*p=head;
			if(p==NULL){
				printf("List is empty\n");
			}else{
				printf("%d\t",p->data);
				p=p->next;
			}
			while(p!=head){
			printf("%d\t",p->data);
			p=p->next;
			}
			printf("%d\n",p->data);
			p=p->prev;
			printf("%d\t",p->data);
			p=p->prev;
				while(p!=head){
				printf("%d\t",p->data);
				p=p->prev;
			        }
				
				printf("%d\t",p->data);
				p=p->prev;
				printf("%d\n",p->data);
	}	

