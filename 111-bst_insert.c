#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *a, *xx;

	if (tree != NULL)
	{
		a = *tree;

		if (a == NULL)
		{
			xx = binary_tree_node(a, value);
			if (xx == NULL)
				return (NULL);
			return (*tree = xx);
		}

		if (value < a->n) /* insert in left subtree */
		{
			if (a->left != NULL)
				return (bst_insert(&a->left, value));

			xx = binary_tree_node(a, value);
			if (xx == NULL)
				return (NULL);
			return (a->left = xx);
		}
		if (value > a->n) /* insert in right subtree */
		{
			if (a->right != NULL)
				return (bst_insert(&a->right, value));

			xx = binary_tree_node(a, value);
			if (xx == NULL)
				return (NULL);
			return (a->right = xx);
		}
	}
	return (NULL);
}
