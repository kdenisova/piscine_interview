/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:00:34 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/12 16:00:35 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h> //printf, scanf, ...


int 	findSize(struct s_criminal **criminals)
{
	int i;

	i = 0;
	while (criminals[i])
		i++;
	return (i);
}

int findMax(struct s_criminal **criminals)
{
	int max;
	int i;

	if (!criminals)
		return (0);
	i = 0;
	max = criminals[0]->description;
	while (criminals[i])
	{
		if (criminals[i]->description > max)
			max = criminals[i]->description;
		i++;
	}
	return (max);
}

void countSort(struct s_criminal **criminals, int exp, int n)
{
	struct s_criminal *new[n];
	int i;
	int count[10] = {0};

	i = 0;
	while (i < n)
	{
		count[(criminals[i]->description / exp) % 10]++;
		i++; 
	}
	i = 1;
	while (i < 10)
	{
		count[i] = count[i] + count[i - 1];
		i++;
	}
	i = n - 1;
	while (i >= 0)
	{
		new[count[(criminals[i]->description / exp) % 10] - 1] = criminals[i];
		count[(criminals[i]->description / exp) % 10]--;
		i--;
	}
	i = 0;
	while (i < n)
	{
		criminals[i] = new[i];
		i++;
	}
}

// int binarySearch(struct s_criminal **criminals, int des, int start, int end)
// {
// 	int i;
// 	int piviot; 
// 	int middle;

// 	piviot = end;
// 	while (piviot)
// 	{
// 		i = start;
// 		middle = piviot / 2;
// 		i = i + middle;
// 		if (criminals[i]->description < des)
// 		{
// 			i++;
// 			start = i;
// 			piviot = piviot - middle;
// 		}
// 		else
// 			piviot = middle;
// 	}
// 	if (start == end)
// 		return (-1);
// 	return (start);
// }

int getDescription(struct s_info *info)
{
	int des;

	if (!info)
		return (0);
	des = info->gender * 1000000 + info->height * 100000 + info->hairColor * 10000 +
		info->eyeColor * 1000 + info->glasses * 100 + info->tattoo * 10 +
		info->piercing;
	return (des);
}

void sortCriminals(struct s_criminal **criminals)
{
	int max;
	int exp;
	int size;

	max = findMax(criminals);
	size = findSize(criminals);
	exp = 1;
	while (max / exp > 0)
	{
		countSort(criminals, exp, size);
		exp = exp * 10;
	}
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	struct s_criminal **new;
	int i;
	int j;
	int des;
	int size;

	if (!criminals || !info)
		return (NULL);
	des = getDescription(info);
	i = binarySearch(criminals, 352100, 0, findSize(criminals));
	size = 0;
	while (criminals[i] && criminals[i]->description == des)
	{
		i++;
		size++;
	}	
	new = (struct s_criminal **)malloc(sizeof(struct s_criminal *) * size);
	j = 0;
	i = i - size - 1;
	while (j <= size)
	{
		new[j] = criminals[i];
		i++;
		j++;
	}
	new[j] = NULL;
	return (new);
}
