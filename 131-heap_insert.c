#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: A pointer to the parent of the node to create.
 * @value: The value to put in the new node.
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *xxx;

	xxx = malloc(sizeof(binary_tree_t));
	if (xxx == NULL)
		return (NULL);

	xxx->n = value;
	xxx->parent = parent;
	xxx->left = NULL;
	xxx->right = NULL;

	return (xxx);
}

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node
 *         NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *a, *xx1, *xx2;
	int z, n, s, z1, l, a1;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	a = *root;
	z = binary_tree_size(a);
	n = z;
	for (l = 0, s = 1; n >= s; s *= 2, l++)
		n -= s;

	for (z1 = 1 << (l - 1); z1 != 1; z1 >>= 1)
		a = n & z1 ? a->right : a->left;

	xx1 = binary_tree_node(a, value);
	n & 1 ? (a->right = xx1) : (a->left = xx1);

	xx2 = xx1;
	for (; xx2->parent && (xx2->n > xx2->parent->n); xx2 = xx2->parent)
	{
		a1 = xx2->n;
		xx2->n = xx2->parent->n;
		xx2->parent->n = a1;
		xx1 = xx1->parent;
	}

	return (xx1);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @a: tree to measure the size of
 * Return: size of the tree
 *         0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *a)
{
	if (!a)
		return (0);

	return (binary_tree_size(a->left) + binary_tree_size(a->right) + 1);
}
