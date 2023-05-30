#include "binary_trees.h"

/**
 * binary_tree_preorder - a function that traverses a binary tree in preorder
 * @tree: Pointer to root node to traverse
 * @func: pointer to a function to call after each node
 * Return: nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
