#include <stdio.h>
#include "BinaryTree.h"

int bintree_main()
{
	struct node* root = NULL;
	root = createTree(&root);
	inOrderDisplay(root);
	return 0;
}