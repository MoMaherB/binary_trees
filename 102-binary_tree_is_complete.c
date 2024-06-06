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
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue, *node;
	size_t size = 1024, i = 0, j = 0, gap = 0;

	if (tree == NULL)
		return (0);
	queue = malloc(size * sizeof(binary_tree_t *));
	if (queue == NULL)
		return (0);
	queue[i++] = (binary_tree_t *)tree;
	while (j < i)
	{
		node = queue[j++];
		if (node == NULL)
			gap = 1;
		else
		{
			if (gap)
			{
				free(queue);
				return (0);
			}
			queue[i++] = node->left;
			if (i >= size)
			{
				queue = resize_queue(queue, &size);
				if (queue == NULL)
				return (0);
			}
			queue[i] = node->right;
			i++;
			if (i >= size)
			{
				queue = resize_queue(queue, &size);
				if (queue == NULL)
					return (0);
			}
		}
	}
	free(queue);
	return (1);
}
