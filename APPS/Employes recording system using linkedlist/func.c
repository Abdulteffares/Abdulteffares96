#include"LinkedList.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"func.h"
//to add new employes
process_status add_employe(sll_t*list)
{
	char title[100],name[100];
	node_t *retnode=NULL;
	int age,salery;
	unsigned long long id;
	printf("enter employe name\n");
	fgets(name,100,stdin);
	name[strcspn(name, "\n")] = '\0';
	printf("enter employe age\n");
	scanf("%d",&age);
	printf("enter employe salery\n");
	scanf("%d",&salery);
	printf("enter employe title\n");
	fflush(stdin);
	fgets(title,100,stdin);
	title[strcspn(title,"\n")]='\0';
	printf("enter employe id (must be 14 digits)\n");
	scanf("%llu",&id);
	getchar();
	while((id/10000000000000)==0||(id/10000000000000)>=10)
	{
		printf("id is not valid please renter id\n");
		scanf("%llu",&id);
		getchar();
	}
	printf("******\n");
	if(search_node(list,id,&retnode)==NODE_NOT_FOUND)
	{
		append_node(list,name,age,salery,title,id);
		printf("process done\n");
		free(retnode);
		return process_done;
	}
	else
	{
		printf("id already existed \n");
		return process_error;
	}
}

// to modify employe data 
process_status modify_employe_data(sll_t*list)
{
	if(list->head==NULL)
	{   system("cls");
		printf("\t\t\t\t\t\t**** List Is Empty ****\n");
		return process_error;
	}
		system("cls");
	unsigned long long id;
	  printf("enter employe id\n");
	  scanf("%llu",&id);
	node_t*retnode=NULL;
	int target_data;
	
    if(search_node(list,id,&retnode)==NODE_NOT_FOUND)
	{
		printf("employe not found\n");
		return process_error;
	}
	system("cls");
	printf("for modifying name press 0\nfor modifying age press 1\nfor modifying salery press 2\nfor modifying title press 3\nfor modifying id press 4\n");
	printf("******\n");
	scanf("%d",&target_data);
	switch(target_data)
	{
		case 0:
		{
			system("cls");
			char name[100];
			printf("Enter employe new name\n");
		    fflush(stdin);
			fgets(name,100,stdin);
			name[strcspn(name, "\n")] = '\0';
			strcpy(retnode->name,name);
			break;
		}	
		case 1: 
		{
			system("cls");
			int age;
			printf("Enter employe modified age\n");
			scanf("%d",&age);
			getchar();
			retnode->age=age;
			break;
		}
		case 2 :
		{
			system("cls");
		    int salery;
			printf("Enter employe new salery\n");
			scanf("%d",&salery);
			getchar();
			retnode->salery=salery;
			break;
		}
		case 3 :
		{
			system("cls");
		    char title[100];
			printf("enter employe new title\n");
			fflush(stdin);
			fgets(title,100,stdin);
			title[strcspn(title,"\n")]='\0';
			strcpy(retnode->title,title);
			break;
		}
		case 4 :
		{
			system("cls");
		    unsigned long long id;
			printf("Enter employe new new id \n");
			scanf("%llu",&id);
			getchar();
			retnode->id=id;
		}
	}
	return process_done;
}
//to delete employe
void delete_employe(sll_t*list)
{
	system("cls");
	if(list->head==NULL)
	{
		printf("\t\t\t\t\t\t**** List Is Empty ****\n");
		return;
	}
	unsigned long long id;
	printf("enter employe id\n");
	scanf("%llu",&id);
	getchar();
	delete_node_byValue(list,id);
}

// to display specific employe;
process_status display_speceific_employe(sll_t*list)
{
	if(list->head==NULL)
	{
		system("cls");
		printf("\t\t\t\t\t\t**** List Is Empty ****\n");
		return process_error;

		 

	}
	node_t*retnode=NULL;
	unsigned long long id;
	system("cls");
	printf("enter employe id\n");
	scanf("%llu",&id);
	getchar();
	system("cls");
	printf("************************************************************************************************************************\n");
	printf("\t  Name\t\t\tAge\t\t\tSallery\t\t\tTitle\t\t\tId\n");
	printf("************************************************************************************************************************\n");
	if(search_node(list,id,&retnode)!=NODE_NOT_FOUND||(search_node(list,id,&retnode))!=SLL_NOT_OK)
	{
		printf("\t%-20s",retnode->name);
		printf("\t%-20d",retnode->age);
		printf("\t%-22d",retnode->salery);
		printf("\t%-18s",retnode->title);
		printf("%llu\n",retnode->id);	
		printf("************************************************************************************************************************\n");
		 return process_done;
	}
	else
	{
		printf("employe Not found\n");
		 return process_error;
	}		
}