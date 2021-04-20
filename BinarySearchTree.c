#include <stdio.h>
#include "BinarySearchTree.h"


int bst_main()
{
	struct node* root = NULL;
	root = insertBST(root, 10);
	root = insertBST(root, 20);
	root = insertBST(root, 30);
	root = insertBST(root, 40);
	root = insertBST(root, 0);
	root = insertBST(root, 2);
	inOrderDisplayBST(root);
	return 0;
}