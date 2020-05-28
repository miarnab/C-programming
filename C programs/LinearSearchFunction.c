#include<stdio.h>
#include<conio.h>
int SequentialSearch(int[],int,int);
int main(){
	int x[20],n,i,p,key;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	printf("\nEnter the element to be searched:\n");
	scanf("%d",&key);
	p=SequentialSearch(x,n,key);
	if(p==-1)
	printf("\nThe search is unsuccessful\n");
	else
	printf("\n%d is found at location %d",key,p);
	}
	int SequentialSearch(int a[],int n,int k){
		int i;
		for(i=0;i<n;i++){
			if(k==a[i])
			return i;
		}
		return (-1);
	}
