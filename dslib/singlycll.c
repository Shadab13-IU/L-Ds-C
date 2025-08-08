#include<stdio.h>
#include<stdlib.h>
#include"scll.h"
t create(int num){
	int data;
	t temp,head=NULL;
	for(int i=1; i<=num; i++){
		temp=(t)malloc(sizeof(node));
		temp->next=temp;
		printf("Enter the data\n");
		scanf("%d",&(temp->data));
		if(head==NULL){
			head=temp;
		}else{
			t p=head;
			while(p->next!=head)p=p->next;
				p->next=temp;
				temp->next=head;
			}
		}
		return head;
}
void insert(t** hpointer,int pos,int data){
		t temp=(t)malloc(sizeof(node));
		temp->next=temp;
		temp->data=data;
		if(*hpointer==NULL){
			*hpointer=temp;
		}else if(*hpointer!=NULL && pos==1){
			temp->next=*hpointer;
			*hpointer=temp;
			temp->next->next=*hpointer;
		}else if(*hpointer!=NULL && pos>1){
			t p=*hpointer; 
			int count=1;
			while(p->next!=*hpointer && count<pos-1){
				p=p->next;
				count++;
			}
			temp->next=p->next;
			p->next=temp;
		}else{
			printf("Invalid position\n");
		}
}
void deletenode(t** hp,int pos){
		t p=*hp;
		t q=*hp;
		if(pos==1){
			while(q->next!=*hp)q=q->next;
			*hp=p->next;
			p->next=NULL;
			q->next=*hp;
			free(p);
		}else{
			int count=1;
			while(p->next!=*hp && count<pos){
				q=p;
				p=p->next;
				count++;
			}
			q->next=p->next;
			p->next=NULL;
			free(p);
		}
}
void traverse(t head){
	t p=head;
	do{
		printf("%d\t",p->data);
	        p=p->next;
	}while(p!=head);
	//printf("%d",p->data);
	printf("\n");
}
int main(int argc,char* argv[]){
	while(1){
	int choice;
	printf("Enter the choice:\n");
	printf("1.Create the list\n");
	printf("2.Insertion of node\n");
	printf("3.Deletion of node\n");
	printf("4.Exit\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("creating list\n");
				int non;
				printf("Enter non:");
				scanf("%d",&non);
				t head=create(non);
				traverse(head);
				break;
			case 2:
				printf("Inserting a node\n");
				int pos,data;
				printf("Enter pos and data:");
				scanf("%d%d",&pos,&data);
				insert(&head,pos,data);
				traverse(head);
				break;
			case 3:
				printf("Deleting a node\n");
				printf("Enter a pos:");
				scanf("%d",&pos);
				deletenode(&head,pos);
				traverse(head);
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}

/*	printf("Enter non,pos,data:");
	scanf("%d%d%d",&non,&pos,&data);
	t head=create(non);
	traverse(head);
	deletenode(&head,pos);
	//insert(&head,pos,data);
	traverse(head);
	return 0;
}*/
