#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 * Return: A pointer to the new root node after rotation.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *xx, *a;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	xx = tree->left;
	a = xx->right;
	xx->right = tree;
	tree->left = a;
	if (a != NULL)
		a->parent = tree;
	a = tree->parent;
	tree->parent = xx;
	xx->parent = a;
	if (a != NULL)
	{
		if (a->left == tree)
			a->left = xx;
		else
			a->right = xx;
	}

	return (xx);
}
