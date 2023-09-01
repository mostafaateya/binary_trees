#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * mos_is_max - goes through a binary tree cheking ropt as max value
 * @tree: pointer to the root
 * Return: 1 if all nodes are max, 0 in other cases
 **/

int mos_is_max(const binary_tree_t *tree)
{
	int x1 = 1, x2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		x1 = mos_is_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		x2 = mos_is_max(tree->right);
	}
	return (x1 && x2);
}

/**
 * binary_tree_is_heap - checks if a binary tree is heap
 * @tree: pointer to the node
 * Return: 1 in case BTS /  0 otherwise
 **/

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int a;

	if (!tree)
		return (0);

	a = binary_tree_is_complete(tree);
	if (!a)
		return (0);
	return (mos_is_max(tree));
}
