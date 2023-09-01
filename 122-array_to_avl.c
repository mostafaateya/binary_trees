#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *a = NULL;
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
			if (avl_insert(&a, array[x1]) == NULL)
				return (NULL);
		}
	}

	return (a);
}
