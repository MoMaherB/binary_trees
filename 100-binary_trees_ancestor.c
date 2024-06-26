#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 *         NULL if no common ancestor is found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	const binary_tree_t *temp1, *temp2;

	if (!first || !second)
		return (NULL);

	temp1 = first;
	temp2 = second;

	while (temp1 != temp2)
	{
		if (temp1)
			temp1 = temp1->parent;
		else
			temp1 = second;

		if (temp2)
			temp2 = temp2->parent;
		else
			temp2 = first;

	}

	return ((binary_tree_t *)temp1);
}
