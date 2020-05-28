#include<stdio.h>
#include<conio.h>
void ShellSort(int [],int);
void main(){
	int a[50],i,n;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter the %d elements:\n",n);
	for(i=0;i<n;i++)
	scanf("%d",a[i]);
}
void ShellSort(int a[],int n){
	int i,j,inc,temp;
	inc=(int)(n/2)-1;
	while(inc>0){
		for(i=inc;i<=n-1;i++){
			temp=a[i];
			j=i;
			while(j>=inc&& a[j-inc]>temp){
				a[j]=a[j-inc];
				j=j-inc;
			}
			a[j]=temp;
		}
		inc=inc/2;
	}
}