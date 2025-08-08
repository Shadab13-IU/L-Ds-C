#include<stdio.h>
#include<stdlib.h>
int* indices(int*,int,int*,int);
void printa(int*);
int main(int argc, char* argv[]){
	int a[]={2,7,11,15};
	int al=sizeof(a)/sizeof(a[0]);
	int b[]={};
	int t=9;
	indices(a,al,b,t);
	printa(b);
	return 0;
}
int* indices(int* a,int len,int *b,int t){
	for(int i=0; i<len; i++){
		for(int j=i+1; j<len; j++){
			if(a[i]+a[j]==t){
				b[0]=i;
				b[3]=j;
				return b;
			}
		}
	}
}
void printa(int* c){
	for(int i=0; i<3; i++){
		printf("%d\t",c[i]);
	}
	printf("\n");
}	
