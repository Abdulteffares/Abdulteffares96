#ifndef _H_linkedList_
#define _H_linkedList_
	typedef int data_t;
	typedef struct tag_node
	{
		char name[100];
		int age;
		int salery;
		char title[100];
		unsigned long long id;
		struct tag_node * next;
	}node_t;

	typedef struct tag_SLL
	{
		node_t * head;
		int size;
	}sll_t;

	typedef enum {
		SLL_OK,
		SLL_NOT_OK,
		SLL_EMPTY,
		NODE_NOT_CREATED,
		NODE_NOT_FOUND,
		LIST_NOT_CREATED
	}EN_sllStatus_t;


	//function to create the linked list
	sll_t * create_list();

	//function to create new node
	node_t * create_node(char *Name,int age ,int salery,char *title,unsigned long long id);
	
	//function to free the lsit 
	EN_sllStatus_t free_sll(sll_t* list);

	//function append node 
	EN_sllStatus_t append_node(sll_t* list , char*name,int age,int salery,char * title,unsigned long long id);

	//function to display the list 
	EN_sllStatus_t display_SLL(sll_t*list);

	//function to search for a certian value in the list 
	EN_sllStatus_t search_node(sll_t * list , unsigned long long id, node_t ** retNode);

	//function to delete a node by a certain value 
	EN_sllStatus_t delete_node_byValue(sll_t * list , unsigned long long id);

	//function to insert a node in a certain position 
	EN_sllStatus_t insert_node_atPos(sll_t * list ,char *name ,int age,int salery,char *title,unsigned long long id, int pos);

	//function to delete a node in a certain position
	EN_sllStatus_t  delete_node_atPos(sll_t* list , int pos);

	//funciton to reverse the linked-list
	EN_sllStatus_t linkedList_reverse(sll_t * list); 

#endif