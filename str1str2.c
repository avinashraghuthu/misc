#include<stdio.h>
#include<conio.h>
main()
{ 
   int i,j=0;
   char str1[30],str2[30];
   printf("enter string1:");
   scanf("%s",str1);
   printf("enter string2:");
   scanf("%s",str2);
   printf("enter the index:");
   scanf("%d",&i);
    while(str2[j]!='\0')
   {
      str1[i]=str2[j];
      i++;
      j++;
   }
     if(str1[i]==' ')
      str1[i]='\0';
      puts(str1);
      getch();
}     
