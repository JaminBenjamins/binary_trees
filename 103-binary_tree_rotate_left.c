#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a left rotation of a tree
 * @tree: pointer to root node of the tree
 *
 * Return: pointer root node of the tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *child, *parent = tree;

	if (!tree)
		return (NULL);

	child = parent->right;
	if (!child)
		return (tree);

	if (child->left)
		child->left->parent = parent;

	parent->right = child->left;
	child->left = parent;
	child->parent = parent->parent;
	parent->parent = child;

	if (child->parent && child->parent->left == parent)
		child->parent->left = child;
	else if (child->parent)
		child->parent->right = child;

	return (child);
}
