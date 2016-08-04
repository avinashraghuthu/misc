//median of two sorted arrays
#include<stdio.h>
#include<conio.h>
void median(int *,int *,int,int);
main()
{
      int *a,*b,alen,n,blen,i;
      printf("enter the len of arr A,B:");
      scanf("%d %d",&n,&blen);
      alen=n+blen;
      a=malloc(alen*sizeof(int));
      b=malloc(blen*sizeof(int));
      printf("enter the elements of A:");
      for(i=0;i<n;i++)
      scanf("%d",&a[i]);
      printf("enter the elements of B:");
      for(i=0;i<blen;i++)
      scanf("%d",&b[i]);
      median(a,b,alen,blen);
      getch();
}
void median(int *a,int *b,int alen,int blen)
{
     int i,j=0,k;     
     int n=alen-blen;
      for(i=0;j<blen;i++)
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
      i=(alen/2);
      if(alen%2==0)
         printf("median=%d",(a[i]+a[i+1])/2);
       else
       printf("median=%d",a[i]);                  
      getch();
}      
