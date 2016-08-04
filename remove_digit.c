#include<stdio.h>
#include<conio.h>
void rem(char *,int);
void main()
{
	char *str;
	int n;
	printf("enter the size of stirng:");
	scanf("%d",&n);
	str=malloc(n*sizeof(char));
	printf("enter the string: ");
	scanf("%s",str);
	rem(str,n);
	getch();
}
void rem(char *str,int n)
{
	int i=0,j;
	while(str[i]!='\0')
	{
		while(str[i]>=48 && str[i]<=58)
		{
			for(j=i;j<n;j++)
			str[j]=str[j+1];
			n--;
		}
		i++;
	}
	printf("%s",str);
	
}
