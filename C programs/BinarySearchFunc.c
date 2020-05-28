#include<stdio.h>
#include<conio.h>
int BinarySearch(int [],int,int);
void main(){
	int x[20],n,i,p,key;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter %d elements in ascending order:\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&x[i]);
	printf("\nEnter the element to search:");
	scanf("%d",&key);
	p=BinarySearch(x,n,key);
	if(p==-1)
	printf("\nThe search is unsuccessful:\n");
	else
	printf("\n%d if found at location %d\n",key,p);
}
	int BinarySearch(int a[],int n,int k){
		int lo,hi,mid;
		lo=0;
		hi=n-1;
		while(lo<=hi)
		{
			mid=(lo+hi)/2;
			if(k==a[mid])
			return (mid);
			if(k<a[mid])
			hi=mid-1;
			else
			lo=mid+1;
		}
		return (-1);
	}