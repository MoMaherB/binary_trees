#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to put in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 *
 * Description: If parent already has a right-child, the new node takes its
 *              place, and the old right-child is set as the right-child of
 *              the new node.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_right_child;

	 if (parent == NULL)
	 	return (NULL);

	new_right_child = malloc(sizeof(binary_tree_t));

	if (new_right_child == NULL)
		return (NULL);

	new_right_child->parent = parent;
	new_right_child->n = value;
	new_right_child->left = NULL;
	new_right_child->right = parent->right;
	if (parent->right != NULL)
		parent->right->parent = new_right_child;
	parent->right = new_right_child;

	return (new_right_child);
}
