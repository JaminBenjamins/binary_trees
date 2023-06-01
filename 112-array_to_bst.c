#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tree from an array
 *
 * @array: pointer to the first element of array
 * @size: number of elements in the array
 * Return: pointer to the root node of BST,
 * NULL if fails
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t length;
	bst_t *tree = NULL;

	for (length = 0; length < size; length++)
		bst_insert(&tree, array[length]);

	return (tree);
