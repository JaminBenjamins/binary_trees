#include "binary_trees.h"

/**
 * binary_tree_balance - a function that calculates balance of a tree
 * @tree: pointer to the root node of the tree
 *
 * Return: 0 if NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
	return (0);
}

/**
 * binary_tree_height - a function that calculates height of a tree
 * @tree: the pointer to root node of the tree
 *
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree)
	{
		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return (l > r ? l : r);
	}
	return (0);
}
