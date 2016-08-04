//function which take unsigned num and print it using %c
#include<stdio.h>
#include<conio.h>
void func(int);
main()
{
  int n;
  printf("enter the num:");
  scanf("%d",&n);
  func(n);
  getch();
}
void func(int n)
{     
      int rem;
      if(n==0)
      return;
      else
      {
                 rem=(n%10);
                 n=n/10;
                 func(n);
                 printf("%c",(rem+'0'));
      }
}      
