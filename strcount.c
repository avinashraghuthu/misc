/*if input as aaabbcc then the output should be a3b2c2*/
#include<stdio.h>
#include<conio.h>
void count(char *);
main()
{
    char *s;
    int n;
	printf("enter the size of string:");
	scanf("%d",&n);
    s=malloc(n*sizeof(char));
	printf("enter the string:");
	scanf("%s",s);
	count(s);
	getch();
} 
void count(char *str)
{
      int i=0,j=0,c,flag=0;
      while(*(str+i)!='\0')
      {
        c=0;
        while(*(str+i)==*(str+j))
        {
           c++;
           j++;
        }
        if(c>1)
         {
           *(str+i+1)=c+'0';
           *(str+i+2)=str[j];
           i=i+2;
           if(c>2)
           flag=1;
         }
        else
         {
             if(flag==1)
                  str[j-1]=str[j];
                i++;     
         }
      }  
      printf("%s",str);
}      
