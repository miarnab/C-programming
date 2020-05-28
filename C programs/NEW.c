//including the header files
#include<stdio.h> 
#include<stdlib.h>
int main(){
	int ar[10],i,j,t,n;
	printf("\nEnter the number of elements in the array:");
	scanf("%d",&n);
	printf("\nEnter the %d elements in the array:",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
	}
	//sorting in the descending order using bubblesort technique
	for(i=0;i<n;i++)
	{
		for(j=0;j<(n-i)-1;j++)
		{
			if(ar[j]<ar[j+1])
			{
				t=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=t;
			}
		}
	}
	//displaying the sorted array
	printf("\nThe sorted array is:");
	for(i=0;i<n;i++)
	{
		printf("\n%d",ar[i]);
	}
}