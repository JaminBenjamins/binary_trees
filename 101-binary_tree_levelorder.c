#include "binary_trees.h"

/**
 * binary_tree_height_aux - a function that finds height of a tree
 * @tree: pointer to the node
 *
 * Return: height of the tree
 */
size_t binary_tree_height_aux(const binary_tree_t *tree)
{
	size_t hleft = 0, hright = 0;

	if (!tree)
		return (0);
	if (tree->left)
		hleft = 1 + binary_tree_height_aux(tree->left);
	if (tree->right)
		hright = 1 + binary_tree_height_aux(tree->right);

	if (hleft > hright)
		return (hleft);
	return (hright);
}

/**
 * print_level_order - print each node
 * @tree: pointer to root node of tree
 * @level: the level of a tre
 * @func: pointer to a node to check
 * Return: void
 */
void print_level_order(const binary_tree_t *tree, int level, void(*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level_order(tree->left, level - 1, func);
		print_level_order(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - a  function that traverse a tree in level order
 * @tree: pointer to root node of tree
 * @func: pointer to function to call at each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0;
	int len = 1;

	if (!tree || !func)
		return;

	height = binary_tree_height_aux(tree) + 1;

	while (len <= height)
	{
		print_level_order(tree, len, func);
		len++;
	}
}
