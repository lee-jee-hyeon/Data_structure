#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Data;

typedef struct ListNode {
	Data data;
	struct ListNode* link;
} ListNode;

int swapNode(ListNode**, ListNode**);
ListNode* createNode(const Data, ListNode*);
ListNode* insertNode(ListNode**, ListNode*);
ListNode* merge(ListNode*, ListNode*);
int display(ListNode*);

int main(void)
{
	ListNode* list1 = NULL, * list2 = NULL;
	ListNode* mergeList = NULL;
	int i;

	srand((unsigned)time(NULL));

	for (i = 0; i < 5; i++)
		insertNode(&list1, createNode(rand() % 20, NULL));
	printf("[List1 Data] ");
	display(list1);

	for (i = 0; i < 5; i++)
		insertNode(&list2, createNode(rand() % 20, NULL));
	printf("\n\n[List2 Data] ");
	display(list2);

	mergeList = merge(list1, list2);
	printf("\n\n[Merge List Data] ");
	display(mergeList);

	return 0;
}

int swapNode(ListNode** list1, ListNode** list2)
{
	ListNode* tempNode;

	if (*list1 == NULL || *list2 == NULL)
		return 0;

	tempNode = *list1;
	*list1 = *list2;
	*list2 = tempNode;

	return 1;
}

ListNode* createNode(const Data data, ListNode* link)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

	if (newNode == NULL)
		return NULL;

	newNode->data = data;
	newNode->link = link;

	return newNode;
}

ListNode* insertNode(ListNode** plist, ListNode* newNode)
{
	ListNode* insertPos = *plist;

	if (*plist == NULL)
		*plist = newNode;
	else
	{
		while (insertPos->link != NULL && insertPos->link->data <= newNode->data)
			insertPos = insertPos->link;

		if ((*plist)->data > newNode->data)
		{
			swapNode(plist, &newNode);
			insertPos = *plist;
		}
		else
			newNode->link = insertPos->link;

		insertPos->link = newNode;
	}

	return *plist;
}

ListNode* merge(ListNode* list1, ListNode* list2)
{
	ListNode* mergeList = (ListNode*)malloc(sizeof(ListNode));
	ListNode* pos1 = list1, * pos2 = list2;
	ListNode* pos_merge = mergeList;

	pos_merge->data = (pos1->data <= pos2->data) ? (pos1->data) : (pos2->data);
	(pos1->data <= pos2->data) ? (pos1 = pos1->link) : (pos2 = pos2->link);

	while (pos1 != NULL && pos2 != NULL)
	{
		if (pos1->data <= pos2->data)
		{
			pos_merge->link = createNode(pos1->data, NULL);
			pos1 = pos1->link;
			pos_merge = pos_merge->link;
		}
		else
		{
			pos_merge->link = createNode(pos2->data, NULL);
			pos2 = pos2->link;
			pos_merge = pos_merge->link;
		}
	}

	while (pos1 != NULL)
	{
		pos_merge->link = createNode(pos1->data, NULL);
		pos1 = pos1->link;
		pos_merge = pos_merge->link;
	}

	while (pos2 != NULL)
	{
		pos_merge->link = createNode(pos2->data, NULL);
		pos2 = pos2->link;
		pos_merge = pos_merge->link;
	}

	return mergeList;
}

int display(ListNode* list)
{
	ListNode* pos = list;

	if (list == NULL)
		return 0;

	do
	{
		printf("%d ", pos->data);
		pos = pos->link;
	} while (pos != NULL);

	return 1;
}