#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _node
{
	char *piplinetype;
	struct _node *next;
} Node;

typedef struct _linkedList
{
	Node *head;
	Node *tail;
	Node *before;
	Node *current;
	int nodeCreateCount;
} LinkedList;

Node *makenode(char *piplinetype, Node * next)
{
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->piplinetype = piplinetype;
	newnode->next = next;
	return newnode;
}
void Linkedinit(LinkedList *plist)
{
	plist->head = NULL;
	plist->tail = NULL;
	plist->nodeCreateCount = 0;
}

void LinkedInsert(LinkedList *plist, char *pipline)
{
	if (plist->head == NULL)
	{
		plist->head = makenode(pipline, NULL);
		plist->tail = plist->head;
	}
	else
	{
		plist->current = makenode(pipline, NULL);
		plist->tail->next = plist->current;
		plist->tail = plist->current;
	}
}
int LinkedListSearchProc(LinkedList *plist, char *pipline)
{
	while (plist->head != plist->tail)
	{
		plist->before = plist->head;
		plist->current = plist->head->next;
	}
	return 1;
}

int pipRuleCheck(LinkedList *plist, char *pipline, int count)
{
	
	plist->nodeCreateCount = 0;
	while (plist->current != plist->tail)
	{
		if (plist->before->piplinetype == "─" && plist->current->piplinetype == "┐")
		{
			(plist->nodeCreateCount)++;
			plist->before = plist->current;
			plist->current = plist->current->next;
		}
		else if (plist->before->piplinetype == "ㅡ" && plist->current->piplinetype == "ㅣ")
		{
			(plist->nodeCreateCount)++;
			plist->before = plist->current;
			plist->current = plist->current->next;
		}
		else if (plist->before->piplinetype == "ㄱ" && plist->current->piplinetype == "ㅣ")
		{
			(plist->nodeCreateCount)++;
			plist->before = plist->current;
			plist->current = plist->current->next;
		}
		else if (plist->before->piplinetype == "ㅣ" && plist->current->piplinetype == "ㄴ")
		{
			(plist->nodeCreateCount)++;
			plist->before = plist->current;
			plist->current = plist->current->next;
		}
		else if (plist->before->piplinetype == "ㄴ" && plist->current->piplinetype == "ㅡ")
		{
			(plist->nodeCreateCount)++;
			plist->before = plist->current;
			plist->current = plist->current->next;
		}
		else
		{
			exit(0);
			break;
		}
		printf("승인");
	}
	return 1;
}

int main(void)
{
	char list[10][10];

	LinkedList plist;
	Linkedinit(&plist);
	for(int n = 0 ; n < 10 ; n++){
	for (int i = 0; i < 10; i++)
	{
		scanf("%s", list[i]);
	}
	for (int j = 0; j < 10; j++)
	{
		LinkedInsert(&plist, list[j]);
	}
	if (pipRuleCheck(&plist,0, 0) == true) {
		printf("승인");
	}
	else
	{
		printf("배관 오류 ! 프로그램이 종료됩니다.");
		exit(0);

	}


	}
	
	return 0;

}