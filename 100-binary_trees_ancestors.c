#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of a node
 * @first: the first node to check
 * @second: second node to check
 *
 * Return: node to the lowest common ancestor
 */
binary_tree_t *binary_tree_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *f, *s;

	for (f = first; f; f = f->parent)
		for (s = second; s; s = s->parent)
			if (f == s)
				return ((binary_tree_t *)f);
	return (NULL);
}
