#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node* prev;
	int data;
	struct node* next;

}*head=NULL;
void create();
void traverse();
void insert();
void delete_node();
int main(int argc,char* argv[]){
	create();
	traverse();
	delete_node();
	traverse();
	return 0;
}
void create(){
	struct node* temp;
	int non,data;
	printf("Enter non:");
	scanf("%d",&non);
	for(int i=1; i<=non; i++){
		temp=(struct node*)malloc(sizeof(struct node));
		temp->prev=temp;
		temp->next=temp;
		printf("Enter data:");
		scanf("%d",&temp->data);
		if(head==NULL){
		head=temp;
		}else{
		struct node* p=head;
		while(p->next!=head)p=p->next;
		p->next=temp;
		temp->prev=p;
		temp->next=head;
		head->prev=temp;
		}
	}
}void insert(){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=temp;
	temp->next=temp;
	int data,pos;
	printf("Enter data and pos:");
	scanf("%d%d",&data,&pos);
	if(head!=NULL && pos==1){
		temp->next=head;
		
void delete_node(){
	int pos;
	printf("Enter pos:");
	scanf("%d",&pos);
	struct node* p;
	struct node* q;
	if(pos==1){
		p=head->next;
		q=head->prev;
		head->prev=NULL;
		head->next=NULL;
		head=p;
		p->prev=q;
		q->next=head;
	}else{
		p=head;
		q=head;
		int count=1;
		while(p->next!=head && count<pos){
			q=p;
			p=p->next;
			count++;
		}
		if(count==pos){
			q->next=p->next;
			p->next->prev=q;
			p->next=NULL;
			p->prev=NULL;
		}
	}
}
void traverse(){
	struct node* p=head;
	while(p->next!=head){
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("%d\t",p->data);
	printf("%d\n",head->data);
	while(p->prev!=head->prev){
		printf("%d\t",p->data);
		p=p->prev;
	}
	printf("%d\t",p->data);
	p=p->prev;
	printf("%d\n",p->data);
}

