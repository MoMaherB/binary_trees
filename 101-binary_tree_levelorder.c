#include "binary_trees.h"
#include <stdlib.h>

/**
 * resize_queue - Resizes the queue to a new size
 * @queue: Pointer to the current queue
 * @size: Pointer to the current size of the queue
 *
 * Return: Pointer to the resized queue, or NULL on failure
 */
binary_tree_t **resize_queue(binary_tree_t **queue, size_t *size)
{
	size_t new_size = *size * 2;
	binary_tree_t **new_queue;
	size_t k;

	new_queue = malloc(new_size * sizeof(binary_tree_t *));
	if (new_queue == NULL)
	{
		free(queue);
		return (NULL);
	}
	for (k = 0; k < *size; k++)
		new_queue[k] = queue[k];
	free(queue);
	*size = new_size;

	return (new_queue);
}

/**
 * binary_tree_levelorder - binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue, *node;
	size_t size = 1024, i = 0, j = 0;

	if (tree == NULL || func == NULL)
		return;
	queue = malloc(size * sizeof(binary_tree_t *));
	if (queue == NULL)
		return;

	queue[i] = (binary_tree_t *)tree;
	i++;

	while (j < i)
	{
		node = queue[j];
		j++;
		func(node->n);
		if (node->left)
		{
			queue[i] = node->left;
			i++;
		}
		if (node->right)
		{
			queue[i] = node->right;
			i++;
		}
		if (i >= size)
		{
			queue = resize_queue(queue, &size);
			if (queue == NULL)
				return;
		}
	}
	free(queue);
}
