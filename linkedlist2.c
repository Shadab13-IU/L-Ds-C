#include<stdio.h>
#include<stdlib.h>
 
 void createlist(); 
 void insert_node();
 void deletenode();
 void traverse();
 struct node{
        int data;
        struct node* next;
 };

 
  int main(){
    struct node* head=NULL;
    int option;
          while(1){
          printf("1.Create list\n");
          printf("2.traverse list\n");
          printf("3.insertio of node\n");
          printf("4.Deletion of node\n");
          printf("5. Reverse linkedlist\n");
          printf("12. Exit\n");
          printf("Enter the option\n");
          scanf("%d",&option); 
          switch(option){
                case 1:
                     printf("List created\n"); 
                     createlist(&head); 
                     break;
                case 2:
                     printf("List traversed\n");
                     traverse(&head);                   
                     break;
                case 3:
                      int post;
                      printf("Enter the pos:\n");
                      scanf("%d",&post);
                      insert_node(&head,post);
                      break;
                case 4:
                     int pos;
                     printf("Enter the pos\n");
                     scanf("%d",&pos);
                     deletenode(&head,pos);
                     break;
                case 12:
                     exit(0);
                default:
                     printf("Wrong option\n");
         }
      }
  }
   void  createlist(struct node **hpointer){
           int non;
           printf("Enter the non\n");
           scanf("%d",&non);
           struct node* p;
           for(int i=1; i<=non; i++){
              struct node* temp=(struct node*)malloc(sizeof(struct node));
              temp->next=NULL;
              printf("Enter node data\n");
              scanf("%d",&(temp->data));
              if(i==1){
                *hpointer=temp;
                p=*hpointer;
              }else{
                   
                   while(p->next!=NULL)p=p->next;
                        p->next=temp;
               }
           }
          // return head;          
      }  
    void insert_node(struct node **hpointer,int post){
         struct node* temp=(struct node*)malloc(sizeof(struct node));
         temp->next=NULL;
         printf("Enter the data\n");
         scanf("%d",&temp->data);
         if(post==1){
           temp->next=*hpointer;
           *hpointer=temp;
         }else{
              struct node*p=*hpointer;
              int count=1;
              while(p->next!=NULL && count<post-1){
                   p=p->next;
                   count++;
              }
              temp->next=p->next;
              p->next=temp;
    } 
  } 
    void deletenode(struct node **hpointer,int pos){
                    struct node* p=*hpointer;
                    struct node* q=*hpointer;
		    if(p==NULL){
			printf("Linkedlist is empty\n");
			return 0;
		    }
                    if(pos==1){
                     *hpointer=p->next;
                     p->next=NULL;
                     free(p);
                    }else{
                         int count=1;
                         while(p->next!=NULL && count<pos){
                              q=p;
                              p=p->next;
                              count++;
                         }
			 if(count==pos){
                          q->next=p->next;
                          p->next=NULL;
                          free(p);
			 }
                    }
   }

  void traverse(struct node **hpointer){
             struct node*p=*hpointer;
              while(p!=NULL){
                   printf("%d\t",p->data);
                   p=p->next;
              }
       printf("\n");

  }
 

