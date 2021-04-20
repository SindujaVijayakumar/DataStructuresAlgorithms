#pragma once
#include<stdio.h>
#include<stdlib.h>

#ifndef BST
#define BST

struct node {
	struct node* left;
	struct node* right;
	int info;
};

struct node* root = NULL;

struct node* insertBST(struct node* r, int val)
{
	struct node* parent;
	struct node* elem;
	struct node* newNode;
	parent = elem = r;
	while (elem != NULL)
	{	
		parent = elem;
		if (elem->info == val)
			return;
		else if (val < elem->info)
			elem = elem->left;
		else
			elem = elem->right;
	}

	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->info = val;
	newNode->left = newNode->right = NULL;
	if (parent == NULL)
		r = newNode;
	else if (val < parent->info)
		parent->left = newNode;
	else
		parent->right = newNode;

	return r;

}


void inOrderDisplayBST(struct node* p)
{
	if (p != NULL)
	{
		inOrderDisplayBST(p->left);
		printf("%d ", p->info);
		inOrderDisplayBST(p->right);
	}

}

void PreOrderDisplayBST(struct node* p)
{
	if (p != NULL)
	{
		printf("%d ", p->info);
		PreOrderDisplayBST(p->left);
		PreOrderDisplayBST(p->right);
	}

}

void PostOrderDisplayBST(struct node* p)
{
	if (p != NULL)
	{
		PostOrderDisplayBST(p->left);
		PostOrderDisplayBST(p->right);
		printf("%d ", p->info);
	}

}

#endif