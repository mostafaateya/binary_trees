#include "binary_trees.h"

/**
 * mos_tree_size - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: Height or 0 if tree is NULL
 */

size_t mos_tree_size(const binary_tree_t *tree)
{
	size_t x1 = 0;
	size_t x2 = 0;

	if (!tree)
		return (0);

	if (tree->left)
		x1 = 1 + mos_tree_size(tree->left);

	if (tree->right)
		x2 = 1 + mos_tree_size(tree->right);

	return (x1 + x2);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: pointer to array sorted in descending order
 **/

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int z, *x = NULL;

	if (!heap || !size)
		return (NULL);

	*size = mos_tree_size(heap) + 1;

	x = malloc(sizeof(int) * (*size));

	if (!x)
		return (NULL);

	for (z = 0; heap; z++)
		x[z] = heap_extract(&heap);

	return (x);
}
