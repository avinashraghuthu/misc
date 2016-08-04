#include<stdio.h>
#include<conio.h>
void counter(char *);
main()
{
	char *str;
	int n;
	printf("enter the size of stirng:");
	scanf("%d",&n);
	str=malloc(n*sizeof(char));
	printf("enter the string: ");
	scanf("%s",str);
	counter(str);
	getch();
}
void counter(char *str)
{
	
	int v=0,c=0;
	while(*str)
	{
		if(*str=='a' || *str=='e' || *str=='i' || *str=='o' || *str=='u' ||*str=='A' || *str=='E' || *str=='I' || *str=='O' || *str=='U')
			v++;
		else
			if((*str>=97 && *str<=123) ||(*str>=65 && *str<=91))
			c++;
	    str++;
	}
	
	printf("no of vowels:%d",v);
	printf("\nno of cosonents:%d",c);
}