#include<stdio.h>
#include<conio.h>
main()
{
	int numbers[100];
	int i=0,j,k=0,t=0,n;
	printf("enter the size :");
	scanf("%d",&n);
	j=n-1;
	printf("enter the array:");
	for(i=0;i<n;i++)
		scanf("%d",&numbers[i]);
    while(k<j)
	{
        while(numbers[k]==0 || numbers[k]==1)
            k+=1;
        while(numbers[j]==2)
            j-=1;
        if(k<j)
		{
            t=numbers[j];
            numbers[j]=numbers[k];
            numbers[k]=t;
		}
	}
	i=0;
    while(i<j)
	{
        while(numbers[i]==0)
            i+=1;
        while(numbers[j]==1)
            j-=1;
        if(i<j)
		{
            t=numbers[j];
            numbers[j]=numbers[i];
            numbers[i]=t;
		}
	}
	for(i=0;i<n;i++)
		printf("%d",numbers[i]);
	getch();
}