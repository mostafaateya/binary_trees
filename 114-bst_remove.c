#include "binary_trees.h"

bst_t *mos_min_value(bst_t *root);
bst_t *mos_del_node(bst_t *root, bst_t *node);
bst_t *mos_del_node_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * mos_min_value - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 * Return: The minimum value in @tree.
 */

bst_t *mos_min_value(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * mos_del_node - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 * Return: A pointer to the new root node after deletion.
 */

bst_t *mos_del_node(bst_t *root, bst_t *node)
{
	bst_t *x = node->parent, *xx = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (x != NULL && x->left == node)
			x->left = node->right;
		else if (x != NULL)
			x->right = node->right;
		if (node->right != NULL)
			node->right->parent = x;
		free(node);
		return (x == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (x != NULL && x->left == node)
			x->left = node->left;
		else if (x != NULL)
			x->right = node->left;
		if (node->left != NULL)
			node->left->parent = x;
		free(node);
		return (x == NULL ? node->left : root);
	}

	xx = mos_min_value(node->right);
	node->n = xx->n;

	return (mos_del_node(root, xx));
}

/**
 * mos_del_node_recursive - Removes a node from a binary
 * search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 * Return: A pointer to the root node after deletion.
 */

bst_t *mos_del_node_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (mos_del_node(root, node));
		if (node->n > value)
			return (mos_del_node_recursive(root, node->left, value));
		return (mos_del_node_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 * Return: A pointer to the new root node after deletion.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	return (mos_del_node_recursive(root, root, value));
}
