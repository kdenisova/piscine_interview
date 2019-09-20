/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:49:48 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/19 13:49:50 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_swap(struct s_art **masterpiece, int i, int j)
{
	struct s_art *temp;

	temp = masterpiece[i];
	masterpiece[i] = masterpiece[j];
	masterpiece[j] = temp;
}

void	heapify(struct s_art **masterpiece, int n, int root)
{
	int max = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left < n && strcmp(masterpiece[left]->name, masterpiece[max]->name) > 0)
		max = left;
	if (right < n && strcmp(masterpiece[right]->name, masterpiece[max]->name) > 0)
		max = right;
	if (max != root)
	{
		ft_swap(masterpiece, root, max);
		heapify(masterpiece, n, max);
	}
}

void	heapSort(struct s_art **masterpiece, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(masterpiece, n, i);
	for (int i = n - 1; i >= 1; i--)
	{
		ft_swap(masterpiece, 0, i);
		heapify(masterpiece, i, 0);
	}
}
