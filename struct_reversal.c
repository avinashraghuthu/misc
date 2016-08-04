#include<stdio.h>
#include<conio.h>
struct std
{
	char *name;
	int age;
};
void rev(struct std *,int );
void main()
{
	int n,m;
	int i=0;
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
		printf("enter the age:");
		scanf("%d",&det[i].age);
	}
	rev(det,m);
	getch();
}
void rev(struct std *det,int m)
{
	struct std temp;
	int i,j;
	printf("before structure reversal:\n");
	for(i=0;i<m;i++)
	{
		printf("str%d: %s",i,det[i].name);
		printf("		age%d: %d\n",i,det[i].age);
	}
	for(i=0,j=(m-1);i<j;i++,j--)
	{
		temp.name=det[i].name;
		det[i].name=det[j].name;
		det[j].name=temp.name;
		temp.age=det[i].age;
		det[i].age=det[j].age;
		det[j].age=temp.age;
	}
	printf("after structure reversal: \n");
	for(i=0;i<m;i++)
	{
		printf("str%d: %s",i,det[i].name);
		printf("		age%d: %d\n",i,det[i].age);
	}
}