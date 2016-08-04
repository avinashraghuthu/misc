#include<stdio.h>
#include<conio.h>
char bindex(char *,int,int);
main()
{
	char *str,c;
	int n,i;
	printf("enter the size:");
	scanf("%d",&n);
	str=malloc(n*sizeof(char));
	printf("enter the string");
		scanf("%s",str);
	printf("enter the index:");
	scanf("%d",&i);
	c=bindex(str,i,n);
	printf("%c",c);
	getch();
}
char bindex(char *str,int i,int n)
{
	if((n-i-1)>=0 && i>=0)
	return str[n-i-1];
	else
	{
		printf("not in range");
		return NULL;
	}
}
		

