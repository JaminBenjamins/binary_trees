#include "binary_trees.h"

/**
 * binary_tree_uncle - a function that checks if a function is uncle of a node
 * @node: a pointer to node to find uncle
 *
 * Return: NULL if node doesn't exist or is NULL
 * Otherwise pointer to node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent->parent == NULL)
		return (NULL);
	if ((node->parent->parent->left) == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
