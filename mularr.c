#include<stdio.h>
#include<conio.h>
main()
{
  int l[20],r[20],i,n,sum=1;
  printf("enter the size arr");
  scanf("%d",&n);
  printf("enter the arr:");
  for(i=0;i<n;i++)
  scanf("%d",&l[i]);
  for(i=n-1;i>=0;i--)
   {
    sum=sum*l[i];
    r[i]=sum;
   }
  
   for(i=1;i<n;i++)
    {
      l[i]=l[i]*l[i-1];
    }
     
   r[0]=r[1];
   for(i=1;i<n-1;i++)
    {
     r[i]=(l[i-1]*r[i+1]);
    }
    r[n-1]=l[n-2];
    printf("\n");
    for(i=0;i<n;i++)
    printf("%d ",r[i]);
    getch();
}
    
    
   
   
   
