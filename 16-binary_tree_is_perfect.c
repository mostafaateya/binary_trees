#include "binary_trees.h"

unsigned char mos_is_leaf(const binary_tree_t *node);
size_t mos_get_depth(const binary_tree_t *tree);
const binary_tree_t *mos_get_leaf(const binary_tree_t *tree);
int mos_is_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * mos_is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 * Return: If the node is a leaf, 1, otherwise, 0.
 */

unsigned char mos_is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * mos_get_depth - Returns the depth of a given
 *         node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 * Return: The depth of node.
 */

size_t mos_get_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + mos_get_depth(tree->parent) : 0);
}

/**
 * mos_get_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 * Return: A pointer to the first encountered leaf.
 */

const binary_tree_t *mos_get_leaf(const binary_tree_t *tree)
{
	if (mos_is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? mos_get_leaf(tree->left) : mos_get_leaf(tree->right));
}

/**
 * mos_is_recursive - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 * Return: If the tree is perfect, 1, otherwise 0.
 */

int mos_is_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (mos_is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (mos_is_recursive(tree->left, leaf_depth, level + 1) &&
		mos_is_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (mos_is_recursive(tree, mos_get_depth(mos_get_leaf(tree)), 0));
}
