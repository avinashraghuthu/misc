//shhifting an char array 12345--->34512 usin an temp arr
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
     char *temp;
     int i=0,j,n,c=0;
     temp=malloc(s*sizeof(char));
      n=strlen(str);
      for(i=0;i<s;i++)
      temp[i]=str[i];
      temp[i]='\0';
      while(s!=0)
     {
            for(i=0;i<(n-c);i++)
            str[i]=str[i+1];
            c++;
            s--;
     }
     for(j=0;temp[j]!='\0';j++,i++)
     {
      str[i-1]=temp[j];
      }
     str[i]='\0';
     printf("%s",str);
}                      
