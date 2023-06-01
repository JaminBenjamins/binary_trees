#include "binary_trees.h"

/**
 * bst_insert - insert a value to a bst
 * @tree: double pointer to root node of tree
 * @value: the value to store in node to insert
 *
 * Return: pointer to created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *tree_1;

	if (tree == NULL || *tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}

	tree_1 = *tree;

	while (tree_1 != NULL)
	{
		if (tree_1->n == value)
			return (NULL);
		if (tree_1->n > value)
		{
			if (tree_1->left == NULL)
			{
				tree_1->left = binary_tree_node(tree_1, value);
				return (tree_1->left);
			}
			tree_1 = tree_1->left;
		}
		if (tree_1->n < value)
		{
			if (tree_1->right == NULL)
			{
				tree_1->right == binary_tree_node(tree_1, value);
				return (tree_1->right);
			}
			tree_1 = tree_1->right;
		}
	}
	return (NULL);
}
