#include<stdio.h>
#include<conio.h>
void Bubblesort(int [],int);
int	 main(){
	int x[20],n,i;
	printf("\n SATYAJIT BISWAS ");
	printf("\n 1623143");
	printf("\nEnter the number of numbers to be sorted:");
	scanf("%d",&n);
	printf("\nEnter %d elements \n",n);
	for(i=0;i<n;i++)
	scanf("%d",&x[i]);
	Bubblesort(x,n);
	printf("\nThe sorted array is\n");
	for(i=0;i<n;i++)
	printf("%4d\n",x[i]);
}
void Bubblesort(int a[],int n)
{
	int temp,pass,i;
	for(pass=0;pass<n-1;pass++)
	{
		for(i=0;i<n-pass-1;i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	}
}
