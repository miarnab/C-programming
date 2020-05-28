#include<stdio.h>
#include<stdlib.h>
#define MAXQ 100
int front=0,rear=-1;
int items[MAXQ];
int IsEmpty();
int IsFull();
void Insert(int);
int Delete();
void Display();
int main()
{
	int x;
	
	char ch='1';
	printf("\n SATYAJIT BISWAS");
		printf("\n 1623143");
	while(ch!='4')
	{
		
		printf("\n 1-INSERT");
		printf("\n 2-DELETE");
		printf("\n 3-DISPLAT");
		printf("\n 4-EXIT");
		printf("\n Enter the user's choice:");
		fflush(stdin);
		ch=getchar();
		switch(ch)
		{
			case '1':
						printf("\n Enter the element to be inserted:");
						scanf("%d",&x);
						Insert(x);
						break;
			case '2':
						x=Delete();
						printf("\n Deleted element is %d \n",x);
						break;
			case '3':
						Display();
						break;
			case '4':
						break;
			default:
						printf("\nWrong choice:Try Again");
		}
	}
}
int IsEmpty()
{
	if(rear<front)
	return 1;
	else
	return 0;
}
int IsFull()
{
	if(rear==MAXQ-1)
	return 1;
	else
	return 0;
}
void Insert(int x)
{
	if(IsFull())
	{
		printf("\nQueue Full");
		return;
	}
	rear++;
	items[rear]=x;
}
int Delete()
{
	int x;
	if(IsEmpty())
	{
		printf("\n Queue Empty");
		exit(0);
	}
	x=items[front];
	front++;
	return x;
}
void Display()
{
	int i;
	if(IsEmpty())
	{
		printf("\nQueue Empty");
		return;
	}
	printf("\n Elements of the Queue are:\n");
	for(i=front;i<=rear;i++)
	printf("%10d\n",items[i]);
}
