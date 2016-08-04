#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
       int data;
    struct   node *link;
}*p=NULL;  
void add(int);
void split(int);
void display(struct node *);
main()
{
	  int n;
      printf("enter the num:");
      scanf("%d",&n);
	  split(n);
	  display(p);
	  getch();
}
void split(int n)
{
	if(n==0)
		return;
	else
	{
		split(n/10);
		add(n%10);
	}
}
void add(int n)
{
    struct node *temp,*r;
     if(p==NULL)
     {
                temp=(struct node *)malloc(sizeof(struct node));
                temp->data=n;
                temp->link=NULL;
                p=temp;
     }
     else
     {
         temp=p;
         while(temp->link!=NULL)
         temp=temp->link;
         r=malloc(sizeof(struct node));
         r->data=n;
         r->link=NULL;
         temp->link=r;
     }
}
void display(struct node *q)
{
	struct node *temp=q;
	printf("After linked list creation:\n");
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->link;
	}
}

                              
