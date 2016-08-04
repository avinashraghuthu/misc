#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void display(char *str[],char *v[],int,int,int,int);
main()
{
      int m,n,i,j,k;
      char **str,**v;
      printf("enter no of rows:");
      scanf("%d",&m);
      printf("enter no of col:");
      scanf("%d",&n);
      str=(char **)malloc(sizeof(char *)*m);
      for(i=0;i<m;i++)
      str[i]=(char *)malloc(n*sizeof(char));
      v=(char **)malloc(sizeof(char *)*m);
     for(k=0;k<m;k++)
     v[k]=(char *)malloc(n*sizeof(char));
      fflush(stdin);
      printf("enter string");
      for(i=0;i<m;i++)
      scanf("%s",str[i]);
      display(str,v,m,n,0,0);
	   for(i=0;i<m;i++)
	 {
		 for(j=0;j<n;j++)
			 printf("%c",str[i][j]);
		 printf("\n");
	 }
	  getch();
}            
void display(char **str,char **v,int m,int n,int i,int j)
{
    
     if(i>=0 && j>=0 && i<m && j<n)
     {
             if(str[i][j]=='1')
             {
				 str[i][j]=' ';
                     display(str,v,m,n,i+1,j);
                     display(str,v,m,n,i,j+1);
                     display(str,v,m,n,i-1,j);
                     display(str,v,m,n,i,j-1);
             }
     }
    
}


     
     
     
