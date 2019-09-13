/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:47:56 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/12 11:47:58 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void countSort(unsigned char *utensils, int n)
{
	int i;
	int j;
	int al[SIZE] = {0};
	
	i = 0;
	while (i < n)
	{
		al[utensils[i]]++;
		i++;
	}
	i = 0;
	j = 1;
	while (i < n)
	{
		while (al[j])
		{
			utensils[i] = j;
			i++;
			al[j]--;
		}
		j++;
	}
}
