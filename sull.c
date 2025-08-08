#include<stdio.h>
#include<stdlib.h>
 
 typedef struct mynode{
         int data;
         struct mynode* next;
 }node;

 node* push(node**, int);
 int pop(node**);
 int peek(node**);

 int main(int argc ,char argv[]){
     node* top=NULL;
     int option,data;
     while(1){
          printf("1.Push\n");
          printf("2.pop\n");
          printf("3.peek\n");
          printf("4.exit\n");
          scanf("%d",&option);
          switch(option){
                case 1: 
                     printf("Enter data\n");
                     scanf("%d",&data);
                     node* result=push(&top,data);
                     if(result=NULL){
                                    printf("Stack overflow\n");
                     }
                     
                 
                     break;
                 case 2:
                     data=pop(&top);
                     printf("%d\n",data);
                     break;             
  
                 case 3:
                     data=peek(&top);
                     printf("%d\n",data);
                     break;   
                 case 4:
                     exit(0);
                 default:
                       printf("Wrong option\n"); 
           }
      }              
       
   
    return 0;
 }
  
 node* push(node**ta,int data){
         node* temp=(node*)malloc(sizeof(node));
         if(temp==NULL)return NULL;
         temp->data=data;
         temp->next=*ta; 
         *ta=temp;
         return temp;
 }
   int pop(node**ta){
       node* temp=*ta;
       if(temp==NULL)return -1;
       *ta=temp->next;
       temp->next=NULL;
       int x=temp->data;
       free(temp);
       return x;
 }

     
 int peek(node**ta){
     node* temp=*ta;
     if(temp==NULL)return temp->data;
 }

     
