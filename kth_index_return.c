#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char index(char *,int );
main()
{
 char *str,c;
 int n,ind;
 printf("enter the size:");
 scanf("%d",&n);
 str=(char *)malloc(n*sizeof(char));
 printf("enter the str:");
 scanf("%s",str);
 printf("enter the index:");
 scanf("%d",&ind);
 c=index(str,ind);
 printf("%c",c);
 getch();
}
char index(char *str,int ind)
{
 int i=0;
 char c=NULL;
 while(str[i]!='\0')
 {
	 if(i==ind)
		 c=str[i];
	 i++;
 }
 if(c==NULL)
 {
	 printf("index is not in the range");
	 return NULL;
 }
 else
	 return c;
}