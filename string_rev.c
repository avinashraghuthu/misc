#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void char_rev(char *);
main()
{
 int n;
 char *str;
 printf("enter the size of arr:");
 scanf("%d",&n);
 str=(char *)malloc(n*sizeof(char));
 printf("enter the arr:");
  scanf("%s",str);
 char_rev(str);
 getch();
}
void char_rev(char *str)
{
     int t;
     int i,j,n=0;
	 while(*str)
	 {
		 n++;
		 str++;
	 }
	 str-=n;
      for(i=0,j=(n-1);i<j;i++,j--)
	  {
		  t=*(str+i);
		  *(str+i)=*(str+j);
		  *(str+j)=t;
	  }
     printf("%s",str);
}