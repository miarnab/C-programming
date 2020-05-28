#include<stdio.h>
#include<stdlib.h>
int main(){
	int ar[20],i,j,t,n;
	//declaring an array
	printf("\n Enter the numberof elements in the array:");
	scanf("%d",&n);
	printf("\n Enter the %d element in the array:",n);
	for(i=0;i<n;i++){
		scanf("%d",ar[i]);
	}
	//sorting in descending order using bubblesort technique
	for(i=0;i<n;i++){
		for(j=0;j<(n-i)-1;j++){
			if(ar[i]<ar[j+1]){
				t=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=t;
			}
		}
	}
	//display the sorted array
	printf("\n The sorted array is:");
	for(i=0;i<n;i++){
		printf("\n%d",ar[i]);
	}
}
