/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piano.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:40:52 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/17 11:40:54 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	**pianoDecompress(struct s_bit *bit, int l)
{
	int **arr;
	int i;
	int j;

	if (!bit)
		return (NULL);
	arr = (int **)malloc(sizeof(int *) * bit->n * l);
	i = 0;
	while (i < bit->n)
	{
		arr[i] = (int *)malloc(sizeof(int) * l);
		j = 0;
		while (j < l)
		{
			if ((bit->arr[i] >> j) & 1)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (arr);
}
