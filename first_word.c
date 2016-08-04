#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char * first(char *);
void main()
{
 char *p;
 char *str;
 int n;
 printf("enter the size:");
 scanf("%d",&n);
 str=malloc(n*sizeof(char));
 printf("enter str and to exit press ctrl+z:");
 fflush(stdin);
 scanf("%[^z]s",str);
 p=first(str);
 if(*p==NULL)
	 printf("there are no words!");
 else
 {
 printf("address:%ld\n",p);
 printf("startng letter of first word:%c",*p);
 }
 getch();
}
char * first(char *str)
{
   char *i;
   int j=0;
    while((str[j]==' ' ||str[j]=='\t' || str[j]=='\n') && str[j]!='\0')
    {
      str++;
    }
      i=&str[j];
      return i;
}