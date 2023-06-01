#include "binary_trees.h"

/**
 * is_bst_h - compare nodes to check if is bst
 * @tree: pointer to the root node of tree
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 if success, 0 otherwise
 */
int is_bst_h(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
	{
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst_h(tree->left, min, tree->n - 1) &&
			is_bst_h(tree->right, tree->n + 1, max));
	}
	return (1);
}

/**
 * binary_tree_is_bst - checks if a binary tree is valid
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is valid bst, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_h(tree, INT_MIN, INT_MAX));
}
