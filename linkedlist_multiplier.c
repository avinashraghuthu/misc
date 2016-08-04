#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    long data;
    struct   node *link;
};
struct result
{
	struct node *start;
	struct node *end;
};
struct node * linkedlist(int );
struct result  adder(struct node *,struct node *);
struct result  multiply(struct node *,struct node *);
struct result  partial_multiply(struct node *,int);
void display(struct node *);
main()
{
	  int num1,num2;
	  struct node *p,*q;
	  struct result r;
	  printf("enter the num1   :");
	  scanf("%ld",&num1);
	  printf("enter the num2   :");
	  scanf("%ld",&num2);
	  p=linkedlist(num1);
	  q=linkedlist(num2);
	  r=multiply(p,q);
	  display(r.start);
	  getch();
}
struct node * linkedlist(int num)
{
    struct node *temp,*r,*head=NULL;
	int sum=0;
	do
	{
		sum=num%10;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=sum;
		if(head==NULL)
		{
				head=temp;
		        temp->link=NULL;
		}
		else
		{
				temp->link=head;
				head=temp;
		}
		num=num/10;
	}while(num!=0);
        
	return head;
}
void display(struct node *q)
{
	struct node *temp=q;
	printf("After Multiplication:\n");
	while(temp!=NULL)
	{
		printf("%ld",temp->data);
		temp=temp->link;
	}
}
struct result adder(struct node *h1,struct node *h2)
{
	struct node *end,*carry,*t1,*t2,*new_node,*h3=NULL,*temp=NULL;
	struct result res_ptr;
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
	res_ptr.start=h3;
	res_ptr.end=end;
	return res_ptr;
}
struct result  multiply(struct node *h1,struct node *h2)
{

   struct node *list1=h1,*list2=h2,*temp_list1,*temp_list2,*head1,*head2,*zero_node;
   struct result adder_ptr1,adder_ptr2;
   int  len1=0,len2=0,sum1,sum2;
   while(list1!=NULL)
   {
	   len1++;
	   list1=list1->link;
   }
   while(list2!=NULL)
   {
	   len2++;
	   list2=list2->link;
   }
   if(len1>len2 || len1==len2)//length is calc bcoz say if num is  2  * 123456789 we need to do only one pass,if it is not calc, we have to do 9 passes
   {
	  list1=h1;
	  list2=h2;
   }
   else
   {
	   list1=h2;
	   list2=h1;
   }
   zero_node=(struct node *)malloc(sizeof(struct node));
   zero_node->data=0;
   zero_node->link=NULL;
   if((len1==len2) && len1==1)
   {   
	   if(list1->data==0 || list2->data==0)
		   zero_node->data=0;
	   else
           zero_node->data=(list1->data*list2->data);
	   adder_ptr1.start=adder_ptr1.end=zero_node;

   } 
   else
   {
	   adder_ptr1=partial_multiply(list1,list2->data);
       list2=list2->link;
	   while(list2!=NULL)
	   {
		 head1=adder_ptr1.start;
	     adder_ptr1.end->link=zero_node;
	     adder_ptr2=partial_multiply(list1,list2->data);
         head2=adder_ptr2.start;
	     adder_ptr1=adder(head1,head2);
         list2=list2->link;
	   }
	}
	   return adder_ptr1;
}

struct  result  partial_multiply(struct node *list1,int n)
{
       struct node *head1,*head2,*zero_node;
	   int sum1,sum2;
	   struct result partial_adder_ptr;
	   zero_node=(struct node *)malloc(sizeof(struct node));
       zero_node->data=0;
       zero_node->link=NULL;
	   
	   sum1=(list1->data * n * 10);
	   head1=linkedlist(sum1);
	   list1=list1->link;
	   sum2=list1->data*n;
	   head2=linkedlist(sum2);
	   partial_adder_ptr=adder(head1,head2);

	   list1=list1->link;
	   while(list1!=NULL)
	   {
		   sum2= n * list1->data;
		   head2=linkedlist(sum2);
		   head1=partial_adder_ptr.start;
		   partial_adder_ptr.end->link=zero_node;
		   partial_adder_ptr=adder(head1,head2);
		   list1=list1->link;
	   }
   
	   return partial_adder_ptr;
}
                              

