#include<stdio.h>
#include<stdlib.h>
int main(){
//Creation of the array
int ar[20],n,i;
printf("\tSATYAJIT BISWAS");
printf("\t 1623143");
printf("\nEnter the number of elements in the array:");
scanf("%d",&n);
printf("\nEnter the elements in the array:");
for(i=0;i<n;i++){
	scanf("\t%d",&ar[i]);
}
//Printing the inputed array
printf("\nThe inputed array is:");
for(i=0;i<n;i++){
	printf("\n\t\t\t%d\n",ar[i]);
}
}
