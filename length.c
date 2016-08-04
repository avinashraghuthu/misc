#include<stdio.h>
#include<conio.h>
void len(char *);
main()
{
 int n;
 char *str;
 printf("enter the size:");
 scanf("%d",&n);
 str=malloc(n*sizeof(char));
 printf("enter str:");
 scanf("%s",str);
 len(str);
 getch();
}
void len(char *str)
{
 int i=0;
 while(*str)
 {
  i++;
  str++;
 }
 printf("%d",i);
}