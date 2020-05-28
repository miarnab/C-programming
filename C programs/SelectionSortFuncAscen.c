#include<stdio.h>
#include<stdlib.h>
void SelectionSort(int [],int);
void main(){
	int x[20],n,i;
	printf("\n SATYAJIT BISWAS");
	printf("\n 1623143");
	printf("\nEnter the number of elements to be sorted:");
	scanf("%d",&n);
	printf("\nEnter the %d elements:",n);
	for(i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	SelectionSort(x,n);
	printf("\nThe sorted array is: \n");
	for(i=0;i<n;i++){
		printf("%4d",x[i]);
	}
}
	void SelectionSort(int a[],int n){
		int i,pos,j,large;
		for(i=n-1;i>0;i--){
			large=a[0];
			pos=0;
			for(j=1;j<=i;j++){
				if(a[j]>large){
					large=a[j];
				pos=j;
			}
		}
		a[pos]=a[i];
		a[i]=large;
		}
	}
