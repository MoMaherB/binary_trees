#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to put in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 *
 * Description: If parent already has a left-child, the new node takes its
 *              place, and the old left-child is set as the left-child of
 *              the new node.
 */


binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left_child;

	if (parent == NULL)
		return (NULL);

	new_left_child = malloc(sizeof(binary_tree_t));

	if (!new_left_child)
		return (NULL);

	new_left_child->parent = parent;
	new_left_child->n = value;
	new_left_child->right = NULL;
	if (parent->left != NULL)
		parent->left->parent = new_left_child;
	new_left_child->left = parent->left;
	parent->left = new_left_child;


	return (new_left_child);

}
