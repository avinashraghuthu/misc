#include<stdio.h>
#include<conio.h>
void map(char *,int);
void main()
{
	char *str;
	int n;
	printf("enter the size of stirng:");
	scanf("%d",&n);
	str=malloc(n*sizeof(char));
	printf("enter the string: ");
	scanf("%s",str);
	map(str,n);
	getch();
}
void map(char *str,int n)
{
   while(*str)
   { 
	   if(*str=='.' || *str==',' || *str=='\'')
		   *str='1';
	  else if(*str=='a' || *str=='b' || *str=='c')
		   *str='2';
	   else if(*str=='d' || *str=='e' || *str=='f')
		   *str='3';
	   else if(*str=='g' || *str=='h' || *str=='i')
		   *str='4';
	   else if(*str=='j' || *str=='k' || *str=='l')
		   *str='5';
	   else if(*str=='m' || *str=='n'|| *str=='o')
		   *str='6';
	   else if(*str=='p' || *str=='q'|| *str=='r' || *str=='s')
		   *str='7';
	   else if(*str=='t' || *str=='u' || *str=='v')
		   *str='8';
	   else if(*str=='w' || *str=='x' || *str=='y' || *str=='z')
		   *str='9';
     str++;
   }
   str-=n;
   printf("%s",str);
}
