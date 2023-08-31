#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: If no common ancestors return NULL, else return common ancestor.
 */

binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *xx1, *xx2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	xx1 = first->parent, xx2 = second->parent;
	if (first == xx2 || !xx1 || (!xx1->parent && xx2))
		return (binary_trees_ancestor(first, xx2));
	else if (xx1 == second || !xx2 || (!xx2->parent && xx1))
		return (binary_trees_ancestor(xx1, second));
	return (binary_trees_ancestor(xx1, xx2));
}
