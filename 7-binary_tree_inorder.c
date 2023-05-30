#include "binary_trees.h"

/**
 * binary_tree_inorder -a function that traverses a tree inorder
 * @tree: pointer to root node to traverse
 * @func: pointer to function to call at each node
 *
 * Return: nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void(*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left);
		func(tree->n);
		binary_tree_inorder(tree->right);
	}
}
