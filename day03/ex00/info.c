/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:48:32 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/13 10:48:34 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int getMin(struct s_node *root)
{
	int min;
	int temp;

	if (!root)
		return (0);
	temp = 0;
	min = root->value;
	if (root->left)
	{
		temp = getMin(root->left); 
		if (temp < min)
			min = temp;
	}
	if (root->right)
	{
		temp = getMin(root->right);
		if (temp < min)
			min = temp;
	}
	return (min);
}

int getMax(struct s_node *root)
{
	int max;
	int temp;

	if (!root)
		return (0);
	temp = 0;
	max = root->value;
	if (root->left)
	{
		temp = getMax(root->left); 
		if (temp > max)
			max = temp;
	}
	if (root->right)
	{
		temp = getMax(root->right);
		if (temp > max)
			max = temp;
	}
	return (max);
}

int getElements(struct s_node *root)
{
	int elem;

	if (!root)
		return (0);
	elem = getElements(root->left) + getElements(root->right) + 1;
	return (elem);
}

int getHeight(struct s_node *root)
{
	int h;
	int temp;

	if (!root)
		return (0);
	temp = 0;
	h = 1;
	if (root->left)
	{
		temp = getHeight(root->left) + 1; 
		if (temp > h)
			h = temp;
	}
	if (root->right)
	{
		temp = getHeight(root->right) + 1;
		if (temp > h)
			h = temp;
	}
	return (h);
}

int isBST(struct s_node *root)
{
	if (!root)
		return (1);
	if (root->left && getMax(root->left) > root->value)
		return (0);
	if (root->right && getMin(root->right) <= root->value)
		return (0);
	if (!isBST(root->left) || !isBST(root->right))
		return (0);
	return (1);
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

int isBalanced(struct s_node *root)
{
	int left;
	int right;

	if (!root)
		return (1);
	left = getHeight(root->left);
	right = getHeight(root->right);
	if (abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return (1);
	return (0);
}

struct s_info   getInfo(struct s_node *root)
{
	struct s_info info;
	
	info.min = getMin(root);
	info.max = getMax(root);
	info.elements = getElements(root);
	info.height = getHeight(root);
	info.isBST = isBST(root);
	info.isBalanced = isBalanced(root);
	return (info);
}
