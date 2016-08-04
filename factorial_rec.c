#include<stdio.h>
#include<conio.h>
int fact(int );
main()
{
	int n;
	printf("enter the num:");
	scanf("%d",&n);
	printf("factorial:%d",fact(n));
	getch();
}
int fact(int n)
{
	if(n==1)
		return 1;
	else
		return n*fact(n-1);
}