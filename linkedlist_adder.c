#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct   node *link;
};  
struct node * add(char *);
struct node * adder(struct node *,struct node *);
void display(struct node *);
main()
{
	  char *str1,*str2;
	  int n1,n2;
	  struct node *p,*q,*r;
      printf("enter the size of num1  :");
      scanf("%d",&n1);
	  str1=malloc(n1*sizeof(char));
	  printf("enter the num1   :");
	  scanf("%s",str1);
	  printf("enter the size of num2  :");
	  scanf("%d",&n2);
	  str2=malloc(n2*sizeof(char));
	  printf("enter the num2   :");
	  scanf("%s",str2);
	  p=add(str1);
	  q=add(str2);
	  r=adder(p,q);
	  display(r);
	  getch();
}
struct node * add(char *s)
{
    struct node *temp,*r,*head=NULL;
	while(*s)
	{
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=*s-'0';
        temp->link=NULL;
		if(head==NULL)
        {
                 
                head=temp;
				r=head;

        }
       else
       {
         r->link=temp;
         r=temp;
       } 
	  s++;
	}
	return head;
}
void display(struct node *q)
{
	struct node *temp=q;
	printf("After ADDITION:\n");
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->link;
	}
}
struct node * adder(struct node *h1,struct node *h2)
{
	struct node *end,*carry,*t1,*t2,*new_node,*h3=NULL,*temp=NULL;
	int n1=0,n2=0,sum,diff=0;
	t1=h1;
	t2=h2;
	while(t1!=NULL)
	{
		n1++;
		t1=t1->link;
	}
	while(t2!=NULL)
	{
		n2++;
		t2=t2->link;
	}
	if(n1>n2 || n1==n2)
	{
		t1=h1;
		t2=h2;
		diff=n1-n2;
	}
	else if(n2>n1)
	{
		t1=h2;
		t2=h1;
		diff=n2-n1;
	}
    if(diff!=0)
	{
		new_node=malloc(sizeof(int));
		new_node->data=t1->data;
		new_node->link=NULL;
		h3=new_node;
	    end=new_node;
	    carry=new_node;
		temp=h3;
		diff--;
		t1=t1->link;
		while(diff!=0)
		{
			new_node=malloc(sizeof(int));
			new_node->data=t1->data;
			new_node->link=NULL;
			temp->link=new_node;
			temp=new_node;
			end=new_node;
			if(new_node->data!=9)
				  carry=new_node;
	        t1=t1->link;
			diff--;	
		}
	}
	while(t1!=NULL && t2!=NULL)
	{
		sum=t1->data+t2->data;
		new_node=malloc(sizeof(int));
		new_node->link=NULL;
		if(h3==NULL)
			{
				h3=new_node;
				end=new_node;
				carry=new_node;
		    }
		else
		{
			end->link=new_node;
			end=new_node;
		}
		if(sum>9)
		  {
			sum=sum%10;
			new_node->data=sum;
			if(carry->data==9 || (end==h3))//if carry->data is 9 i.e in head, new node is to be created if a carry is obtained eg: 708 + 299
			{
				new_node=malloc(sizeof(int));
				new_node->data=1;
				new_node->link=carry;
				h3=new_node;
				while(carry!=end)
				{
					carry->data=0;
				    carry=carry->link;
				}
			}
			else
			{
				carry->data++;
				carry=carry->link;
				while(carry!=end)
				{
					carry->data=0;
					carry=carry->link;
				}
			}
		  }
		else if(sum==9)//dont move carry pointer,but move end pointer
		{
			new_node->data=sum;
		}
		else//move carry pointer and end pointer
		{
			new_node->data=sum;
			if(h3!=end)
			{
			   carry=new_node;
			}
		}
		t1=t1->link;
		t2=t2->link;
	}
	return h3;
}



                              
