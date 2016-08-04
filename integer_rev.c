#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void int_rev(int [],int);
main()
{
 int n,i;
 int *arr;
 printf("enter the size of arr:");
 scanf("%d",&n);
 arr=(int *)malloc(n*sizeof(int));
 printf("enter the arr:");
 for(i=0;i<n;i++)
 {
  scanf("%d",&arr[i]);
 }
 int_rev(arr,n);
 getch();
}
void int_rev(int *arr,int n)
{
     int t;
     int i,j;
      for(i=0,j=(n-1);i<j;i++,j--)
	  {
		  t=arr[i];
		  arr[i]=arr[j];
		  arr[j]=t;
	  }
	 for(i=0;i<n;i++)
     printf("%d",arr[i]);
}