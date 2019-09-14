/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:22:07 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/13 14:22:08 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node *createNode(int value)
{
	struct s_node *node;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

struct s_node *traverse(int *arr, int start, int end)
{
	struct s_node *root;
	int piviot;

	root = NULL;
	if (start <= end)
	{
		piviot = (start + end) / 2;
		root = createNode(arr[piviot]);
		root->left = traverse(arr, start, piviot - 1);
		root->right = traverse(arr, piviot + 1, end);
	}
	return (root);
}

struct s_node *createBST(int *arr, int n)
{
	if (n <= 0)
		return (NULL);
	return (traverse(arr, 0, n - 1));
}
