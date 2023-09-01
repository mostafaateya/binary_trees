#include "binary_trees.h"

/**
 * mos_create_tree - creates an AVL tree with recursion
 * @node: pointer node
 * @array: input array of integers
 * @size: size of array
 * @mode: 1 to adding on the left, 2 to adding on the right
 * Return: no return
 */

void mos_create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t a;

	if (size == 0)
		return;

	a = (size / 2);
	a = (size % 2 == 0) ? a - 1 : a;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[a]);
		mos_create_tree(&((*node)->left), array, a, 1);
		mos_create_tree(&((*node)->left), array + a + 1, (size - 1 - a), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[a]);
		mos_create_tree(&((*node)->right), array, a, 1);
		mos_create_tree(&((*node)->right), array + a + 1, (size - 1 - a), 2);
	}
}

/**
 * sorted_array_to_avl - creates root node and calls to mos_create_tree
 * @array: input array of integers
 * @size: size of array
 * Return: pointer to the root
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *xx;
	size_t a;

	xx = NULL;

	if (size == 0)
		return (NULL);

	a = (size / 2);

	a = (size % 2 == 0) ? a - 1 : a;

	xx = binary_tree_node(xx, array[a]);

	mos_create_tree(&xx, array, a, 1);
	mos_create_tree(&xx, array + a + 1, (size - 1 - a), 2);

	return (xx);
}
