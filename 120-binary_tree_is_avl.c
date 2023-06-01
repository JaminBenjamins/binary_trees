#include "binary_trees.h"

/**
 * tree_height - finding the height of a tree
 * @tree: pointer to root of a tree
 * Return: integer with level
 */
int tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	left = tree_height(tree->left);
	right = tree_height(tree->right);
	if (left > right)
		return (left + 1);
	return (right + 1);
}

/**
 * bt_balance - checks height difference of a tree
 * @tree: pointer to the root node
 * Return: difference of height
 */
int bt_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_height(tree->left) - tree_height(tree->right));
}

/**
 * bavl - checks if a function is AVL tree
 * @tree: pointer to the root node
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if is AVL, 0 otherwise
 */
int bavl(const binary_tree_t *tree, int min, int max)
{
	int bleft, bright, bal;

	if (tree == NULL)
		return (1);
	if (tree->n > max || tree->n < min)
		return (0);
	bal = bt_balance(tree);
	if (bal < -1 || bal > 1)
		return (0);
	bleft = bavl(tree->left, min, tree->n - 1);
	bright = bavl(tree->right, tree->n + 1, max);
	if (bleft == 1 && bright == 1)
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - checks if binary tree is valid AVL tree
 * @tree: pointer to root node of tree
 *
 * Return: 1 if tree is AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bavl(tree, INT_MIN, INT_MAX));
}
