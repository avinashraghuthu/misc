#include<stdio.h>
#include<conio.h.>
#include<stdlib.h>
typedef struct tree
{
       int val;
       struct tree *left;
       struct tree *right;
}node;
void insert(node **,int);
void intrav(node *);
void search(node *,int);
main()
{
      int n,v,s;
      node *head;
      head=(node *)malloc(sizeof(node));
      printf("enter val:");
      scanf("%d",&head->val);
      head->left=NULL;
      head->right=NULL;
      do
      {
        printf("1.add 2.display 3.exit:\n"); 
        scanf("%d",&n);
        switch(n)
        {
                 case 1:printf("enter the num:");
                         scanf("%d",&v);
                         insert(&head,v);
                         break;
                 case 2:intrav(head);
					 printf("\n");
                         break;
                 case 3: break;
         }
        }while(n!=3);
	  printf("enter the search element node val:");
	  scanf("%d",&s);
	  search(head,s);
         getch();
}
void insert(node **r,int v)
{
     if((*r)==NULL)
     {
                (*r)=(node *)malloc(sizeof(node));
                (*r)->val=v;
                (*r)->left=NULL;
                (*r)->right=NULL;
     }
     else
     {
         if((*r)->val>v)
           insert(&(*r)->left,v);
          else if((*r)->val<v)
            insert(&(*r)->right,v);
      }
}        
void intrav(node *temp)
{   
	 if(temp!=NULL)
     {
     intrav(temp->left);
      printf("%d",temp->val);
	  intrav(temp->right);
    }
}                                                    
void search(node *temp,int s)
{   
	 if(temp!=NULL)
     {
	   if(s<temp->val)
        search(temp->left,s);
	   if(temp->val==s)
	    {
          if(temp->left!=NULL)
              printf("left:%d\n",temp->left->val);
		  else
			  printf("left node is null\n");
    	  printf("root:%d\n",temp->val);
		  if(temp->right!=NULL)
		     printf("right:%d\n",temp->right->val);
		  else
			printf("right node  is null");
	   }
	  if(temp->val<s)
	 search(temp->right,s);
	 
     }

}               