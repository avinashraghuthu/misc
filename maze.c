#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void output(char **,int n,int m);
void display(char **,int,int,int,int);
main()
{
	char **a;
	int n=0,m=0,i,j;
	printf("enter number of rows and columns:");
	scanf("%d%d",&n,&m);
	a=(char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++)
	  a[i]=(char *)malloc(m*sizeof(char));
	fflush(stdin);
	printf("enter input array:");
	for(i=0;i<n;i++)
	{
      gets(a[i]);
	}
		output(a,n,m);
		getch();
}
	void output(char **a,int n,int m)
	{
     int i,j,k,p,q,x;
     char **c;
	 p=(2*n+1);
	 q=(4*m+1);
	 c=(char **)malloc(p*sizeof(char *));
	 for(i=0;i<p;i++)
	  c[i]=(char *)malloc(q*sizeof(char));
	
	i=0;
	 while(i<p)
	 {
		if(i%2==0)
	     {
		 j=0;
		 while(j<q)
			 c[i][j++]='-';
		 c[i][j]='\0';
 		}
		i++;
	 }

	
	 i=0;k=0;
	 while(i<p)
	{
		if(i%2!=0)
		{
			j=0;x=0;
		  while(j<q)
		   {
		     c[i][j++]='|';
			 if(j==q)
				 break;

		     c[i][j++]=' ';
		     c[i][j++]=a[k][x++];
			 c[i][j++]=' ';	
		   }
		  c[i][j]='\0';
		  k++;
	    }
		i++;
	}
     display(c,p-1,q-1,1,2);
       for(i=0;i<p;i++)
	 {
		 for(j=0;j<q;j++)
			 printf("%c",c[i][j]);
		 printf("\n");
	 }
}
void display(char **str,int m,int n,int i,int j)
{
    
     if(i>=0 && j>=0 && i<m && j<n)
     {
             if(str[i][j]=='1')
             {    
				 str[i][j]=' ';
				    str[i+1][j]=' ';
				    display(str,m,n,i+2,j);
				    str[i][j+2]=' ';
                    display(str,m,n,i,j+4);  
                     str[i-1][j]=' ';
                     display(str,m,n,i-2,j);
                     str[i][j-2]=' ';
                     display(str,m,n,i,j-4);
                     
             }
     }
    
} 
      
      
	
	
