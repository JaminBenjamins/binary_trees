#include "binary_trees.h"

/**
 * is_full_recursive - a function that checks if a tree is full recursively
 * @tree: pointer to the root node of the tree
 *
 * Return: number of full nodes
 */
 int is_full_recursive(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((tree->left == NULL && tree->right != NULL) ||
			(tree->left != NULL && tree->right == NULL) ||
			 is_full_recursive(tree->left) == 0 ||
			 is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - a function that checks if a function is full 
 * @tree: a pointer to the root node of the tree
 *
 * Return: 1 if node is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}
