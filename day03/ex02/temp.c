#include "header.h"
#include <stdio.h>

static int first;
static int second;

struct s_node *lowestCommonAncestor(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	int i;
	int find;
	struct s_node *node;
	struct s_node *temp;

	node = NULL;
	i = 0;
	find = 0;
	if (!root)
		return (NULL);
	if (!strcmp(root->name, firstSpecies))
	{
		first = 1;
		return (root);
	}
	if (!strcmp(root->name, secondSpecies))
	{
		second = 1;
		return (root);
	}
	while (root->children[i])
	{
		temp = lowestCommonAncestor(root->children[i], firstSpecies, secondSpecies);
		if (temp)
		{
			node = temp;
			find++;
			if (find == 2)
				return (root);		
		}
		i++;
	}
	return (node);
}

int findPath(struct s_node *root, char *species)
{
	int i;

	i = 0;
	if (!root)
		return (0);
	if (!strcmp(root->name, species))
		return (1);
	while (root->children[i])
	{
		if (findPath(root->children[i], species))
			return (1);
		i++;
	}
	return (0);
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	struct s_node *ancestor;
	
	first = 0;
	second = 0;
	ancestor = lowestCommonAncestor(root, firstSpecies, secondSpecies);
	if (first && second)
		return (ancestor);
	//printf("first = %d, second = %d\n", first, second);
	return(NULL);
}



// static int bal;

// int checkLevel(struct s_node *root, int level)
// {
// 	int left;
// 	int right;

// 	if (!root)
// 		return (level);
// 	left = checkLevel(root->left, level + 1);
// 	right = checkLevel(root->right, level + 1);
// 	if (abs(left - right) > 1)
// 		bal = 0;
// 	return (ft_max(left, right));
// }

// int isBalanced(struct s_node *root)
// {	
// 	bal = 1;
// 	checkLevel(root, 0);
// 	return (bal);
// }