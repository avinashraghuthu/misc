#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
main()
{
  char str[20];
  int i,j=0,n,sum=0;
  printf("enter the binary:");
  gets(str);
  n=strlen(str);
  for(i=n-1;i>=0;i--,j++)
  {
   if(str[i]=='1')
      sum+=(1*(pow(2,j)));
  }
  printf("%d",sum); 
  getch();
}
