#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct dict
{
	char * word;
	long number;
	int lenght;
};
void dict_convertion(int);
void word_copy(char *,char *);
int word_to_number(char *);
int char_convert(char);
void word_search(struct dict *,int,int);
main()
{
	int number;
	printf("enter the number");
	scanf("%d",&number);
	dict_convertion(number);
	getch();
}
int char_convert(char c)
{
	if(c>='a' && c<='c')
		return 2;
	else if(c>='d' && c<='f')
		return 3;
	else if(c>='g' && c<='i')
		return 4;
	else if(c>='j' && c<='l')
		return 5;
	else if(c>='m' && c<='o')
		return 6;
	else if(c>='p' && c<='s')
		return 7;
	else if(c>='t' && c<='w')
		return 8;
	else if(c>='x' && c<='z')
		return 9;
}
int word_to_number(char *str)
{
	int number=0,temp;
	while(*str)
	{
		temp=char_convert(*str);
		number=number*10+temp;
		str++;
	}
	return number;
}
void word_copy(char *src,char *dest)
{
	while(*dest++ = *src++);
}
void dict_convertion(int num)
{
	FILE *fp;
	struct dict *objects;
	int count=1,index=0,i=0;
	char c,*temp;
	temp=malloc(sizeof(char));
	fp=fopen("dictionary.txt","r");
	if(fp==NULL)
	  printf("file cannot be opened");
    else
	{
      do
        {
	       c=fgetc(fp);
	       if(c==' ' || c=='\n' || c==EOF)
	        {   
		       temp[i]='\0';
			   if(count==1)
				   objects=(struct dict *)malloc(sizeof(struct dict));
			   else
				    objects=realloc(objects,count*sizeof(struct dict));
			   objects[index].word=(char *)malloc(sizeof(char));
			   word_copy(temp,objects[index].word);
			   objects[index].number=word_to_number(objects[index].word);
			   objects[index].lenght=i;
			  // printf("%d\n",objects[index].number);
		       i=0;
			   index++;
		       count++;
	       }
	      else
	       {
		      temp[i]=c;
		      i++;
           }
        }while(c!=EOF);
		
	}
	word_search(objects,count,num);
}
void word_search(struct dict *objects,int count,int num)
{
	int index=0,temp,len=0,diff=0,no_word=-1;
	temp=num;
	while(temp!=0)
	{
		temp=temp/10;
		len++;
	}
	while(index!=count)
	{
		if(len>objects[index].lenght)
		{
			index++;
			continue;
		}
		else
		{
			temp=objects[index].number;
			diff=objects[index].lenght-len;
			while(diff!=0)
			{
				temp=temp/10;
			    diff--;
			}
			if(temp==num)
			{
				printf("%s\n",objects[index].word);
		        no_word=1;
			}
			index++;
		}
	}
	if(no_word==-1)
	printf("no word");
}