// bubblepoint.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node *PtrToNode;
typedef PtrToNode List; 
typedef PtrToNode Position;
typedef int ElementType;

struct Node  
{  
    ElementType Element;  
    Position Next;  
}; 

List initList()  
{  
    List L = (List)malloc(sizeof(struct Node));  
    L->Next = NULL;  
        return L;  
} 

void insertElement(List L,int *num)  
{  
    int element = *num;  
    PtrToNode tmp = (PtrToNode)malloc(sizeof(struct Node));  
    tmp->Element = element;  
    tmp->Next = L->Next;  
    L->Next = tmp;  
}

void printList(List L)  
{  
    Position P = L->Next;  
    printf("L->");  
    while(P != NULL)  
    {  
        printf("%d - >", P->Element);  
        P = P->Next;  
    }  
    printf("NULL\n");  
} 

int get_length(List L)  
{  
    int i = 0;  
    Position P = L->Next;  
    while(P != NULL)  
    {  
        i++;  
        P = P->Next;  
    }  
    return i;  
} 

void BubblePoint(List L)  
{  
    Position pre;  
    Position cur;  
    Position next;  
      
    int i, j;  
    i = get_length(L);  
    printf("length = %d\n", i);  
      
    while(i != 1)  
    {  
        pre = L;  
                cur = L->Next;  
                next = cur->Next;  
                j = i;  
        i--;  
        while(j != 1)  
        {  
            j--;  
            if(cur->Element > next->Element)  
            {  
                cur->Next = next->Next;  
                pre->Next = next;  
                next->Next = cur;  
                  
                pre = next;  
                next = cur->Next;  
            }  
            else  
            {  
                pre = cur;  
                cur = next;  
                next = next->Next;  
            }  
        }  
    }     
}  

int _tmain(int argc, _TCHAR* argv[])
{

	char str[1024]={0};
	int num[1024]={0};
	int i = 0;
	char *token = NULL;
	char *next_token = NULL;
	List L;  
    L = initList();  

	gets_s(str);
	token = strtok_s(str," ",&next_token);
	while(token != NULL)
	{
		if(*token == 'q' || *token == 'Q')
		{
			break;
		}
		num[i] = atoi(token);
		insertElement(L,num+i);
		i++;
		token = strtok_s(NULL," ",&next_token);
	}
    printList(L);  
    BubblePoint(L);  
    printList(L); 
	return 0;
}

