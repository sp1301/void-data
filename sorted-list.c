#include <stdlib.h>
#include <stdio.h>
#include "sorted-list.h"


SortedListPtr* head = NULL;

SortedListPtr SLCreate (CompareFuncT cf, DestructFuncT df) // set everything to default
{
  SortedListPtr node = (struct SortedList*) malloc(sizeof(struct SortedList));
  node -> data = NULL;
  node -> next = NULL;
  node -> prev = NULL;
  node ->compare = cf;
  node ->destruct = df;
  
  return node;
}

void SLDestroy (SortedListPtr list) // assuming list is the start of node.
{
	while(list -> prev != NULL) // bring the list to the head of the link list
	{
		list = list -> prev;
	}
	
	if(list->next == NULL) // if it;s only one node
	{
		list->destruct(list->data);
		free(list);
		list = NULL;
		return;
	}
	
	SortedListPtr temp =  list;
     while (temp -> next != NULL) // frees everything
     {
		temp = list -> next;
		list->destruct(list->data);
		free(list);
		list = temp;
     }
	 list = NULL;
}

int SLInsert(SortedListPtr list, void *newObj)
{
	
	if(list->data == NULL) // error check
	{
		list-> data = newObj;
		return 1;
	}
	
	
	SortedListPtr temp = SLCreate(list -> compare, list -> destruct);
	temp -> data = newObj;
	
	while(list != NULL)// can start anywhere on the list
	{
		if(list->compare(list->data, newObj) == 0) // equal to
		{
			temp->destruct(temp->data);
			free(temp);
			return 0;
		}
		else if(list->compare(list->data, newObj) == -1) //will increment to the left and stop when it hits the front or some value that is bigger
		{
			if(list -> prev == NULL)
			{
				temp -> next = list;
				list -> prev = temp;
				return 1;
			}
			else if(list->prev->compare(list->prev->data, newObj) == 1)
			{
				temp -> prev = list -> prev;
				temp -> next = list;
				list -> prev -> next = temp;
				list -> prev = temp;
				return 1;
			}
			list = list -> prev;
		}
		else if(list->compare(list->data, newObj) == 1)//>>>>>  increment to the right and will stop when it hits the end or a lower value
		{
			if(list -> next == NULL)
			{
				list -> next = temp;
				temp -> prev = list;
				return 1;
			}
			else if(list->next->compare(list->next->data, newObj) == -1)
			{
				temp -> prev = list;
				temp -> next = list -> next;
				list -> next -> prev = temp;
				list -> next = temp;
				return 1;
			}
			list = list -> next;
		}
	}
	
	
	temp->destruct(temp->data);
	free(temp);
	return 0;
}

int SLRemove(SortedListPtr list, void* newObj)
{
	// newObj 
	//return 1 successe 
	//reutn 0 failuer
	if(list == NULL)
	{
		return 0;
	}
	
	while(list -> prev != NULL) // brings the list to be the head of the link list
		{
			list = list -> prev;
		}
	
	//SortedListPtr temp = NULL;
	//SortedListPtr placeholder = NULL;
	while(list != NULL) // it goes through the list and checks 3 cases, if it is one node, hit the head , hits the end, or middle
	{
		if(list->compare(list->data, newObj) == 0)
		{
			//temp = list;
			if(list -> prev  == NULL && list -> next == NULL)
			{
				list->destruct(list->data);
				free(list);
				list = NULL;
				return 1;
			}
			else if(list -> prev == NULL && list -> next != NULL)
			{
				//placeholder = list -> next;
				list->next->prev = NULL;
				list-> next = NULL;
				list->destruct(list->data);
				free(list);
				//list = placeholder;
				return 1;
			}
			else if(list -> next == NULL && list -> prev != NULL)
			{
				//placeholder = list -> prev;
				list->prev->next = NULL;
				list->destruct(list->data);
				free(list);
				//list = placeholder;
				return 1;
			}
			else
			{
			//placeholder =  list-> prev;
			list ->next -> prev = list -> prev;
			list->prev->next = list -> next;
			list->destruct(list->data);
			free(list);
			//list = placeholder;
			return 1;
			}			
		}
		list = list -> next;
	}
	
	
	return 0;
}



SortedListIteratorPtr SLCreateIterator (SortedListPtr list)
{
      SortedListIteratorPtr node  = (struct SortedListIterator*)  malloc(sizeof(struct SortedListIterator));
	  node -> SL = list;
      return node;
}

void SLDestroyIterator(SortedListIteratorPtr iter)
{
      free(iter);
}

void* SLNextItem(SortedListIteratorPtr iter)
{
	//iter look in to next then get the next ptr then set iter to that nextt;
	if(iter == NULL)
	{
		return NULL;
	}
	if(iter -> SL == NULL)
	{
		return NULL;
	}
	if(iter->SL->next == NULL)
	{
		return NULL;
	}
	
	iter -> SL = iter -> SL -> next; // increment the iter
	return  iter -> SL -> data; // give incremented iter
	
}

void* SLGetItem(SortedListIteratorPtr iter)
{
	if(iter == NULL)
	{
		return NULL;
	}
	if(iter -> SL == NULL)
	{
		return NULL;
	}
	return iter->SL->data; // give data at iter
}
