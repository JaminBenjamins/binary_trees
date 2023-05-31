#include "binary_trees.h"

/**
 * binary_tree_is_leaf - a function to check if a node is a leaf
 * @node: Pointer to node to check
 *
 * Return: 1 if node is leaf
 * Return 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->right == NULL || !node->left == NULL)
		return (1);
	return (0);
}
