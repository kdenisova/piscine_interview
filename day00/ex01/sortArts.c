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

int		partition(struct s_art **arts, int low, int high)
{
	int i;
	int j;
	char *piviot;
	struct s_art *temp;

	i = low;
	j = low;
	piviot = arts[high]->name;
	while (j < high)
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
	arts[i] = arts[high];
	arts[high] = temp;
	return (i);
}

void	quickSort(struct s_art **arts, int low, int high)
{
	int piviot;

	if (low < high)
	{
		piviot = partition(arts, low, high);
		quickSort(arts, low, piviot - 1);
		quickSort(arts, piviot + 1, high);
	}
}

void	sortArts(struct s_art **arts)
{
	int size;
	
	size = findSize(arts);
	quickSort(arts, 0, size - 1);
}
