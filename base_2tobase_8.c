#include<stdio.h>
#include<conio.h>
#include<math.h>
void convert(int [],int);
int todecimal(int []);
main()
{
 int *arr,n,i;
 printf("enter arr size");
 scanf("%d",&n);
 arr=malloc(n*sizeof(int));
 printf("enter the binary arr:");
 for(i=0;i<n;i++)
  {
	 scanf("%d",&arr[i]);
  }
  convert(arr,n);
  getch();
}
void convert(int arr[],int n)
{
	int temp[3],*res;
	int i,j=(n-1),k,c,n1;
	 if(n%3==0)
		 n1=(n/3);
	  else
		n1=((n/3)+1);
	 k=n1;
	 res=malloc(n1*sizeof(int));
	while(j>=0)
	{
	 for(i=2;i>=0 && j>=0;i--,j--)
	  {
		temp[i]=arr[j];
	  }
      c=todecimal(temp);
	  res[--k]=c;
	  for(i=0;i<3;i++)
		  temp[i]=0;
	}
	for(i=0;i<n1;i++)
     printf("%d",res[i]);
}
int todecimal(int temp[])
{
	int i,j,s=0;
/*	for(i=0;i<3;i++)
	{
		printf("%d",temp[i]);
		printf("\n");
	}*/
	for(i=2,j=0;i>=0;i--,j++)
		s+=((temp[i])*pow(2,j));
	return s;
}