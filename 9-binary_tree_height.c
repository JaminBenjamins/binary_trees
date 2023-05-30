#include "binary_trees.h"

/**
 * binary_tree_height - measure the height of a binary tree
 * @tree:  a point to the root node of the tree
 *
 * Return: height of tree if exists
 * Otherwise: return NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
	size_t l = 0, r = 0;

	l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return ((l > r) ? l : r);
	}
}
