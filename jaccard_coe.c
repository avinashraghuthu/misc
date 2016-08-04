#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list
{
	char **term_list;
	int list_len;
};
struct list k_gram_split(char *,int,int);
float jaccard_coe(struct list,struct list,int);
main()
{
	int query_len,ind_len,k_gram;
	char *query_term,*index_term;
    struct list que_ob,ind_ob;
	float jacc_coe;
	printf("enter the query term len:");
	scanf("%d",&query_len);
	query_term=malloc(query_len*sizeof(char));
	printf("enter the query term:");
	scanf("%s",query_term);
	printf("enter the index term len:");
	scanf("%d",&ind_len);
	index_term=malloc(ind_len*sizeof(char));
	printf("enter the index term:");
	scanf("%s",index_term);
	printf("enter the k-gram:");
	scanf("%d",&k_gram);
	que_ob=k_gram_split(query_term,query_len,k_gram);
	ind_ob=k_gram_split(index_term,ind_len,k_gram);
	jacc_coe=jaccard_coe(que_ob,ind_ob,k_gram);
	printf("jaccord_coe = %f",jacc_coe);
	getch();
}
struct list k_gram_split(char *term,int len,int k_gram)
{
	struct list ob;
	int i=0,j=0,count=0;
	ob.list_len=len-k_gram+1;
	ob.term_list=(char **)malloc(ob.list_len*sizeof(char *));
	for(i=0;i<ob.list_len;i++)
		ob.term_list[i]=(char *)malloc(k_gram*sizeof(char));
	for(i=0;i<=len-k_gram;i++)
	{
		count=0;
		for(j=i;count<k_gram;j++,count++)
		{
			ob.term_list[i][count]=term[j];
		}
		ob.term_list[i][count]='\0';
	}
	return ob;
}
float jaccard_coe(struct list que_ob,struct list ind_ob,int k_gram)
{
	int i,j,k=0;
	int intersect_term_count=0,union_term_count;
	int equal_flag=1;
	float jacc_coe;
	for(i=0;i<que_ob.list_len;i++)
	{
		for(j=0;j<ind_ob.list_len;j++)
		{
			k=0;
			equal_flag=1;
			while(k < k_gram)
			{
				if(que_ob.term_list[i][k]!=ind_ob.term_list[j][k])
				{
      				 equal_flag=0;
					 break;
				}
				k++;
			}
			if(equal_flag==1)
				intersect_term_count++;
		}
	}
	union_term_count=((que_ob.list_len + ind_ob.list_len));

	jacc_coe= ((float)intersect_term_count)/(union_term_count);
	return jacc_coe;
}