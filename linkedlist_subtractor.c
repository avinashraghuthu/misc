#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct   node *link;
};  
struct node * linkedlist(char *);
struct node * subtr(struct node *,struct node *);
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
	  p=linkedlist(str1);
	  q=linkedlist(str2);
	  r=subtr(p,q);
	  display(r);
	  getch();
}
struct node * linkedlist(char *s)
{
    struct node *temp,*r,*head=NULL;
	while(*s)
	{
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=*s;
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
	printf("After subtraction:\n");
	while(temp!=NULL)
	{
		printf("%c",temp->data);
		temp=temp->link;
	}
}
struct node * subtr(struct node *h1,struct node *h2)
{
	struct node *end,*borrow,*t1,*t2,*new_node,*h3=NULL,*temp=NULL,*temp1;
	int n1=0,n2=0,len_diff=0,borrow_sum;
    int negative=0;
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
		len_diff=n1-n2;
	}
	else if(n2>n1)
	{
		t1=h2;
		t2=h1;
	 	len_diff=n2-n1;
	    negative=-1;
	}
    if(len_diff!=0)
	{
		new_node=malloc(sizeof(int));
		new_node->data=t1->data;
		new_node->link=NULL;
		h3=new_node;
	    end=new_node;
	    borrow=new_node;
		temp=h3;
		len_diff--;
		t1=t1->link;
		while(len_diff!=0)
		{
			new_node=malloc(sizeof(int));
			new_node->data=t1->data;
			new_node->link=NULL;
			temp->link=new_node;
			temp=new_node;
			end=new_node;
			if(new_node->data!='0')
				  borrow=new_node;
	        t1=t1->link;
			len_diff--;	
		}
	}
	if(t1->data < t2->data && n1==n2)
	{   
		temp=t1;
		t1=t2;
		t2=temp;
	    negative=-1;
	}
	else if(t1->data==t2->data && n1==n2)
	{   
		while(t1!=NULL && t1->data==t2->data)
		{
			t1=t1->link;
			t2=t2->link;
		}
		if(t1!=NULL && t1->data < t2->data)
	    {   
		negative=-1;
		temp=t1;
		t1=t2;
		t2=temp;
	    }
	}
	if(t1==NULL && t2==NULL)
		{
			h3=malloc(sizeof(struct node));
			h3->data='0';
			h3->link=NULL;
			return h3;
	    }
	while(t1!=NULL && t2!=NULL)
	{
		//diff=t1->data-t2->data;
		new_node=malloc(sizeof(int));
		new_node->link=NULL;
		if(h3==NULL)
			{
				h3=new_node;
				end=new_node;
				borrow=new_node;
		    }
	
		else
		{
			end->link=new_node;
			end=new_node;
		}
		if(t1->data < t2->data)
		  {
			 borrow_sum=10+(t1->data-'0');
			 new_node->data=((borrow_sum-(t2->data-'0'))+'0');
			
				borrow->data--;
				if(h3->data=='0')
				    {
						h3=borrow->link;
				        borrow=h3;
					}
				else
					borrow=borrow->link;
		        while(borrow!=end)
				        {
				         	borrow->data='9';
				        	borrow=borrow->link;
				         }	
		
		}
		else if(t1->data==t2->data)//dont move borrow pointer,but move end pointer
		{
			new_node->data='0';
		}
		else//move borrow pointer and end pointer
		{
			borrow_sum=((t1->data-'0')-(t2->data-'0'))+'0';
			new_node->data=borrow_sum;
			if(h3!=end)
			{
			   borrow=new_node;
			}
		}
		t1=t1->link;
		t2=t2->link;
	}	
	if(negative==-1)
	{
		new_node=malloc(sizeof(char));
		new_node->data='-';
		new_node->link=h3;
		h3=new_node;
	}
     return h3;
}


                              
