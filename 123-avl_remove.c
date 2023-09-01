#include "binary_trees.h"

/**
 * mos_balance_factor - Measures balance factor of a AVL
 * @tree: tree to go through
 * Return: balanced factor
 */

void mos_balance_factor(avl_t **tree)
{
	int a;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	mos_balance_factor(&(*tree)->left);
	mos_balance_factor(&(*tree)->right);
	a = binary_tree_balance((const binary_tree_t *)*tree);
	if (a > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (a < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * mos_get_specific_node - get the next successor
 * i mean the min node in the right subtree
 * @node: tree to check
 * Return: the min value of this tree
 */

int mos_get_specific_node(bst_t *node)
{
	int a = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		a = mos_get_specific_node(node->left);
		if (a == 0)
		{
			return (node->n);
		}
		return (a);
	}
}

/**
 *mos_remove_node - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */

int mos_remove_node(bst_t *root)
{
	int xx = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		xx = mos_get_specific_node(root->right);
		root->n = xx;
		return (xx);
	}
}

/**
 * mos_remove_bst_node - remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */

bst_t *mos_remove_bst_node(bst_t *root, int value)
{
	int a = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		mos_remove_bst_node(root->left, value);
	else if (value > root->n)
		mos_remove_bst_node(root->right, value);
	else if (value == root->n)
	{
		a = mos_remove_node(root);
		if (a != 0)
			mos_remove_bst_node(root->right, a);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *xx = (avl_t *) mos_remove_bst_node((bst_t *) root, value);

	if (xx == NULL)
		return (NULL);
	mos_balance_factor(&xx);
	return (xx);
}
