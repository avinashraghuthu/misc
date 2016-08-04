#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	char data;
	struct node * link;
};
struct node * create(char *);
struct node * remove_dupl(struct node *);
void display(struct node *);
main()
{
   struct node * head;
   char *number;
   int n;
   printf("enter the size:");
   scanf("%d",&n);
   number=malloc(n*sizeof(char));
   printf("entre the number:");
   scanf("%s",number);
   head=create(number);
   head=remove_dupl(head);
   display(head);
   getch();
}
struct node * create(char * str)
{
	struct node *head,*temp,*new_node;
	head=malloc(sizeof(struct node));
	head->data=*str;
	head->link=NULL;
	temp=head;
	str++;
	while(*str)
	{
		new_node=malloc(sizeof(struct node));
		new_node->data=*str;
		new_node->link=NULL;
		temp->link=new_node;
		temp=new_node;
	    str++;
	}
	return head;
}
void display(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%c",temp->data);
		temp=temp->link;
	}
}
struct node * remove_dupl(struct node *head)
{
	struct node * base_node,*curr_node,*check_node;
	base_node=head;
	while(base_node!=NULL)
	{
		curr_node=base_node;
		check_node=curr_node->link;
		while(check_node!=NULL)
		{
			if(base_node->data==check_node->data)
			{
				while(check_node!=NULL && base_node->data==check_node->data)
					check_node=check_node->link;
				curr_node->link=check_node;
			}
			else
			{
				curr_node=curr_node->link;
				check_node=check_node->link;
			}
		}
		base_node=base_node->link;
	}
	return head;
}