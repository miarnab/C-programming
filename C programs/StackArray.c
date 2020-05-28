#include<stdio.h>
#include<stdlib.h>
#define MAXSTK 100
int top=-1;
int items[MAXSTK];
int IsEmpty();
int IsFull();
void Push(int);
int Pop();
void Display();
int main()
{
	int x;

	char ch='1';
		printf("\n SATYAJIT BISWAS");
		printf("\n 1623143");
	while(ch!='4')
	{
		
		printf("\n 1-PUSH");
		printf("\n 2-POP");
		printf("\n 3-DISPLAY");
		printf("\n 4-EXIT");
		printf("\n Enter the user's choice:");
		fflush(stdin);
		ch=getchar();
		switch(ch)
		{
			case '1':
						printf("\n Enter the element to be pushed:");
						scanf("%d",&x);
						Push(x);
						break;
			case '2':
						x=Pop();
						printf("\n Popped element is %d \n",x);
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
	if(top==-1)
	return 1;
	else
	return 0;
}
int IsFull()
{
	if(top==MAXSTK-1)
	return 1;
	else
	return 0;
}
void Push(int x)
{
	if(IsFull())
	{
		printf("\nStack Full");
		return;
	}
	top++;
	items[top]=x;
}
int Pop()
{
	int x;
	if(IsEmpty())
	{
		printf("\n Stack Empty");
		exit(0);
	}
	x=items[top];
	top--;
	return x;
}
void Display()
{
	int i;
	if(IsEmpty())
	{
		printf("\nStack Empty");
		return;
	}
	printf("\n Elements of the Queue are:\n");
	for(i=top;i>=0;i--)
	printf("%10d\n",items[i]);
}
