//0,1 array sorting
#include<stdio.h>
#include<conio.h>
main()
{
      int a[20],n,i,j,t;
      printf("enter the size:");
      scanf("%d",&n);
      printf("enter 0 and 1:");
      for(i=0;i<n;i++)
      scanf("%d",&a[i]);
      i=0;
      j=n-1;
      while(i<j)
      {
        while(a[i]==0)
        i++;
        while(a[j]==1)
        j--;
      if(i<j)    
      {       
       t=a[i];
       a[i]=a[j];
       a[j]=t;
       }
      } 
       for(i=0;i<n;i++)
       printf("%d",a[i]);
       getch();
}
