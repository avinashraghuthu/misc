//shhifting an char array 12345--->34512
#include<stdio.h>
#include<conio.h>
#include<string.h>
void shift(char *,int);
main()
{
     char *str,n,s;
     printf("enter the size:");
     scanf("%d",&n);
     printf("enter no times to be shift:");
     scanf("%d",&s);
     str=malloc(n*sizeof(char));
     printf("enter the string:");
     scanf("%s",str);
     shift(str,s);
     getch();
}
void shift(char *str,int s)
{
     char t;
     int i=0,n;
      n=strlen(str);
     while(s!=0)
     {
             t=str[0];
            for(i=0;i<n;i++)
            str[i]=str[i+1];
            s--;
             str[i-1]=t;
     }
     str[i+1]='\0';
     printf("%s",str);
}                      
