#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorted-list.h"

int IntComp(void * p1, void * p2 )
{
	int x = *((int*)p1);
	int y = *((int*)p2);
	
	
	if(x < y)
	{
		return  -1;
	}
	else if(x > y)
	{
		return 1;
	}
	else
	return 0;
}
int FloatComp(void * p1, void * p2 )
{
	float x = *((float*)p1);
	float y = *((float*)p2);
	
	
	if(x < y)
	{
		return  -1;
	}
	else if(x > y)
	{
		return 1;
	}
	else
	return 0;
}
int StringComp(void* p1, void * p2)
{
	//char * x = *((char**)p1);
	//char * y = *((char**)p2);
	
	if(strcmp(p1,p2) < 0)
	{
		return  -1;
	}
	else if(strcmp(p1,p2) > 0)
	{
		return 1;
	}
	else
	return 0;	
}
void df(void * x) // just frees that data
{
	free(x);
}


int main(int argc, char ** argv)
{	
 struct SortedList* intList = NULL;
 intList = SLCreate(&IntComp, &df);
 struct SortedList*  floatList = NULL;
 floatList = SLCreate(&FloatComp, &df);
 struct SortedList*  stringList = NULL;
 stringList = SLCreate(&StringComp, &df);
	
	while(1)
	{
	int a = 0;
	printf("Enter 1 for insert a piece of data \nEnter 2 for remove a piece of data \nEnter 3 for destroy a list \nEnter 4 to look through a list \nEnter 5 to exit program\n");
	scanf("%d", &a);
	if(a == 1) // ALL THIS IS FOR INSERT
	{
		printf("Enter 1 if data is a integer \nEnter 2 if data is a string\nEnter 3 if data is a float\n");
		scanf("%d", &a);
		if(a == 1)// insert intger
		{
			int b = 0;
			printf("Enter your number to insert: ");
			scanf("%d", &b);
			void *bp=(void*)(malloc(sizeof(int)));  // when you see this it's to convert certain data to a void pointer.
			memcpy(bp, &b, 1);
			
			int SorF =  SLInsert(intList, bp);
			if(SorF == 1)
			{
				printf("Success\n");
			}
			else if(SorF == 0)
			{
				printf("Fail\n");
			}
		}
		else if(a == 2) // insert string
		{
			char b[40];
			printf("Enter your word to insert: ");
			scanf("%s", b);
			void *bp=(void*)(malloc(40*sizeof(char)));
			memcpy(bp, &b, 40);
			
			int SorF =  SLInsert(stringList, bp);
			if(SorF == 1)
			{
				printf("Success\n");
			}
			else if(SorF == 0)
			{
				printf("Fail\n");
			}
			
		}
		else if(a == 3) // insert float
		{
			float b;
			printf("Enter your number to insert: ");
			scanf("%f", &b);
			void *bp=(void*)(malloc(sizeof(float)));
			memcpy(bp, &b, 40);
			
			int SorF =  SLInsert(floatList, bp);
			if(SorF == 1)
			{
				printf("Success\n");
			}
			else if(SorF == 0)
			{
				printf("Fail\n");
			}
		}
		else
		{
			printf("invalid input\n");
			break;
		}
	}
	else if(a == 2)//remove
	{
		
		printf("Enter 1 if data is a integer \nEnter 2 if data is a string\nEnter 3 if data is a float\n");
		scanf("%d", &a);
		if(a == 1) // remove int
		{
			
			if(intList == NULL)
			{
				printf("No Integer list was created");
			}
			else
			{
			int b = 0;
			printf("Enter your number to remove: ");
			scanf("%d", &b);
			void *bp=(void*)(malloc(sizeof(int)));
			memcpy(bp, &b, 1);
			
			int SorF =  SLRemove(intList, bp);
			if(SorF == 1)
			{
				printf("Success\n");
			}
			else if(SorF == 0)
			{
				printf("Fail\n");
			}
			}
		}
		else if(a == 2) // remove string
		{
			if(intList == NULL)
			{
				printf("No Integer list was created");
			}
			else
			{
			char b[40];
			printf("Enter your number to remove: ");
			scanf("%s", b);
			void *bp=(void*)(malloc( 40 * sizeof(char)));
			memcpy(bp, &b, 40);
			
			int SorF =  SLRemove(stringList, bp);
			if(SorF == 1)
			{
				printf("Success\n");
			}
			else if(SorF == 0)
			{
				printf("Fail\n");
			}
			}
			
		}
		else if(a == 3) // remove float
		{
			if(floatList == NULL)
			{
				printf("No Float list was created");
			}
			else
			{
			float b = 0;
			printf("Enter your number to remove: ");
			scanf("%f", &b);
			void *bp=(void*)(malloc(sizeof(float)));
			memcpy(bp, &b, 40);
			
			int SorF =  SLRemove(floatList, bp);
			if(SorF == 1)
			{
				printf("Success\n");
			}
			else if(SorF == 0)
			{
				printf("Fail\n");
			}
			}
		}
		else
		{
			printf("invalid input\n");
			break;
		}
	}
	else if(a == 3)//destroy
	{
		printf("Enter 1 if you want to destroy a integer list \nEnter 2 if you want to destroy a string list\nEnter 3 if you want to destroy a float list\n");
		scanf("%d", &a);
		if(a == 1)// destroy int
		{
			if(intList == NULL)
			{
				printf("No Integer list was created");
			}
			else
			{
				SLDestroy(intList);
				printf("list destroyed\n");
			}
		}
		else if(a == 2)//destroy string
		{
			if(stringList == NULL)
			{
				printf("No String list was created");
			}
			else
			{
				SLDestroy(stringList);
				printf("list destroyed\n");
			}
		}
		else if(a == 3)//destroy float
		{
			if(floatList == NULL)
			{
				printf("No Float list was created");
			}
			else
			{
				SLDestroy(floatList);
				printf("list destroyed\n");
			}
		}
		else
		{
			printf("invalid input\n");
			break;
		}
	}
	else if(a == 4)// iterator
	{
		
		printf("Enter 1 to look through the Intger list\nEnter 2 to look through the String list\nEnter 3 to look through the Float list\n");
		scanf("%d", &a);
		if(a == 1) // int list
		{
			while(intList != NULL && intList -> prev != NULL) // when you see this, this is to bring the link list to the head. so iter can start fromt he start. so it will always start from the head
			{
				intList = intList -> prev;
			}
			
			struct SortedListIterator* iterInt = NULL;
			iterInt = SLCreateIterator(intList);
			if(iterInt -> SL == NULL)
			{
				printf("No list for Integer has been made\n");
			}
			else
			{
			int c = 0;
			while(c != 3)
			{
				printf("Enter 1 to get curr data\nEnter 2 to get next data\nEnter 3 to stop\n");
				scanf("%d", &c);
				if(c == 1)//curr
				{
					void *data = (void*)(malloc(sizeof(int)));
					data = SLGetItem(iterInt);
					if(iterInt -> SL == NULL || iterInt -> SL -> data == NULL)
					{
						printf("Done with Iterator\n");
					}
					else 
					printf("%d\n", *((int*)(data)));
				}
				else if(c == 2)//next
				{
					void *data = (void*)(malloc(sizeof(int)));
					data = SLNextItem(iterInt);
					if(iterInt -> SL == NULL || iterInt -> SL -> data == NULL || data == NULL)
					{
						printf("Done with Iterator\n");
					}
					else
					printf("%d\n", *((int*)(data)));
				}
				else if(c != 3)
				{
					printf("invalid input\n");
					break;
				}
			}
			}
			free(iterInt);
		}
		else if(a == 2)// word iter
		{
			while(stringList != NULL && stringList -> prev != NULL)
			{
				stringList = stringList -> prev;
			}
			struct SortedListIterator* iterString = NULL;
			iterString = SLCreateIterator(stringList);
			
			if(iterString -> SL == NULL)
			{
				printf("No list for Integer has been made\n");
			}
			else
			{
			int c = 0;
			while(c != 3)
			{
				printf("Enter 1 to get curr data\nEnter 2 to get next data\nEnter 3 to stop\n");
				scanf("%d", &c);
				if(c == 1)//curr
				{
					void *data = (void*)(malloc(sizeof(char[40])));
					data = SLGetItem(iterString);
					if(iterString -> SL == NULL || iterString -> SL -> data == NULL)
					{
						printf("Done with Iterator\n");
					}
					else
					printf("%s\n", (char*)(data));
				}
				else if(c == 2)//next
				{
					void *data = (void*)(malloc(sizeof(char[40])));
					data = SLNextItem(iterString);
					if(iterString -> SL == NULL || iterString -> SL -> data == NULL || data == NULL)
					{
						printf("Done with Iterator\n");
					}
					else
					printf("%s\n", (char*)(data));
				}
				else if(c != 3)
				{
					printf("invalid input\n");
					break;
				}
			}
			}
			free(iterString);
		}
		else if(a == 3) // float
		{
			while(floatList != NULL && floatList -> prev != NULL)
			{
				floatList = floatList -> prev;
			}
			
			struct SortedListIterator* iterFloat = NULL;
			iterFloat = SLCreateIterator(floatList);
			if(iterFloat -> SL == NULL)
			{
				printf("No list for Float has been made\n");
			}
			else
			{
			int c =0;
			while(c != 3)
			{
				printf("Enter 1 to get curr data\nEnter 2 to get next data\nEnter 3 to stop\n");
				scanf("%d", &c);
				if(c == 1)//curr
				{
					void *data = (void*)(malloc(sizeof(float)));
					data = SLGetItem(iterFloat);
					if(iterFloat->SL == NULL || iterFloat -> SL -> data == NULL)
					{
						printf("Done with Iterator\n");
					}
					else
					printf("%f\n", *((float*)(data)));
				}
				else if(c == 2)//next
				{
					void *data = (void*)(malloc(sizeof(float)));
					data = SLNextItem(iterFloat);
					if(iterFloat->SL == NULL  || iterFloat ->SL -> data == NULL || data != NULL)
					{
						printf("Done with Iterator\n");
					}
					else
					printf("%f\n", *((float*)(data)));
				}
				else if(c != 3)
				{
					printf("invalid input\n");
					break;
				}
			}
			}
			free(iterFloat);
		}
		else
		{
			printf("invalid input\n");
			break;
		}
	}
	else if(a == 5)
	{
		printf("Program Exited\n");
		break;
	}
	else
	{
		printf("invalid input\n");
		break;
	}
	}
	
	
  return 0;
}
