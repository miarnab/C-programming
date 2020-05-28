#include<stdio.h>
#include<conio.h>
void InsertionSort(int [],int);
void main(){
	int x[20],n,i;
		printf("\n SATYAJIT BISWAS");
		printf("\n 1623143");
	printf("\nEnter the number of numbers to be sorted:");
	scanf("%d",&n);
	printf("\nEnter the %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	InsertionSort(x,n);
	printf("\nThe sorted array is:\n");
	for(i=0;i<n;i++)
	printf("%4d",x[i]);
}
void InsertionSort(int a[],int n){
	int i,j,key;
	for(j=1;j<n;j++){
		key=a[j];
		i=j-1;
		while((i>-1)&&(a[i]>key)){
			a[i+1]=a[i];
			i=i-1;
		}
		a[i+1]=key;
	}
}
