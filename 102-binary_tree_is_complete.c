#include "binary_trees.h"

/**
 * count_nodes - counts the nodes in a tree
 * @root: node
 *
 * Return: number of nodes
 */
int count_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);
	return (1 + count_nodes(root->left) + count_nodess(root->right));
}

/**
 * is_complete - checks if a tree is complete
 * @root: pointer to root node of the tree
 * @index: index of node to be evaluated
 * @n: number of trees in a node
 *
 * Return: 1 if tree is a heap, 0 otherwise
 */
int is_complete(binary_tree_t *root, int index, int n)
{
	if (!root)
		return (0);
	if (index >= n)
		return (0);
	if (!root->left && !root->right)
		return (1);
	if (root->right && !root->left)
		return (0);
	if (root->left && !root->right)
		return (is_complete(root->left, index * 2 + 1, n));

	return (is_complete(root->left, index * 2 + 1, n) &&
			is_complete(root->right, index * 2 + 2, n));
}

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node;
	binary_tree_t *root;

	if (!tree)
		return (0);
	root = (binary_tree_t *)tree;
	node = count_nodes(root);

	return (is_complete(root, 0, node));
}
