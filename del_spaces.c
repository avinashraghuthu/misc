// given a string with spaces like "hello world" remove all the spaces. 
//There can be multiple spaces in the string. this should be done without using extra string or array
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void delspace(char *);
main()
{
    char *s;
    int n,i,j,c=0;
	printf("enter the size of string:");
	scanf_s("%d",&n);
    s=malloc(n*sizeof(char));
	printf("enter the string:");
	for(i=0;i<n;i++)
	{
     fflush(stdin);
	scanf_s("%c",&s[i]);
    }
	s[i]='\0';
	delspace(s);
	//getch();
}	
void delspace(char *s)
{  
     int i,j,c=0;
     for(i=0;s[i]!='\0';i++)
      {
        if(s[i]!=' ')
        continue;
        else
        {
        while(s[i]==' ')
         {
          for(j=i;s[j+1]!='\0';j++)
          s[j]=s[j+1];
          c++;
         }
        }
      } 
        s[j-c+1]='\0';
        puts(s);
}
