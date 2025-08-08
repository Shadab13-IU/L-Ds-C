#include<stdio.h>
 void swap(int*,int*);
 void selectionsort(int*,int);
 void printarray(int*,int);
 int main(int argc,char* argv[]){
     int a[]={7,3,5,9,2,8,4};
     int len=sizeof(a)/sizeof(a[0]);
     printarray(a,len);
     selectionsort(a,len);
     printarray(a,len);
     return 0;
 }
 void swap(int* x,int* y){
     int temp=*x;
     *x=*y;
     *y=temp;
 }
 void selectionsort(int* a,int len){
     int index=0;
     for(int i=1; i<len; i++){
         index=i-1;
         for(int j=i; j<len; j++){
             if(a[j]<a[index]){
               index=j;
             }
         }
         swap(&a[i-1],&a[index]);
     }
 }
 void printarray(int* a,int len){
      for(int i=0; i<len; i++){
          printf("%d\t",a[i]);
      }
      printf("\n");
 }
 
