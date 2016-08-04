 //Given a string and two indexes I and J remove all the characters from I to J both
// included from the string. Ex: Hello, 2,3 output should be heo
#include<stdio.h>
#include<stdlib.h>
void delindex(char *,int,int,int);
main()
{
   
	char *str;
    int n,a,b;
	printf("enter the size of string:");
	scanf("%d",&n);
    str=malloc(n*sizeof(char));
	printf("enter the string:");
	scanf("%s",str);
   printf("enter the starting index:");
   scanf("%d",&a);
   printf("enter the ending index:");
   scanf("%d",&b);
   delindex(str,a,b,n);
   getch();
}
void delindex(char *str,int i,int j,int n)
{
	if(i>=0 && j<n)
	{
	 while(str[j+1]!='\0')
       {
          str[i]=str[j+1];
           i++;
           j++;
       }
       str[i]='\0';
	}
	else 
		{
			printf("enter index wrong");
	        return;
	 }
 puts(str);
}             
