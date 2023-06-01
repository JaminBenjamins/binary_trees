#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a function that rotates a binary tree
 * to the right
 * @tree: pointer to the root node of the binary tree
 *
 * Return: pointer to the root node of rotated tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *child, *parent = tree;

	if (!tree)
		return (NULL);

	child = parent->left;
	if (!child)
		return (tree);

	if (child->right)
		child->right->parent = parent;

	parent->left = child->right;
	child->right = parent;
	child->parent = parent->parent;
	parent->parent = child;

	if (child->parent && child->parent->left == parent)
		child->parent->left = child;
	else if (child->parent)
		child->parent->right = child;

	return (child);
}
