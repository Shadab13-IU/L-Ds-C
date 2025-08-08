
#include<stdio.h>
#include<stdlib.h>
	struct node{
		int data;
		struct node* next;
	}*head=NULL;
	void createlist();
	void Traverse();
	int main(int argc,char* argv[]){
		int option;
		    while(1){
			printf("1.Createlsit\n");
			printf("2.Traverse\n");
			printf("Exit\n");
			printf("Enter option\n");
			scanf("%d",&option);
			switch(option){
				case 1:
				     printf("Create\n");
				     createlist();
				     break;
				case 2:
					printf("Traverse\n");
					Traverse();
					break;
				case 3:
					exit(0);
				default:
					printf("Wrong option\n");
                        }

      		    }
        }

	void createlist(){
		int non;
		printf("Enter the non\n");
		scanf("%d",&non);
		struct node* p;
		for(int i=1; i<=non; i++){
		    struct node* temp=(struct node*)malloc(sizeof(struct node));
		    temp->next=temp;
		    printf("Enter the data\n");
		    scanf("%d",&(temp->data));
		    if(i==1){
			head=temp;
			p=head;
		    }else{
			while(p->next!=head)p=p->next;
				p->next=temp;
                    }
                    temp->next=head;

		}

	}
	void Traverse(){
		struct node*p=head;
                      if(p==NULL){
                        printf("List is empty\n");
                     }else{
				printf("%d\t",p->data);
				p=p->next;
                       while(p!=head){
                            printf("%d\t",p->data);
                            p=p->next;
			}
			printf("%d\n",p->data);
			}
	}
