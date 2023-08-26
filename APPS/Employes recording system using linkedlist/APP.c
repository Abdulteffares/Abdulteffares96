#include"LinkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"func.h"
void main(void)
{
	int choice,flag=1;
	sll_t * ptrtos=create_list();
	while(flag)
	{
		system("cls");
		printf("welcomee to the system\nTo add new employe press 0\nTo delete an employe press 1\nTo modify an existing data press 2\nTo view all the employes data press 3\nTo view data of an specific employe press 4\nTo Exit press any number\n");
	    scanf("%d",&choice);
		getchar();
		switch(choice)
		{
			case 0:
			{
				add_employe(ptrtos);
				break;	
			}
			case 1:
			{
			  delete_employe(ptrtos);
			  break;
			}
			case 2:
			{
			  modify_employe_data(ptrtos);
			  break;
			}
			case 3:
			{
				display_SLL(ptrtos);
				break;
			}
			case 4:
			{
				display_speceific_employe(ptrtos);
				break;
			}
			default :
			exit(0);
			break ;
		}
		//system("cls");
		printf("To Exit press 0\nTo return to the prev menue press any number\n ");
	    scanf("%d",&flag);
	}
	
	free_sll(ptrtos);
}
