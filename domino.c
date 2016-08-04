#include<stdio.h>
#include<conio.h>
void s_domino(int,int,int,int,int);
void build_domino(int,int,int,int,int,int);
main()
{
	int up,down,left,right;
	int row,col;
	printf("enter the values of up,down,left,right:");
	scanf("%d %d %d %d",&up,&down,&left,&right);
	printf("enter the row and col length");
	scanf("%d %d",&row,&col);
	build_domino(up,down,left,right,row,col);
	getch();
}
void build_domino(int up,int down,int left,int right,int row,int col)
{
	int i,j;
	int t_up,t_down;
     for(i=0;i<row;i++)
		 {
			 if(i%2!=0)
			 {
				 t_up=down;
				 t_down=up;
			 }
			 else
			 {
				 t_up=up;
				 t_down=down;
			 }
			 s_domino(t_up,t_down,left,right,col);
			 if(i!=(row-1))
			   for(j=0;j<4*col-1;j++)
				 printf("-");
	     }
}

void s_domino(int up,int down,int left,int right,int col)
{
	int temp=0,i,t;
	int tleft,tright;
	printf("\n");
	for(temp=0;temp<3;temp++)
	   {
		 for(i=0;i<col;i++)
	       {
			 if(i%2!=0)
			 {
				 tright=left;
				 tleft=right;
				 
			 }
			 else
			 {
				 tright=right;
				 tleft=left;
			 }
	         if(temp%2!=0)
	         {
	           printf("%d",tleft);
	           printf(".");
	           printf("%d",tright);
	         }
	         else
	         {
		       printf(".");
		       if(temp==0)
			     printf("%d",up);
		        else
			     printf("%d",down);
		       printf(".");
	         }
			 if(i==(col-1))
				 printf("\n");
			 else
				 printf("|");
	       }
		 if(temp==3)
			 printf("\n");

	   }
}