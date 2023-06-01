#include "binary_trees.h"

/**
 * bal: measures balance factor of an AVL
 * @tree: pointer root node to check
 *
 * Return: balanced factor
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - get the minimum node in right subtree
 * @node: pointer to node of root to check
 * Return: the minimum value of this tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
		return (0);
	left = successor(node->left);
	if (left == 0)
		return (node->n);
	return (left);
	}
}

/**
 * remove_type - function that removes node
 * @root: pointer to node to remove
 * Return:  1 if has children, 0 otherwise
 */
int remove_type(bst_t *root)
{
	int new_value;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;


		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}


/**
 * bst_remove - remove a node from bst tree
 * @root: the pointer to node of the tree
 * @value: node with value to remove
 * Return: changed oregana
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from AVL tree
 * @root: pointer to root node of a tree
 * @value: node with value to remove
 * 
 * Return: root node of tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *)bst_remove((avl_t *)root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
