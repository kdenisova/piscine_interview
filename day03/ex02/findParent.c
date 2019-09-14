/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:15:13 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/13 15:15:15 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int first;
static int second;

struct s_node *lowestCommonAncestor(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	int i;
	int find;
	struct s_node *node;
	struct s_node *temp;

	i = 0;
	find = 0;
	node = NULL;
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

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	struct s_node *ancestor;
	
	first = 0;
	second = 0;
	ancestor = lowestCommonAncestor(root, firstSpecies, secondSpecies);
	if (first && second)
		return (ancestor);
	return(NULL);
}
