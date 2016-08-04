#include<stdio.h>
#include<conio.h>
int word(char *);
main()
{
	char *str;
	int n,i,p;
	printf("enter the size of stirng:");
	scanf("%d",&n);
	str=malloc(n*sizeof(char));
	printf("enter the string: ");
	fflush(stdin);
	scanf("%[^\n]s",str);
	 p=word(str);
	 if(p==0)
		 printf("No words in string");
	 else
		 printf("word count:%d",p);
	 getch();
}
int word(char *str)
{
	int i=0,j=0,c=0,t=0;
    while(str[i]!='\0')
	{
		if(str[i]==' ' ||str[i]=='\t' || str[i]=='\n')
		{
			i++;
		  if(str[i]!='\0' && str[i]!=' ' && str[i]!='\t')
		  {
			j=i;
			c++;
			t=1;
		  }
	   }
		else
		{
			if(t==0)
			{
				c++;
				t=1;
			}
		    i++;
		}
	}
	return c;
}