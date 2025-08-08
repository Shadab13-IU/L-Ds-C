#include<stdio.h>
#include<stdlib.h>
 int* merge(int*,int,int*,int);
 printarray(int*,int);
 int main(int argc,char* argv[]){
     int a[]={2,8,12,15,17,48,56};
     int b[]={3,7,9,14,18,19};
     int lena=sizeof(a)/sizeof(a[0]);
     int lenb=sizeof(b)/sizeof(b[0]);
     int* result=merge(a,lena,b,lenb);
     //int lenk=lena+lenb;
     printarray(result,lena+lenb);
     return 0;
 }
 int* merge(int* a,int lena,int* b,int lenb){
     int *temp=(int*)calloc(lena+lenb,sizeof(int));
     int i=0;
     int j=0;
     int k=0;
     while(i<lena && j<lenb){
          if(a[i]<=b[j]){
 	    temp[k++]=a[i++];
          }else{
	    temp[k++]=b[j++];
	   }
     }
    /* while(i<lena){
          temp[k++]=a[i++];
     }
     while(j<lenb){
          temp[k++]=b[j++];
     }*/
     return temp;
 }
 printarray(int*a,int len){
     for(int i=0;i<len; i++){
        printf("%d\t",a[i]);
     }
     printf("\n");
 }

