#include "binary_trees.h"

size_t mos_lenght(const binary_tree_t *tree);
int mos_balance(const binary_tree_t *tree);
avl_t *mos_insert_value(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * mos_lenght - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, your function must return 0, else return height.
 */

size_t mos_lenght(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t x1 = 0, x2 = 0;

		x1 = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		x2 = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((x1 > x2) ? x1 : x2);
	}
	return (0);
}

/**
 * mos_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 * Return: If tree is NULL, return 0, else return balance factor.
 */

int mos_balance(const binary_tree_t *tree)
{
	return (tree != NULL ? mos_lenght(tree->left) - mos_lenght(tree->right) : 0);
}

/**
 * mos_insert_value - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */

avl_t *mos_insert_value(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int xxx;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = mos_insert_value(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = mos_insert_value(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	xxx = mos_balance(*tree);
	if (xxx > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (xxx < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (xxx > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (xxx < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 * Return: A pointer to the inserted node, or NULL on failure.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *a = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	mos_insert_value(tree, *tree, &a, value);
	return (a);
}
