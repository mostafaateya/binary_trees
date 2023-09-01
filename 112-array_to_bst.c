#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *xxx = NULL;
	size_t x1, x2;

	if (array == NULL)
		return (NULL);

	for (x1 = 0; x1 < size; x1++)
	{
		for (x2 = 0; x2 < x1; x2++)
		{
			if (array[x2] == array[x1])
				break;
		}
		if (x2 == x1)
		{
			if (bst_insert(&xxx, array[x1]) == NULL)
				return (NULL);
		}
	}

	return (xxx);
}
