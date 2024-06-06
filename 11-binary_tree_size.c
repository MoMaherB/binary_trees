#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);
	if (tree != NULL && tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL && tree->right == NULL)
		return (1 + binary_tree_size(tree->left));
	else if (tree->left == NULL && tree->right != NULL)
		return (1 + binary_tree_size(tree->right));
	else
		return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));

}
