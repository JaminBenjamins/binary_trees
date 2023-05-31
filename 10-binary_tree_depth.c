#include "binary_trees.h"

/**
 * binary_tree_depth - Measure depth of the node of a tree
 * @tree: pointer to the tree to measure
 *
 * Return: integer representative of a tree depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
