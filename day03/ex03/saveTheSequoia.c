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

int ft_left(int i)
{
	return (2 * i + 1);
}

int ft_right(int i)
{
	return (2 * i + 2);
}

void 	swap(struct s_criminal **criminals)
{
	int i;

	i = 0;
	while (criminals[i])
		i++;
	return (i);
}

void	convertHeap(struct s_node **root)
{
	int n;
	struct s_node *current;

	current = *root;
	if (current->right &&)
}

void	saveTheSequoia(struct s_node **root)
{

}


