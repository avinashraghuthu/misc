#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	char data;
	struct node * link;
};
struct node * create(char *);
struct node * add_node(struct node *,int);
struct node * find_mid_node(struct node *);
void display(struct node *);
main()
{
   struct node * head;
   char *number;
   int n,key;
   printf("enter the size:");
   scanf("%d",&n);
   number=malloc(n*sizeof(char));
   printf("enter the element to be added:");
   scanf("%d",&key);
   printf("enter the number:");
   scanf("%s",number);
   head=create(number);
   head=add_node(head,key);
   display(head);
   getch();
}
struct node * create(char * str)
{
	struct node *head,*temp,*new_node,*mid_node;
	int count=0,mid=0;
	head=malloc(sizeof(struct node));
	head->data=*str;
	head->link=NULL;
	temp=head;
	mid_node=head;
	str++;
    while(*str)
	{
		new_node=malloc(sizeof(struct node));
		new_node->data=*str;
		new_node->link=NULL;
		temp->link=new_node;
		temp=new_node;
	    str++;
		count++;
		while(mid!=(count/2))
			{
				mid_node=mid_node->link;
				mid++;
		    }
	}
	new_node->link=mid_node;
	return head;
}
void display(struct node *head)
{
	struct node *temp1=head,*temp2=head->link;
	printf("After the new node is added with link to  mid node:\n");
	while(temp1->data <temp2->data)
	{
		printf("%c->",temp1->data);
		temp1=temp1->link;
		temp2=temp2->link;
	}
    printf("%c->",temp1->data);
	printf("%c->",temp2->data);
}
struct node * add_node(struct node *head,int k)
{
	struct node *new_node,*prev,*curr;
	int node_added=-1;
	char key;
	key=k+'0';
	new_node=malloc(sizeof(struct node));
	new_node->data=key;
	new_node->link=NULL;
	prev=head;
	curr=head->link;
	if(head->data>key)
	{
		new_node->link=head;
		head=new_node;
		node_added=1;
	}
	else
	{
		while(curr->data > prev->data)
		{
			if(key>curr->data)
			{
				prev=curr;
				curr=curr->link;
			}
			else
			{
				prev->link=new_node;
				new_node->link=curr;
				node_added=1;
				break;
			}
		}
	}
	if(node_added==-1)
	{
		prev->link=new_node;
		new_node->link=curr;
	}
   return find_mid_node(head);
}

struct node * find_mid_node(struct node *head)
{
	struct node * prev,*mid_node,*curr;
	int count=0,mid=0;
    prev=head;
	mid_node=head;
	curr=prev->link;

	while(prev->data < curr->data)
	{
	   count++;
	   while(mid!=(count/2))
			{
				mid_node=mid_node->link;
				mid++;
		    }
	      prev=curr;
		  curr=curr->link;
	}
	prev->link=mid_node;
	return head;
}