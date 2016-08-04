#include<stdio.h>
#include<conio.h>
void ar(int);
main()
{
	int n;
	printf("enter the num:");
	scanf("%d",&n);
	ar(n);
	getch();
}
void ar(int n)
{
	if(n<=0)
		return;
	else
	{
		ar(n/2);
		printf("%d",n%2);
	}
}