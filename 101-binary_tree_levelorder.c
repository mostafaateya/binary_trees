#include "binary_trees.h"

/**
 * struct node_s - singly linked list
 * @node: const binary tree node
 * @next: points to the next node
 */

typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} mos_node;

mos_node *mos_add_node(mos_node *head, const binary_tree_t *btnode);
void mos_free(mos_node *head);
mos_node *mos_get_child(mos_node *head, const binary_tree_t *parent);
void mos_call_func(mos_node *head, void (*func)(int));

/**
 * binary_tree_levelorder - Goes through a binary tree
 *                          using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	mos_node *xxx = NULL;

	func(tree->n);
	xxx = mos_get_child(xxx, tree);
	mos_call_func(xxx, func);

	mos_free(xxx);
}

/**
 * mos_call_func - Calls func on all nodes at each level.
 * @head: Pointer to head of linked list with nodes at one level.
 * @func: Pointer to a function to call for each node.
 */

void mos_call_func(mos_node *head, void (*func)(int))
{
	mos_node *xxx = NULL, *curr = NULL;

	if (!head)
		return;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		xxx = mos_get_child(xxx, curr->node);
	}
	mos_call_func(xxx, func);
	mos_free(xxx);
}

/**
 * mos_get_child - appends children of parent to linked list.
 * @head: Pointer to head of linked list where children will be appended.
 * @parent: Pointer to node whose children we want to append.
 * Return: Pointer to head of linked list of children.
 */

mos_node *mos_get_child(mos_node *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = mos_add_node(head, parent->left);
	if (parent->right)
		head = mos_add_node(head, parent->right);
	return (head);
}

/**
 * mos_add_node - adds a new node at the end of a linkedlist
 * @head: pointer to head of linked list
 * @btnode: const binary tree node to append
 * Return: pointer to head, or NULL on failure
 */

mos_node *mos_add_node(mos_node *head, const binary_tree_t *btnode)
{
	mos_node *xx = NULL, *a = NULL;

	xx = malloc(sizeof(*xx));
	if (xx)
	{
		xx->node = btnode;
		xx->next = NULL;
		if (!head)
			head = xx;
		else
		{
			a = head;
			while (a->next)
				a = a->next;
			a->next = xx;
		}
	}
	return (head);
}

/**
 * mos_free - frees all the nodes in a linked list
 * @head: pointer to the head of list_t linked list
 */

void mos_free(mos_node *head)
{
	mos_node *a = NULL;

	while (head)
	{
		a = head->next;
		free(head);
		head = a;
	}
}
