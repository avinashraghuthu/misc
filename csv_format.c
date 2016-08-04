#include<stdio.h>
#include<conio.h>
void   csv_parser();
void  csv_format(int [],int);
main()
{
	csv_parser();
	getch();
}
void csv_parser()
{
	int no_of_fields=0,current_field=0,length=0;
	int *length_of_fields;
    int i;
	char c;
	FILE *fp;
	fp=fopen("sample_csv.csv","r");
	if(fp==NULL)
	  printf("file cannot be opened");
    else
	{
      do
        {
	       c=fgetc(fp);
	       if(c==',' || c=='\n')
				    no_of_fields++;
	      else
	             continue;
        }while(c!='\n');
	}
	length_of_fields=malloc(no_of_fields*sizeof(int));
	for(i=0;i<no_of_fields;i++)
		length_of_fields[i]=0;
	rewind(fp);
	do
	{
		c=fgetc(fp);
		if(c==',' || c=='\n' || c==EOF)
		{
			
			if(length_of_fields[current_field]<length)
				length_of_fields[current_field]=length;
			if(c=='\n')
				current_field=0;
			else
                current_field++;
			length=0;
		    
		}
		else
			length++;
	}while(c!=EOF);
	csv_format(length_of_fields,no_of_fields);
}
void csv_format(int length_of_fields[],int no_of_fields)
{
	int length=0,current_field=0,i;
	FILE *fp;
	char c;
	fp=fopen("sample_csv.csv","r");
	if(fp==NULL)
		printf("file cannot be opened");
	else
	{
		do
		{
			c=fgetc(fp);
			if(c==',' || c=='\n' || c==EOF)
		    {
			
			    if(length_of_fields[current_field]>length )
			    {
				     while(length_of_fields[current_field]!=length)
				     {	
					  printf(" ");
					   length++;
				     }
			    }
				for(i=0;i<5;i++)
					printf(" ");
			    if(c=='\n')
				   {
					   current_field=0;
					   printf("\n");
				   }
			   else
                  current_field++;
			   length=0;
		    
		    }
		    else
		    {
			  printf("%c",c);
			  length++;
		     }
		 }while(c!=EOF);
	}
}