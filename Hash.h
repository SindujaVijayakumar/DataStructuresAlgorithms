#pragma once
#include <stdlib.h>
#include <stdio.h>

#ifndef hashtable
#define hashtable

struct Node {
	struct Node* next;
	int info;
};

struct Node* HT[10];

struct Node* createNode(int info)
{
	struct Node *p;
	p = (struct Node*)malloc(sizeof(struct Node));
	p->next = NULL;
	p->info = info;

	return p;
}

void initHashTable(struct Node** HT)
{
	for (int i = 0; i < 10; i++)
		HT[i] = NULL;
	//return HT;
}

int hashFunction(int info)
{
	return info % 10;
}


void insertHashTable(struct Node *HT[], int info)
{
	struct Node *t = createNode(info);
	int index = hashFunction(info);
	struct Node *p;
	struct Node *prev;
	if (HT[index] == NULL)
		HT[index] = t;
	else
	{
		p = HT[index];
		prev = p;
		while (p != NULL)
		{
			if (p->info < info)
				break;
			prev = p;
			p = p->next;
		}

		if (p == HT[index])
		{
			t->next = HT[index];
			HT[index] = t;
		}
		else
		{
			t->next = prev->next;
			prev->next = t;
		}
	}

}

void displayHashTable(struct Node** HT)
{
	struct Node* HT_node;
	for (int i = 0; i < 10; i++)
	{
		HT_node = HT[i];
		printf("\nHT[%d] ::", i);
		while (HT_node != NULL)
		{
			printf("%d ", HT_node->info);
			HT_node = HT_node->next;
		}
	}

}



#endif

