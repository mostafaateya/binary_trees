#include "binary_trees.h"
#include <stdlib.h>

/**
 * mos_tree_length - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: Height or 0 if tree is NULL
 */

size_t mos_tree_length(const heap_t *tree)
{
	size_t x1 = 0;
	size_t x2 = 0;

	if (!tree)
		return (0);

	if (tree->left)
		x1 = 1 + mos_tree_length(tree->left);

	if (tree->right)
		x2 = 1 + mos_tree_length(tree->right);

	if (x1 > x2)
		return (x1);
	return (x2);
}

/**
 * mos_tree_size - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: Height or 0 if tree is NULL
 */

size_t mos_tree_size(const binary_tree_t *tree)
{
	size_t x1 = 0;
	size_t x2 = 0;

	if (!tree)
		return (0);

	if (tree->left)
		x1 = 1 + mos_tree_size(tree->left);

	if (tree->right)
		x2 = 1 + mos_tree_size(tree->right);

	return (x1 + x2);
}

/**
 * mos_preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last note in traverse
 * @height: height of tree
 * Return: No Return
 */

void mos_preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	mos_preorder(tree->left, node, height);
	mos_preorder(tree->right, node, height);
}

/**
 * mos_heapify - heapifies max binary heap
 * @root: pointer to binary heap
 */

void mos_heapify(heap_t *root)
{
	int a;
	heap_t *x1, *x2;

	if (!root)
		return;

	x1 = root;

	while (1)
	{
		if (!x1->left)
			break;
		if (!x1->right)
			x2 = x1->left;
		else
		{
			if (x1->left->n > x1->right->n)
				x2 = x1->left;
			else
				x2 = x1->right;
		}
		if (x1->n > x2->n)
			break;
		a = x1->n;
		x1->n = x2->n;
		x2->n = a;
		x1 = x2;
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/

int heap_extract(heap_t **root)
{
	int a;
	heap_t *x, *xx;

	if (!root || !*root)
		return (0);
	x = *root;
	a = x->n;
	if (!x->left && !x->right)
	{
		*root = NULL;
		free(x);
		return (a);
	}

	mos_preorder(x, &xx, mos_tree_length(x));

	x->n = xx->n;
	if (xx->parent->right)
		xx->parent->right = NULL;
	else
		xx->parent->left = NULL;
	free(xx);
	mos_heapify(x);
	*root = x;
	return (a);
}
