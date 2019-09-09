/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:36:17 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/09 11:36:19 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int 	findSize(struct s_art **arts)
{
	int i;

	i = 0;
	while (arts[i])
		i++;
	return (i);
}

int		partition(struct s_art **arts, int left, int right)
{
	int i;
	int j;
	char *piviot;
	struct s_art *temp;

	i = left;
	j = left;
	piviot = arts[right]->name;
	while (j < right)
	{
		if (strcmp(arts[j]->name, piviot) < 0)
		{
			temp = arts[i];
			arts[i] = arts[j];
			arts[j] = temp;
			i++;
		}
		j++;
	}
	temp = arts[i];
	arts[i] = arts[right];
	arts[right] = temp;
	return (i);
}

void	quickSort(struct s_art **arts, int left, int right)
{
	int i;

	if (left >= right)
		return ;
	i = partition(arts, left, right);
	quickSort(arts, left, i - 1);
	quickSort(arts, i + 1, right);
}

void	sortArts(struct s_art **arts)
{
	int size;
	
	size = findSize(arts);
	quickSort(arts, 0, size - 1);
}
