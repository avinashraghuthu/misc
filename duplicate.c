//to compress dupl characters  like accommdate--------->acomdate
#include<stdio.h>
#include<conio.h>
#include<string.h>
void dupl(char *);
main()
{
     char *str,n;
     printf("enter the size:");
     scanf("%d",&n);
     str=malloc(n*sizeof(char));
     printf("enter the string:");
     scanf("%s",str);
     dupl(str);
     getch();
}
void dupl(char *str)
{
     int n,i,j,k;
     n=strlen(str);
     for(i=0,j=i+1;i<n;i++,j++)
     {                                       
        while(str[i]==str[j])
         {
         for(k=j;k<n;k++)
           str[k]=str[k+1];
             n--;
          }  
        } 
     printf("%s",str);
}      
