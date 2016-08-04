#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
       char data;
    struct   node *link;
}*p=NULL;  
void split(char *);
void add(char);
void display(struct node *);
main()
{
	  char *str;
	  int n;
      printf("enter the size:");
      scanf("%d",&n);
	  str=(char *)malloc(n*sizeof(char));
	  printf("enter the string");
	  fflush(stdin);
	  scanf("%[^\n]s",str);
	  split(str);
	  display(p);
	  getch();
}
void split(char *str)
{
	int i=0;
	while(str[i]!='\0')
	{
		add(str[i]);
		i++;
	}
}
void add(char n)
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
         r=(struct node *)malloc(sizeof(struct node));
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
		printf("%c\n",temp->data);
		temp=temp->link;
	}
}

                              
