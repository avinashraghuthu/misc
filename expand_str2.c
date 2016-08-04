#include<stdio.h>
#include<conio.h>
void expand(char *,int,int);
void main()
{
	char *str;
	int n,m;
	printf("enter the size of stirng:");
	scanf("%d",&m);
	printf("enter the repetition num:");
	scanf("%d",&n);
	str=malloc(n*m*sizeof(char));
	printf("enter the string: ");
	scanf("%s",str);
	expand(str,m,n);
	getch();
}
void expand(char *str,int m,int n)
{
	int i,t,c;
	t=n;
	c=m*n;
	str[c]='\0';
	while((t-1)!=0)
	{
		for(i=1;i!=(m+1);i++)
			str[--c]=str[m-i];
		t--;
	}
	printf("%s",str);
}
        