/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:46:58 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/12 10:47:00 by kdenisov         ###   ########.fr       */
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

void	merge(struct s_player **players, int left, int middle, int right)
{
	int i;
	int j;
	int k;
	int l;
	int r;
	
	l = middle - left + 1;
	r = right - middle;
	struct s_player *lhalf[l];
	struct s_player *rhalf[r];
	i = 0;
	while (i < l)
	{
		lhalf[i] = players[left + i];
		i++;
	}
	j = 0;
	while (j < r)
	{
		rhalf[j] = players[middle + 1 + j];
		j++;
	}
	i = 0;
	j = 0;
	k = left;
	while (i < l && j < r)
	{
		if (lhalf[i]->score >= rhalf[j]->score)
		{
			players[k] = lhalf[i];
			i++;
		}
		else
		{
			players[k] = rhalf[j];
			j++;
		}
		k++;
	}
	while (i < l)
	{
		players[k] = lhalf[i];
		i++;
		k++;
	}
	while (j < r)
	{
		players[k] = rhalf[j];
		j++;
		k++;
	}
}

void	sortPlayers(struct s_player **players, int left, int right)
{
	int middle;

	if (left < right)
	{
		middle = left + (right - left) / 2;
		sortPlayers(players, left, middle);
		sortPlayers(players, middle + 1, right);
		merge(players, left, middle, right);
	}
}

struct s_player **mergeSort(struct s_player **players)
{
	sortPlayers(players, 0, findSize(players) - 1);
	return (players);
}
