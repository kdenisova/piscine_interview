/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:14:56 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/11 15:14:58 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	findSize(struct s_stone *stone)
{
	struct s_stone *current;
	int count;
	int size;

	size = 0;
	count = 0;
	current = stone;
	while (current)
	{
		if (size != current->size)
		{
			size = current->size;
			count++;
		}
		current = current->next;
	}
	return (count);
}

void	fillCell(struct s_stone *stone, struct s_stone **cells)
{
	struct s_stone *current;
	int i;
	int size;

	size = 0;
	i = 0;
	current = stone;
	while (current)
	{
		if (size != current->size)
		{
			cells[i] = current;
			size = current->size;
			i++;
		}
		current = current->next;
	}
}

struct s_stone *updateStones(struct s_stone **cells, int size)
{
	struct s_stone *stone;
	struct s_stone *current;

	int i;

	i = 0;
	while (i < size)
	{
		current = cells[i];
		while (current->next && current->next->size == current->size)
			current = current->next;
		stone = current;
		if (i < size - 1)
			stone->next = cells[i + 1];
		else
			stone->next = NULL;
		i++;
	}
	return (cells[0]);
}

void sortStones(struct s_stone **stone)
{
	struct s_stone *temp;
	int i;
	int j;
	int size;

	if (!stone)
		return ;
	size = findSize(*stone);
	struct s_stone *cells[size];
	fillCell(*stone, cells);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (cells[j]->size < cells[i]->size)
			{
				temp = cells[i];
				cells[i] = cells[j];
				cells[j] = temp;
			}
			j++;
		}
		i++;
	}
	*stone = updateStones(cells, size);
}
