#include<stdio.h>
#include<conio.h>
char * word(char *);
main()
{
	char *str,*p;
	int n,i;
	printf("enter the size of stirng:");
	scanf("%d",&n);
	str=malloc(n*sizeof(char));
	printf("enter the string: ");
	fflush(stdin);
	scanf("%[^\n]s",str);
	 p=word(str);
	 if(*p==' ' || *p=='\t')
		 printf("No words in string");
	 else
	 {
		 printf("address:%ld\n",p);
		 printf("starting letter of last word:%c",*p);
	 }
	 getch();
}
char  * word(char *str)
{
	int i=0,j=0;
	char *p;
    while(str[i]!='\0')
	{
		if(str[i]==' ' ||str[i]=='\t' || str[i]=='\n')
		{
			i++;
		if(str[i]!='\0' && str[i]!=' ' && str[i]!='\t')
		j=i;
		}
		else
		i++;
	}
	p=&str[j];
	return p;
}