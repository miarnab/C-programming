#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[20],i,flag=0,p,n,s;
	printf("\nEnter the number of elements in the array:\n");
	scanf("%d",&n);
	printf("\nEnter the %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	//searching by Linear Search technique
	printf("\nEnter the number to search:\n");
	scanf("%d",&s);
	for(i=0;i<n;i++){
		if(s==a[i]){
			flag=1;
			p=i;
		}
	}
	if(flag==1){
		printf("\nSearch Successful;Found at position %d\n",p);
	}
	else
	printf("\nSearch Unsuccessful;Not Found\n");
}