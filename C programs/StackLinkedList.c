#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node *stack;
int IsEmpty(stack);
stack Push(stack,int);
stack Pop(stack);
void Display(stack);
int main()
{
	stack s=NULL;
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
		printf("\n Enter your choice:");
		fflush(stdin);
		ch=getchar();
		switch(ch)
		{
			case '1':
					printf("\n Enter the element to be pushed:");
					scanf("%d",&x);
					s=Push(s,x);
					break;
			case '2':
					s=Pop(s);
					break;
			case '3':
					Display(s);
					break;
			case '4':
					break;
			default:printf("\n\nWrong choice!Try again\n");
		}
	}
}
int IsEmpty(stack s)
{
	if(s==NULL)
	return 1;
	else
	return 0;
	}
 stack Push(stack s,int x)
 {
 	stack temp;
 	temp=(stack)malloc(sizeof(struct node));
 	if(temp==NULL)
 	{
	 	printf("\nOut of memory space");
	 	exit(0);
 	}
 	temp->info=x;
 	temp->next=s;
 	s=temp;
 	return s;
 }
 stack Pop(stack s)
 {
 	stack temp;
 	int x;
 	if(IsEmpty(s))
 	{
	 	printf("\n Stack empty");
	 	exit(0);
 	}
 	temp=s;
 	x=s->info;
 	printf("\nPopped element is:%d",x);
 	s=s->next;
 	free(temp);
 	return s;
 }
 void Display(stack s)
 {
 	stack ptr;
 	ptr=s;
 	printf("\nThe elements in the stack are:\n");
 	if(ptr==NULL)
 	{
	 	printf("\nStack empty\n\n");
	 	return;
 	}
 	while(ptr!=NULL)
 	{
	 printf("%d \n",ptr->info);
	 ptr=ptr->next;
 	}
 }
