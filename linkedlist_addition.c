#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *link;
}*p1=NULL,*p2=NULL,*sum=NULL;
void add(struct node **,int);
void display(struct node *);
struct node * rev(struct node *);
void addr(struct node *,struct node *);
main()
{
	int n;
	do
	{
		printf("enter the num and to exit -11 for linkedlist 1:  ");
		scanf("%d",&n);
		if(n!=-11)
		add(&p1,n);
	}while(n!=-11);
	printf("\n");
	do
	{    
		printf("enter the num and to exit -11 for linkedlist 2:  ");
		scanf("%d",&n);
		if(n!=-11)
		add(&p2,n);
	}while(n!=-11);
	printf("num1:    ");
	display(p1);
	printf("num2     ");
	display(p2);
	addr(p1,p2);
	sum=rev(sum);
	printf("sum:     ");
	display(sum);
	getch();
}
void add(struct node **p,int n)
{
	struct node *r,*temp;
	if((*p)==NULL)
	{
		temp=malloc(sizeof(struct node));
		temp->data=n;
		temp->link=NULL;
		*p=temp;
	}
	else
	{
		temp=*p;
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
    printf("\n");
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
void addr(struct node *p1,struct node *p2)
{
	int n1=0,n2=0,t=0;
	p1=rev(p1);
	p2=rev(p2);
	while(p1!=NULL && p2!=NULL)
	{
		t=p1->data+p2->data+n1;
		n2=t%10;
			add(&sum,n2);
		n1=t/10;
		p1=p1->link;
		p2=p2->link;
	}
	if(n1!=0 &&(p1==NULL && p2==NULL))
		add(&sum,n1);
	while(p1!=NULL)
	{
		if(n1==0)
		 add(&sum,p1->data);
		else
			add(&sum,n1+p1->data);
		 p1=p1->link;
		 n1=0;
	}
	while(p2!=NULL)
	{
		if(n1==0)
		add(&sum,p2->data);
		else
			add(&sum,n1+p2->data);
		p2=p2->link;
		n1=0;
	}
}