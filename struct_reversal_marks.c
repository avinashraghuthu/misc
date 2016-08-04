#include<stdio.h>
#include<conio.h>
struct std
{
	char *name;
	int marks[6];
};
void rev(struct std *,int );
void main()
{
	int n,m;
	int i=0,j;
	struct std *det;
	printf("enter no of struct you want:");
	scanf("%d",&m);
	det=(struct std *)malloc(m*sizeof(struct std));
	for(i=0;i<m;i++)
	{
		printf("enter the str size:");
		scanf("%d",&n);
		det[i].name=malloc(n*sizeof(char));
		printf("enter str:");
		scanf("%s",det[i].name);
		printf("enter the six sub marks:");
		for(j=0;j<6;j++)
		scanf("%d",&det[i].marks[j]);
	}
	rev(det,m);
	getch();
}
void rev(struct std *det,int m)
{
	struct std temp;
	int i,j,k;
	printf("before structure reversal:\n");
	for(i=0;i<m;i++)
	{
		printf("str%d: %s\n",i,det[i].name);
		for(k=0;k<6;k++)
		printf("sub%d: %d  ",(k+1),det[i].marks[k]);
		printf("\n");
	}
	printf("\n");
	for(i=0,j=(m-1);i<j;i++,j--)
	{
		temp.name=det[i].name;
		det[i].name=det[j].name;
		det[j].name=temp.name;
		for(k=0;k<6;k++)
		{
		 temp.marks[k]=det[i].marks[k];
		 det[i].marks[k]=det[j].marks[k];
		 det[j].marks[k]=temp.marks[k];
		}
	}
	printf("after structure reversal: \n");
	for(i=0;i<m;i++)
	{
		printf("str%d: %s\n",i,det[i].name);
		for(k=0;k<6;k++)
		printf("sub%d: %d  ",(k+1),det[i].marks[k]);
		printf("\n");
	}
}