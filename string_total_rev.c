#include<stdio.h>
#include<conio.h>
void rev(char *,int);
main()
{
	char *str;
	int n,i;
	printf("enter the size:");
	scanf("%d",&n);
	str=malloc(n*sizeof(char));
	printf("enter the string");
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		scanf("%c",&str[i]);
	}
	str[i]='\0';
	printf("Before swapping:\n");
	printf("%s\n",str);
	rev(str,n);
	getch();
}
void rev(char *str,int n)
{
	int i=0,j=0,c=0;
	char t;
	while(str[c]!='\0')
	{
		while(str[j]!=' ' && str[j]!='\0')
			j++;
		c=j+1;
		for(j=(j-1);i<j;i++,j--)
		{
			t=str[i];
			str[i]=str[j];
			str[j]=t;
		}
		i=c;
		j=c;
	}
	for(i=0,j=(n-1);i<j;i++,j--)
	{
		t=str[i];
		str[i]=str[j];
		str[j]=t;
	}
	printf("After swapping\n");
	printf("%s",str);
}