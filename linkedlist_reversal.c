#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *link;
}*p=NULL;
void add(int );
void display(struct node *);
struct node * rev(struct node *);
main()
{
	int n;
	do
	{
		printf("enter the num and to exit -11:  ");
		scanf("%d",&n);
		if(n!=-11)
		add(n);
	}while(n!=-11);
	display(p);
	printf("\n");
	p=rev(p);
	display(p);
	getch();
}
void add(int n)
{
	struct node *r,*temp;
	if(p==NULL)
	{
		temp=malloc(sizeof(struct node));
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
	while(q!=NULL)
	{
		printf("%d",q->data);
		q=q->link;
	}
}
struct node * rev(struct node *p)
{
	struct node *prev,*curr,*next;
	prev=p;
	curr=prev->link;
	next=curr->link;
	while(curr!=NULL)
	{
	
		curr->link=prev;
		prev=curr;
		curr=next;
		if(next!=NULL)
		next=next->link;
	}
	p->link=NULL;
	return prev;
}