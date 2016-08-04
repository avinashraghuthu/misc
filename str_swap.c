#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void swap(char *,char *);
main()
{
 int n1,n2;
 char *str1,*str2;
 printf("enter the size of str:");
 scanf("%d%d",&n1,&n2);
 str1=(char *)malloc((n1+n2)*sizeof(char));
 str2=(char *)malloc((n1+n2)*sizeof(char));
 printf("enter the arr1:");
  scanf("%s",str1);
 printf("enter the string2:");
 scanf("%s",str2);
 printf("before swapping\n");
  printf("str1:   %s\n",str1);
 printf("str2:   %s\n",str2);
 swap(str1,str2);
  printf("After swapping\n");
     printf("str1:  %s\n",str1);
	 printf("str2:  %s",str2);
 getch();
}
void swap(char *str1,char *str2)
{
     int t;
     int i,j,n=0;
	 int n1=0,n2=0;
	 while(*str1)
	 {
		 n1++;
		 str1++;
	 }
	 str1-=n1;
	 while(*str2)
	 {
	  n2++;
	  str2++;
      }
	  str2-=n2;
      for(i=0,j=0;str1[i]!='\0' || str2[j]!='\0';i++,j++)
	  {
		  t=*(str1+i);
		  *(str1+i)=*(str2+j);
		  *(str2+j)=t;
	  }
	 
}