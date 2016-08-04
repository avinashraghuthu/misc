//Given an array of length n is sorted. Part of the array is reversed, fix the array
//1 2 4 3 5 6 8 7 --------> 1 2 3 4 5 6 7 8  
#include<stdio.h>
#include<conio.h>
void fix(int *,int);
void main()
{
	int *arr,n,i;
	printf("enter the size of arr:");
	scanf("%d",&n);
	arr=malloc(n*sizeof(int));
	printf("enter the values:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	fix(arr,n);
	getch();
}
void fix(int *arr,int n)
{
	int t=0,i=0,j=0,k;
	while(i<=(n+1))
	{
		if(arr[i]<arr[i+1] || (t==1 && (i+1)==n))
		{
			i++;
			j++;
			if(t==1)
			{
				k=i;
				for(i=i-1,j=j-1;j<i;j++,i--)
				{
					t=arr[i];
					arr[i]=arr[j];
					arr[j]=t;
				}
				t=0;
				i=k;
				j=k;
			}
		}
		else
		{
			i++;
			t=1;
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
