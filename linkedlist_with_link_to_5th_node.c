#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	char data;
	struct node * next_link;
	struct node * node5_link;
};
struct node * linkedlist(char *);
struct node * add_node(struct node  *,int);
struct node * remove_node(struct node *,int);
struct node * find_node5(struct node *);
void display(struct node *);
main()
{
	char *num;
	int new_num;
    struct node *temp,*result;
	int len;
	printf("enter the length of number :");
	scanf("%d",&len);
	num=malloc((len+1)*sizeof(char));
	printf("enter the number: ");
	scanf("%s",num);
	printf("enter the  digit u want to add :");
	scanf("%d",&new_num);
	temp=linkedlist(num);
	result=add_node(temp,new_num);
	display(result);
	printf("\nenter the node to be deleted: ");
	scanf("%d",&new_num);
	temp=remove_node(result,new_num);
	display(temp);
	getch();
}
struct node * linkedlist(char *str)
{
	struct node *new_node,*temp,*head,*node5_ptr;
	int count=0;
	new_node=malloc(sizeof(struct node));
	new_node->data=*str;
	new_node->next_link=NULL;
	new_node->node5_link=NULL;
	head=new_node;
	node5_ptr=head;
	temp=head;
	str++;
	while(*str)
		{
			new_node=malloc(sizeof(struct node));
			new_node->data=*str;
			new_node->next_link=NULL;
			new_node->node5_link=NULL;
			temp->next_link=new_node;
			count++;
		    if(count>=5)
		    {
			node5_ptr->node5_link=new_node;
			node5_ptr=node5_ptr->next_link;
		    }
			temp=new_node;
			str++;
		}
         return head;
}
void display(struct node *head)
{
	struct node *temp=head,*node5=head->node5_link;
	while(temp!=NULL)
	{
		printf("%c",temp->data);
		temp=temp->next_link;
	}
	printf("\n");
	printf("nodes which are linked with 5 link\n");
	while(node5!=NULL)
	{
		printf("%c",node5->data);
		node5=node5->next_link;
	}
}
struct node * add_node(struct node *head,int k)
{
	struct node *prev,*curr,*new_node,*node5;
	int node_added=-1;
	char key=k+'0';
	prev=head;
	curr=head->next_link;
	node5=head->node5_link;
	new_node=malloc(sizeof(struct node));
	new_node->data=key;
	new_node->next_link=NULL;
	new_node->node5_link=NULL;
	if(key<prev->data)
	{
		new_node->next_link=head;
		new_node->node5_link=head->node5_link;
		node_added=1;
		head=new_node;
	}
	else
	{
		while(curr!=NULL)
		{
			if(key>curr->data)
			{
				if(node5!=NULL && key>node5->data)//if key is greater than the node5 val we go to that part
				{
					prev=node5;
					curr=prev->next_link;
					node5=node5->node5_link;
				}
				else
				{
					prev=curr;
					curr=curr->next_link;
				}
			}
			else
			{
				prev->next_link=new_node;
				new_node->next_link=curr;
				node_added=1;
			    break;
			}
		}
	}
	if(node_added==-1)
	{
		prev->next_link=new_node;
		new_node->next_link=curr;
	}
	return find_node5(head);
}
struct node * find_node5(struct node *head)
{
	struct node *node5,*curr;
	int count=0;
	node5=head;
	curr=head;
	while(node5!=NULL)
	{
		if(count>=5)
		{
			curr->node5_link=node5;
			curr=curr->next_link;
			node5=node5->next_link;
		}
		else
			node5=node5->next_link;
		count++;
	}
	return head;
}
struct node * remove_node(struct node *head,int k)
{
	struct node *prev,*curr,*node5;
	char key=k+'0';
	int deleted=-1;
	prev=head;
	curr=head->next_link;
	node5=head->node5_link;
	   if(head->data==key)
		{
			head=curr;
			deleted=1;
		}
		else
		{
			while(curr!=NULL)
			{
				if(key>curr->data)
				{
					if(node5!=NULL && key>node5->data)
					{
						prev=node5;
						curr=node5->next_link;
						node5=node5->node5_link;
					}
					else
					{
						prev=curr;
						curr=curr->next_link;
					}
				}
				else
				{
					curr=curr->next_link;
					prev->next_link=curr;
					break;
				}
			}
		}

        return find_node5(head);					
}