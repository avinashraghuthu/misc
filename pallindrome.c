#include<stdio.h>
#include<conio.h>
#include<string.h>
void pallin(char *);
main()
{
    char *str,n;
    printf("enter the size: ");
    scanf("%d",&n);
    str=malloc(n*sizeof(char));
    printf("enter the string: ");
    scanf("%s",str);
    pallin(str);
    getch();
}
void pallin(char *str)
{
     int n,i,j,c=1;
     n=strlen(str);
     for(i=0,j=(n-1);i<j;i++,j--)
     {
                                 if(str[i]!=str[j])
                                  c=0;
     }
     if(c==1)
     printf("%s is pallindrome",str);
     else
     printf("%s is not a pallimdrome",str);
}                                    
    
