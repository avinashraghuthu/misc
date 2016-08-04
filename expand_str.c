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
	int i,t;
	str[m*n]='\0';
	while(m!=0)
	{
		t=n;
		for(i=1;t!=0;t--,i++)
			str[m*n-i]=str[m-1];
		m--;
	}
	printf("%s",str);
}
        