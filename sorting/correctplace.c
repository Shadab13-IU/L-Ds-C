#include<stdio.h>
 void correctplace(int*,int);
 printarray(int*,int);
 int main(int argc,char* argv[]){
     int a[]={-2,4,3,-1,-5,7,8,-6};
     int len=sizeof(a)/sizeof(a[0]);
     correctplace(a,len);
     printarray(a,len);
     return 0;
 }
 void correctplace(int*a,int len){
     int i=0,j=len-1;
     while(i<j){
	 while(a[i]>0)i++;
         while(a[j]<0)j--;
         if(i<j){
          swap(&a[i],&a[j]);
	 }
     }
 }
 printarray(int*a,int len){
     for(int i=0; i<len; i++){
       printf("%d\t",a[i]);
     }
     printf("\n");
 }
 void swap(int*x,int*y){
      int temp=*x;
      *x=*y;
       *y=temp; 
 } 
