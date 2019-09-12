/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:27:11 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/11 18:27:13 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void insertionSort(struct s_player **players)
{
	int i;
	int j;
	struct s_player *current;

	i = 0;
	while (players[i])
	{
		current = players[i];
		j = i;
		while (j > 0 && players[j - 1]->score < current->score)
		{
			players[j] = players[j - 1];
			j--;
		}
		players[j] = current;
		i++;
	}
}
