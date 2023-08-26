#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Linkedlist.h"

sll_t * create_list()
{
	sll_t*ptrtos=malloc(sizeof(sll_t));
	if(ptrtos!=NULL)
	{
		ptrtos->head=NULL;
		ptrtos->size=-1;
		return ptrtos;
	}
	else 
	return NULL;

}

//function to create new node
node_t * create_node(char *Name,int age ,int salery,char *title,unsigned long long id)
{
	node_t*ptrton=malloc(sizeof(node_t));
	if(ptrton!=NULL)
	{
		strcpy(ptrton->name,Name);
		ptrton->age=age;
		ptrton->salery=salery;
		strcpy(ptrton->title,title);
		ptrton->id=id;
		ptrton->next=NULL;
		return ptrton;
	}
	else
		return NULL;
	
	
}

//function to free the lsit 
EN_sllStatus_t free_sll(sll_t* list)
{
	if(list==NULL)
	{
		return SLL_NOT_OK;
	}
	node_t *current=list->head;
	node_t* prev=list->head;
	while(current!=NULL)
	{
		current=current->next;
		free(prev);
		prev=current;
		
	}
	free(list);
	return SLL_OK;
}

//function append node 
EN_sllStatus_t append_node(sll_t* list , char*name,int age,int salery,char * title,unsigned long long id)
{
	if(list!=NULL)
	{
		if(list->head==NULL)
		{
			list->head=create_node(name,age,salery,title,id);
			list->size++;
			return  SLL_OK;
		}
		else
		{
			node_t*current=list->head;
			while(current->next!=NULL)
			{
				current=current->next;
			}
			current->next=create_node(name,age,salery,title,id);
			if(current->next==NULL)
			{
				return NODE_NOT_CREATED;
			}
			list->size++;
			return  SLL_OK;
		}
	}
	else
		return NODE_NOT_CREATED ;
		
	
	
}

//function to display the list 
EN_sllStatus_t display_SLL(sll_t*list)
{
	
	if(list==NULL)return SLL_NOT_OK;
	if(list->head==NULL) 
	{
		system("cls");
		printf("\t\t\t\t\t\t**** List Is Empty ****\n");
		return SLL_EMPTY;
	}
	node_t*current=list->head;
	 system("cls");
	printf("************************************************************************************************************************\n");
	printf("\t  Name\t\t\tAge\t\t\tSallery\t\t\tTitle\t\t\tId\n");
	printf("************************************************************************************************************************\n");
	while(current!=NULL)
	{  
		printf("\t%-20s",current->name);
		printf("\t%-20d",current->age);
		printf("\t%-22d",current->salery);
		printf("\t%-18s",current->title);
		printf("%llu\n",current->id);	
		current=current->next;
	}
	printf("************************************************************************************************************************\n");
	return SLL_OK;
}

//function to search for a certian value in the list 
EN_sllStatus_t search_node(sll_t * list , unsigned long long id, node_t ** retNode)
{
	if(list!=NULL)
	{
		node_t*current=list->head;
		if(current!=NULL)
		{	
			while((current->id!=id))
			{
				if(current->next!=NULL)
				{
					current=current->next;
				}
				else
					break;
			
			}
			if(current->id==id)
			{
				*retNode=current;
				return  SLL_OK;
			}
			if(current->next==NULL||current==NULL)
			{
				return NODE_NOT_FOUND;
			}
		}
		else
		{ 
		  return NODE_NOT_FOUND;
		}
	
	}
	else
	{    
		  return SLL_NOT_OK;
	}
	
	
}
EN_sllStatus_t delete_node_byValue(sll_t * list , unsigned long long id)
{
	if(list!=NULL)
	{
		if(list->head == NULL)
		{
			
			return SLL_EMPTY;
		}
		node_t*current=list->head;
		node_t*prev=current;
		if(current->id==id)
		{
			list->head=list->head->next;
			list->size--;
			free(current);
			return SLL_OK;
		}
		while(current->id!=id&&current->next!=NULL)
		{
			prev=current;
			current=current->next;
		
		}
		
		if(current->id==id)
		{
			prev->next=current->next;
			list->size--;
			free(current);
			return SLL_OK;
		}
		if(current->next==NULL)
		{
			printf("employe_NOT_Found\n");
			return NODE_NOT_FOUND;
			
		}
		
	
	}
	else
	{
		  return SLL_NOT_OK;
	}
	
}
//function to insert a node in a certain position 
EN_sllStatus_t insert_node_atPos(sll_t * list ,char *name ,int age,int salery,char *title,unsigned long long id, int pos)
{
	if(list==NULL)return SLL_NOT_OK;
	if(list->head==NULL) return SLL_EMPTY;
	if(pos>=list->size)
	{
		append_node(list,name,age,salery,title,id);
		return SLL_OK;
	}
	node_t* ptrton=create_node(name,age,salery,title,id);
	if(pos==0)
	{
		ptrton->next=list->head;
		list->head=ptrton;
		return SLL_OK;
	}
	
	int local_counter=0;
	node_t*current=list->head;
	node_t*prev=list->head;
	if(pos>0&&pos<list->size)
	{
		
		for(local_counter=0;local_counter<=pos;local_counter++)
		{
			prev=current;
			current=current->next;
		}
		ptrton->next=current;
		prev->next=ptrton;
		return SLL_OK;
	
	}
	
	
		
}

//function to delete a node in a certain position
EN_sllStatus_t  delete_node_atPos(sll_t* list , int pos)
{
	if(list!=NULL)
	{
		if(list->head == NULL)
		{
			system("cls");
			printf("\t\t\t\t\t\t\t\t\t\t List IS EMPTY\n");
			return SLL_EMPTY;
		}
		
		node_t*current=list->head;
		node_t*prev=current;
		if(pos==0)
		{
			list->head=list->head->next;
			list->size--;
			free(current);
			return SLL_OK;
			
			
		}
		
		int local_counter;
		for(local_counter=0;local_counter<=pos;local_counter++)
		{
			if(current!=NULL)
			{
				if(local_counter==pos)
				{
					prev->next=current->next;
					list->size--;
					free(current);
					
					
				}
			}
		  prev=current;
		  current=current->next;
		}
		if(current==NULL)
		{
			return NODE_NOT_FOUND;
		}
	
	}
	else
	{
		  return SLL_NOT_OK;
	}
}


//funciton to reverse the linked-list
EN_sllStatus_t linkedList_reverse(sll_t * list)
{
	if(list==NULL||list->head==NULL)return SLL_NOT_OK;
	node_t*current=list->head;
	node_t*prev=NULL;
	node_t*temp=NULL;
	while(current!=NULL)
	{
		temp=current->next;
		current->next=prev;
		prev=current;
		current=temp;
	}
	list->head=prev;
	return SLL_OK;
} 