#include "binary_trees.h"

/**
 * binary_tree_sibling - a function that checks if a node has siblings
 * @node: pointer to node to check
 *
 * Return: 1 if node has sibing, 0 otherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (0);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
