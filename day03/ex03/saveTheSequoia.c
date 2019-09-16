/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:06:12 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/13 19:06:14 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swapRight(struct s_node **root, struct s_node **node)
{
	struct s_node *temp;

	temp = *root;
	*root = *node;
	*node = temp;
	temp = (*root)->left;
	(*root)->left = (*node)->left;
	(*node)->left = temp;
	temp = (*root)->right;
	(*root)->right = (*node)->right;
	(*node)->right = temp;
}

void swapLeft(struct s_node **root, struct s_node **node)
{
	struct s_node *temp;

	temp = *root;
	*root = *node;
	*node = temp;
	temp = (*root)->right;
	(*root)->right = (*node)->right;
	(*node)->right = temp;
	temp = (*root)->left;
	(*root)->left = (*node)->left;
	(*node)->left = temp;
}

int	convertHeap(struct s_node **root)
{
	int n;

	if (!(*root))
		return (0);
	n = 1;
	if ((*root)->right && (*root)->right->value > (*root)->value)
		swapRight(root, &(*root)->right);
	if ((*root)->left && (*root)->left->value > (*root)->value)
		swapLeft(root, &(*root)->left);
	n = n + convertHeap(&(*root)->right) + convertHeap(&(*root)->left);
	return (n);
}

void	saveTheSequoia(struct s_node **root)
{
	int n;
	int i;

	if (!root)
		return ;
	i = 0;
	n = convertHeap(root);
	while (i < n - 1)
	{
		convertHeap(root);
		i++;
	}
}
