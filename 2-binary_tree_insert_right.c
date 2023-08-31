#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child
 *                            of another in a binary tree.
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *xxx;

	if (parent == NULL)
		return (NULL);

	xxx = binary_tree_node(parent, value);
	if (xxx == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		xxx->right = parent->right;
		parent->right->parent = xxx;
	}
	parent->right = xxx;

	return (xxx);
}
