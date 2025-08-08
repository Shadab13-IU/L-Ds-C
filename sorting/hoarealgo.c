#include<stdio.h>
#include<stdlib.h>
/*int hoarealgo(int*,int,int);
void printarray(int*,int);
void swap(int* ,int*);
int main(int argc,char* argv[]){
	int a[]={3,4,2,8,7,1,5};
     	int len=sizeof(a)/sizeof(a[0]);
     	printarray(a,len);
     	hoarealgo(a,0,len-1);
    	printarray(a,len);
     	return 0;
}
int hoarealgo(int* a,int low,int high){
	int pivot=low;
     	int i=low+1,j=high;
     	while(i<j){
         	while(i<=j && a[i]<=a[pivot])i++;
         	while(i<=j && a[j]>a[pivot])j--;
         	if(i<=j){
           		swap(&a[i],&a[j]);
         	}
     	}
     	swap(&a[pivot],&a[j]);
     	return j;
}
void swap(int*x,int*y){
     int temp=*x;
     *x=*y;
     *y=temp;
}
void printarray(int* a,int len){
     for(int i=0; i<len; i++){
         printf("%d\t",a[i]);
     }
     printf("\n");
}*/
 // lo mutoalgo to do this sorting
/*int hoarealgo(int*,int,int);
void printarray(int*,int);
void swap(int* ,int*);
int main(int argc,char* argv[]){
	int a[]={3,4,2,8,7,1,5};
     	int len=sizeof(a)/sizeof(a[0]);
     	printarray(a,len);
     	hoarealgo(a,0,len-1);
    	printarray(a,len);
     	return 0;
}
int hoarealgo(int* a,int low,int high){
	int pivot=high;
     	int i=-1,temp;
     	for(int j=0; j<=high; j++){
		if(a[j]<a[pivot]){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	i++;
     	swap(&a[i],&a[pivot]);
     	return i;
}
void swap(int*x,int*y){
     int temp=*x;
     *x=*y;
     *y=temp;
}
void printarray(int* a,int len){
     for(int i=0; i<len; i++){
         printf("%d\t",a[i]);
     }
     printf("\n");
}*/
//int partition(int*,int,int);
void mergewithin(int*,int);
void printarray(int*,int);
void swap(int* ,int*);
//void quicksort(int*,int,int);
/*int main(int argc,char* argv[]){
	int a[]={3,4,2,8,7,1,5};
     	int len=sizeof(a)/sizeof(a[0]);
     	printarray(a,len);
     	quicksort(a,0,len-1);
    	printarray(a,len);
     	return 0;
}
int partition(int* a,int low,int high){
	int pivot=low;
     	int i=low+1,j=high;
     	while(i<j){
         	while(i<=j && a[i]<=a[pivot])i++;
         	while(i<=j && a[j]>a[pivot])j--;
         	if(i<=j){
           		swap(&a[i],&a[j]);
         	}
     	}
     	swap(&a[pivot],&a[j]);
     	return j;
}*/
void swap(int*x,int*y){
     int temp=*x;
     *x=*y;
     *y=temp;
}
void printarray(int* a,int len){
     for(int i=0; i<len; i++){
         printf("%d\t",a[i]);
     }
     printf("\n");
}
/*void quicksort(int* a,int low,int high){
	if(low<high){
		int pivot=partition(a,low,high);
		quicksort(a,low,pivot-1);
		quicksort(a,pivot+1,high);
	}
}*/
int main(int argc,char* argv[]){
	int a[]={2,4,6,10,15,20,3,7,18,30,35};
     	int len=sizeof(a)/sizeof(a[0]);
     	printarray(a,len);
     	mergewithin(a,len);
    	printarray(a,len);
     	return 0;
}
void mergewithin(int*a,int len){
	int i=0,j=1;
	while(j<len && a[j]>a[j-1])j++;
	int temp;
	while(i<j){
	while(a[i]<a[j])i++;
		temp=a[j];
		int k=j-1;
		while(k>=i){
		a[k+1]=a[k];
		k--;
		}
		a[i]=temp;
		i++;
		j++;
	}
}


