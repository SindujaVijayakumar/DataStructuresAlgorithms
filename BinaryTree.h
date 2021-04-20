#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#ifndef BINTREE
#define BINTREE

struct node {
	struct node* lchild;
	struct node* rchild;
	int info;
};

struct queue {
	struct node* element;
	struct queue* next;
};

struct queue* first = NULL;
struct queue* last = NULL;
//struct node* root = NULL;


void enqueue(struct node* itemToQ)
{
	struct queue* item = (struct queue*)malloc(sizeof(struct queue));
	item->element = itemToQ;
	item->next = NULL;
	if (first == NULL)
	{
		first = item;
		last = item; 
	}
	else
	{
		last->next = item;
		last = item;
	}

}

struct node* dequeue()
{
	struct node* itemToRemove;
	itemToRemove = NULL;

	if (first == NULL)
		;
	else if (first == last)
	{
		itemToRemove = first->element;
		first = last = NULL;
	}
	else
	{
		itemToRemove = first->element;
		first = first->next;
	}
	return itemToRemove;


}

bool isQueueEmpty()
{
	return (first == NULL);
}

struct node* createTree(struct node* root)
{
	struct node* parent;
	struct node* nodeToAdd;
	int info;
	printf("\nenter root :");
	scanf_s("%d", &info);

	root = (struct node*)malloc(sizeof(struct node));
	root->info = info;	
	root->lchild = root->rchild = NULL;
	parent = root;
	enqueue(root);

	while (!isQueueEmpty())
	{
		parent = dequeue();
		printf("\nEnter left child of %d ", parent->info);
		scanf_s("%d", &info);
		if (info != -1)
		{
			nodeToAdd = (struct node*)malloc(sizeof(struct node));
			nodeToAdd->info = info;
			nodeToAdd->lchild = nodeToAdd->rchild = NULL;
			parent->lchild = nodeToAdd;
			enqueue(nodeToAdd);
		}

		printf("\nEnter right child of %d ", parent->info);
		scanf_s("%d", &info);
		if (info != -1)
		{
			nodeToAdd = (struct node*)malloc(sizeof(struct node));
			nodeToAdd->info = info;
			nodeToAdd->lchild = nodeToAdd->rchild = NULL;
			parent->rchild = nodeToAdd;
			enqueue(nodeToAdd);
		}


	}

	return root;

}


void inOrderDisplay(struct node* p)
{
	if (p != NULL)
	{
		inOrderDisplay(p->lchild);
		printf("%d ", p->info);
		inOrderDisplay(p->rchild);
	}

}

void PreOrderDisplay(struct node* p)
{
	if (p != NULL)
	{
		printf("%d ", p->info);
		PreOrderDisplay(p->lchild);		
		PreOrderDisplay(p->rchild);
	}

}

void PostOrderDisplay(struct node* p)
{
	if (p != NULL)
	{
		PostOrderDisplay(p->lchild);		
		PostOrderDisplay(p->rchild);
		printf("%d ", p->info);
	}

}
#endif
