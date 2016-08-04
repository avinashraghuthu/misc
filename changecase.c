#include<stdio.h>
#include<conio.h>
void change(char *);
main()
{
	char *str;
	int n;
	printf("enter the size of stirng:");
	scanf("%d",&n);
	str=malloc(n*sizeof(char));
	printf("enter the string: ");
	scanf("%s",str);
	change(str,n);
	getch();
}
void change(char *str,int n)
{
	
	while(*str)
	{
		if(*str>=65 && *str<=91)
			*str+=32;
		else
			if(*str>=97 && *str<=123)
				*str-=32;
		str++;
	}
	str-=n;
	printf("%s",str);
}