#include<stdio.h>
 //void sort(int*,int,void(*)(int*,int));
 void asc(int*,int);
 void dsc(int*,int);
 void swap(int*,int*);
 void printarray(int*,int);
      int main(){
          int a[]={5,2,7,3,4,1};
	  int len=sizeof(a)/sizeof(a[0]);
          printarray(a,len);
          asc(a,len);
          printarray(a,len);
          dsc(a,len);
          printarray(a,len);
          return 0;
      }
      void sort(int* a,int len,void(*fn)(int*,int){
           fn(a,len)
      }*/ 
      void asc(int* a,int len){
          int flag;
          for(int i=1; i<len; i++){
             flag=0;
             for(int j=1; j<len-i+1; j++){
                if(a[j-1]>a[j]){
                   flag=1;
                   swap(&a[j-1],&a[j]);
                }
             }
             if(flag==0)break;
          }
      }
      void dsc(int* a,int len){
           int flag;
           for(int i=1; i<len; i++){
              flag=0;
              for(int j=1; j<len-i+1; j++){
                 if(a[j-1]<a[j]){
		   flag=1;
                   swap(&a[j-1],&a[j]);
                 }
              }
              if(flag==0)break;
          }
      }
      void swap(int* x,int*y){
           int temp=*x;
           *x=*y;
           *y=temp;
      }
      void printarray(int*a,int len){
           for(int i=0; i<len; i++){
              printf("%d ",a[i]);
           }
           printf("\n");
      }
