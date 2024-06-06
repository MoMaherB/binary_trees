#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle node of a given node in a binary tree
 * @node: Pointer to the node to find the uncle of
 *
 * Return: Pointer to the uncle node if it exists, NULL otherwise
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	if (node->parent == node->parent->parent->right)
		return (node->parent->parent->left);
	return (node->parent->parent->right);
}
