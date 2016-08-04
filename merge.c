//MERGING TWO SOTRED ARRAYS
#include<stdio.h>
#include<conio.h>
main()
{
      int a[30],b[20],alen,n,blen,i,j=0,k;
      printf("enter the len of arr A,B:");
      scanf("%d %d",&n,&blen);
      alen=n+blen;
      printf("enter the elements of A:");
      for(i=0;i<n;i++)
      scanf("%d",&a[i]);
      printf("enter the elements of B:");
      for(i=0;i<blen;i++)
      scanf("%d",&b[i]);
      for(i=0;j<blen && i<n;i++)
      {
         if(a[i]<b[j])
          continue;
         else
         {
          for(k=(n-1);k>=i;k--)
          a[k+1]=a[k];
          n++;
          a[i]=b[j];
          j++;
         }
      }
	  while(j!=(blen))
	  {
		  a[i]=b[j];
		  j++;
		  i++;
	  }
      for(i=0;i<alen;i++)
      printf("%d ",a[i]);
      getch();
}      
