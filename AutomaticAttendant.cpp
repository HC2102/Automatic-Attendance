#include <stdio.h>
#include<time.h>
#include<string.h>
#include <iostream>
#define MAX 200
int main()
{
	FILE *fp = NULL;
	int option, schoolType;
	char schoolName[MAX];
	int daym,yearm,monthm,date;

//	printf("%s",ctime(&t));
	// check file is open successfully
	fp = fopen("diem-danh-tuyen-sinh.txt","a");
	if(fp!=NULL)
	{
		printf("Enter school name:\n");
		scanf("%[^\n]",schoolName);
		printf("\n==========Automatic Attendant==========\n");
		printf("1. Instance AA\n2. Manual AA\n");
		printf("Version 1.0.0 copyright Homles\n");
		scanf("%d",&option);
		printf("=======================================\n");
		switch(option)
		{
			case 1:
				time_t t;
				time(&t);
				printf("Enter school type (1/2):\n");
				scanf("%d",&schoolType);
				fprintf(fp,"%s%s %d\n----------------------------\n",ctime(&t),schoolName,schoolType);
				printf("Complete!");
				break;
			case 2:
				printf("Enter date:\n");
				scanf("%d",&date);
				printf("Enter the date (dd/mm/yy)\n");
				scanf("%d %d %d",&daym,&monthm,&yearm);
				printf("Enter school type (1/2):\n");
				scanf("%d",&schoolType);
				fprintf(fp,"%d, %d %d %d (date, dd/mm/yy)\n%s %d\n----------------------------\n",date,daym,monthm,yearm,schoolName,schoolType);
				printf("Complete!\n");
				
		}
		fclose(fp);
	}
	else
	{
		printf("Failed to open file \n");
	}
	system("pause");
	return 0;
	//this is a change  in local machine


}
