#include "binary_trees.h"
#include <limits.h>

size_t mos_lenght(const binary_tree_t *tree);
int mos_validation(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * mos_lenght - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, your function must return 0, else return height.
 */

size_t mos_lenght(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t x1 = 0, x2 = 0;

		x1 = tree->left ? 1 + mos_lenght(tree->left) : 1;
		x2 = tree->right ? 1 + mos_lenght(tree->right) : 1;
		return ((x1 > x2) ? x1 : x2);
	}
	return (0);
}

/**
 * mos_validation - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */

int mos_validation(const binary_tree_t *tree, int lo, int hi)
{
	size_t x1, x2, a;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		x1 = mos_lenght(tree->left);
		x2 = mos_lenght(tree->right);
		a = x1 > x2 ? x1 - x2 : x2 - x1;
		if (a > 1)
			return (0);
		return (mos_validation(tree->left, lo, tree->n - 1) &&
			mos_validation(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (mos_validation(tree, INT_MIN, INT_MAX));
}
