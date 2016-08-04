#include<stdio.h>
#include<conio.h>
main()
{
      char str[30];
      int i,j;
      puts("enter the string:");
      scanf("%s",&str);
      puts("enter the starting index:");
      scanf("%d",&i);
      puts("enter the ending index");
      scanf("%d",&j);
      while(str[j+1]!='\0')
       {
          str[i]=str[j+1];
           i++;
           j++;
       }
       str[i]='\0';
       puts(str);
       getch();
}                  
