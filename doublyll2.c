#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node* prev;
	int data;
	struct node* next;
}*head=NULL;
void create(int);
void traverse();
void insert(int,int);
void delete_node(int);
int main(int argc,char* argv[]){
	int option,non;
	while(1){
		printf("1.To create list\n");
		printf("2.To traverse list\n");
		printf("3.To insert a node\n");
		printf("4.Delete a node\n");
		printf("10.To exit\n");
		printf("Enter option:");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Enter non:");
				scanf("%d",&non);
				create(non);
				//traverse();
				break;
			case 2:
				traverse();
				break;
			case 3:
				int data,pos1;
				printf("Enter  data and pos:");
				scanf("%d%d",&data,&pos1);
				insert(data,pos1);
				break;
			case 4:
				int pos;
				printf("Enter pos:");
				scanf("%d",&pos);
				delete_node(pos);
				break;
			case 10:
				exit(0);
			default:
				printf("Invalid option\n");
		}
	}
	return 0;
}
void create(int n){
	for(int i=1; i<=n; i++){
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->prev=NULL;
		temp->next=NULL;
		printf("Enter data:");
		scanf("%d",&temp->data);
		if(i==1){
			head=temp;
		}else{
			struct node* p=head;
			while(p->next!=NULL)p=p->next;
			p->next=temp;
			temp->prev=p;
		}
	}
}
void insert(int data,int pos){
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->prev=NULL;
		temp->next=NULL;
		temp->data=data;
		if(head==NULL){
			head=temp;
		}else if(head!=NULL && pos==1){
			temp->next=head;
			head->prev=temp;
			head=temp;
		}else {
			struct node* p=head;
			int count=1;
			while(p->next!=NULL && count<pos-1){
				p=p->next;
				count++;
			}
			if(count==pos-1){
				temp->prev=p;
				temp->next=p->next;
				if(p->next!=NULL){
					p->next->prev=temp;
				}
				p->next=temp;
			}
		}
}
void delete_node(int pos){
	struct node* p=head;
	struct node* q=head;
	if(head==NULL){
		printf("List is empty\n");
	}else if(head!=NULL && pos==1){
		p->next->prev=NULL;
		head=p->next;
		p->next=NULL;
		free(p);
	}else if(head!=NULL && pos>1){
		int count=1;
		while(p->next!=NULL && count<pos){
			q=p;
			p=p->next;
			count++;
		}
		q->next=p->next;
		if(p->next!=NULL){
			p->next->prev=q;
		}
		p->next=NULL;
		p->prev=NULL;
		free(p);
	}else{
		printf("Invalid position\n");
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


