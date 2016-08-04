#include<stdio.h>
#include<conio.h>
int ar(int [],int);
void t2comp(int [],int);
main()
{
	int n,*arr,c,i;
	arr=malloc(sizeof(int));
	printf("enter the num:");
	scanf("%d",&n);
	if(n>=0)
	{
	c=ar(arr,n);
	}
	else
		{
			c=ar(arr,-(n));
			t2comp(arr,c);
	    }
	for(i=0;i<c;i++)
		printf("%d",arr[i]);
	printf("\nlen:%d",c);
	getch();
}
int ar(int arr[],int n)
{
	int i,c,j,t;
	for(i=0;n>=1;i++)
	{
		arr[i]=(n%2);
		n=(n/2);
	}
	c=i;
	for(i=0,j=(c-1);i<j;i++,j--)
	{
		t=arr[i];
        arr[i]=arr[j];
		arr[j]=t;
	}
	
        return c;
}
void t2comp(int arr[],int c)
{
	int i=(c-1),t=0;
		while(arr[i]==1 && t!=1)
			{
				t=1;
				i--;
		    }
		while(i>=0 && t==1)
		{
			if(arr[i]==1)
				arr[i]=0;
			else
				arr[i]=1;
			i--;
		}
}