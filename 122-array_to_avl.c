#include "binary_trees.h"

/**
 * array_to_avl - convert an array to avl binary tree
 * @array: pointer to first element in array of the tree
 * @size: number of elements in the array
 *
 * Return: pointer to the root node
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t index;
	avl_t *root =  NULL;

	if (!array || size == 0)
		return (NULL);

	root = avl_insert(&root, array[0]);
	for (index = 1; index < size; index++)
		avl_insert(&root, array[index]);
	return (root);
}
