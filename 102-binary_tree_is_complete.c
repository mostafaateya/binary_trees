#include "binary_trees.h"

levelorder_queue_t *mos_create_node(binary_tree_t *node);
void mos_free_queu(levelorder_queue_t *head);
void mos_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void mos_pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * mos_create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */

levelorder_queue_t *mos_create_node(binary_tree_t *node)
{
	levelorder_queue_t *x;

	x = malloc(sizeof(levelorder_queue_t));
	if (x == NULL)
		return (NULL);

	x->node = node;
	x->next = NULL;

	return (x);
}

/**
 * mos_free_queu - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */

void mos_free_queu(levelorder_queue_t *head)
{
	levelorder_queue_t *a;

	while (head != NULL)
	{
		a = head->next;
		free(head);
		head = a;
	}
}

/**
 * mos_push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 */

void mos_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *a;

	a = mos_create_node(node);
	if (a == NULL)
	{
		mos_free_queu(head);
		exit(1);
	}
	(*tail)->next = a;
	*tail = a;
}

/**
 * mos_pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */

void mos_pop(levelorder_queue_t **head)
{
	levelorder_queue_t *a;

	a = (*head)->next;
	free(*head);
	*head = a;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *xx1, *xx2;
	unsigned char z = 0;

	if (tree == NULL)
		return (0);

	xx1 = xx2 = mos_create_node((binary_tree_t *)tree);
	if (xx1 == NULL)
		exit(1);

	while (xx1 != NULL)
	{
		if (xx1->node->left != NULL)
		{
			if (z == 1)
			{
				mos_free_queu(xx1);
				return (0);
			}
			mos_push(xx1->node->left, xx1, &xx2);
		}
		else
			z = 1;
		if (xx1->node->right != NULL)
		{
			if (z == 1)
			{
				mos_free_queu(xx1);
				return (0);
			}
			mos_push(xx1->node->right, xx1, &xx2);
		}
		else
			z = 1;
		mos_pop(&xx1);
	}
	return (1);
}
