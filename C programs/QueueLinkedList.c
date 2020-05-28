#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node *queueType;
queueType front=NULL,rear=NULL;
int IsEmpty();
void Insert(int);
int Delete();
void Display();
void main()
{
	int x;
	char ch='1';
	printf("\n SATYAJIT BISWAS");
		printf("\n 1623143");
	while(ch!='4')
	{
		printf("\n 1-INSERT");
		printf("\n 2-DELETE");
		printf("\n 3-DISPLAY");
		printf("\n 4-QUIT");
		printf("\n Enter your choice:");
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
					printf("\n The deleted element is %d\n",x);
					break;
			case '3':
					Display();
					break;
			case '4':
					break;
			default:printf("\n\nWrong choice!Try again\n");
		}
	}
}
int IsEmpty()
{
	if(front==NULL)
	return 1;
	else
	return 0;
	}
 void Insert(int x)
 {
 	queueType temp;
 	temp=(queueType)malloc(sizeof(struct node));
 	if(temp==NULL)
 	{
	 	printf("\nOut of memory space");
	 	exit(0);
 	}
 	temp->info=x;
 	temp->next=NULL;
 	if(rear==NULL)
 	front=temp;
 	else
 	rear->next=temp;
 	rear=temp;;
 }
 int Delete()
 {
 	queueType temp;
 	int x;
 	if(IsEmpty())
 	{
	 	printf("\n Queue empty");
	 	exit(0);
 	}
 	temp=front;
 	x=temp->info;
 	front=temp->next;
 	if(front==NULL)
 	rear=NULL;
 	free(temp);
 	return x;
 }
 void Display()
 {
 	queueType ptr;
 	ptr=rear;
 	if(ptr==NULL)
 	{
 		printf("\n Queue Empty\n\n");
 		return;
 	}
 	printf("\nThe elements in the queue are:\n");
 	for(ptr=front;ptr!=NULL;ptr=ptr->next)
 	{
	 printf("%5d\n",ptr->info);
 	}
 }
 
