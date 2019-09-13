/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:30:02 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/12 10:30:04 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int 	findSize(struct s_player **players)
{
	int i;

	i = 0;
	while (players[i])
		i++;
	return (i);
}

int		partition(struct s_player **players, int low, int high)
{
	int i;
	int j;
	int piviot;
	struct s_player *temp;

	i = low;
	j = low;
	piviot = players[high]->score;
	while (j < high)
	{
		if (players[j]->score > piviot)
		{
			temp = players[i];
			players[i] = players[j];
			players[j] = temp;
			i++;
		}
		j++;
	}
	temp = players[i];
	players[i] = players[high];
	players[high] = temp;
	return (i);
}

void	sortPlayers(struct s_player **players, int low, int high)
{
	int piviot;

	if (low < high)
	{
		piviot = partition(players, low, high);
		sortPlayers(players, low, piviot - 1);
		sortPlayers(players, piviot + 1, high);
	}
}

void quickSort(struct s_player **players)
{
	int size;
	
	size = findSize(players);
	sortPlayers(players, 0, size - 1);
}