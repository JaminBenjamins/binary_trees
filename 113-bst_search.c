#include "binary_trees.h"

/**
 * bst_search - searches for a value in a binary tree
 * @tree: pointer to the root node of the bst
 * @value: value to search for in bst
 *  Return: pointer to value, NULL if value not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
