#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 * Return: A pointer to the new root node after rotation.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *xxx, *a;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	xxx = tree->right;
	a = xxx->left;
	xxx->left = tree;
	tree->right = a;
	if (a != NULL)
		a->parent = tree;
	a = tree->parent;
	tree->parent = xxx;
	xxx->parent = a;
	if (a != NULL)
	{
		if (a->left == tree)
			a->left = xxx;
		else
			a->right = xxx;
	}

	return (xxx);
}
