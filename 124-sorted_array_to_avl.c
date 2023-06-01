#include "binary_trees.h"

/**
 * sorted_array_to_avl_recursive - make array to avl recursively
 * @array: pointer to array to convert
 * @findex: initial index of subarray
 * @lindex:final index of subarray
 *
 * Return: pointer to the root node of a tree
 */
avl_t *sorted_array_to_avl_recursive(int *array, int findex, int lindex)
{
	avl_t *root;
	int half;

	if (lindex < findex)
		return (NULL);

	half = (findex + lindex) / 2;

	/* Create binary tree with root equal to half */
	root = binary_tree_node(NULL, array[half]);
	if (!root)
		return (NULL);

	/* Sort the branches */
	root->left = sorted_array_to_avl_recursive(array, findex, half - 1);
	root->right = sorted_array_to_avl_recursive(array, half + 1, lindex);
	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;
	return (root);
}


/**
 * sorted_array_to_avl - builds an AVL tree from array
 * @array: pointer to first element in array
 * @size: number of elements in arraya
 *
 * Return: pointer to root node of created AVL
 */
avl_t *sorted_array_to_avl(int *array, int size)
{
	if (!array || size == 0)
		return (NULL);
	return (sorted_array_to_avl_recursive(array, 0, size - 1));
}

