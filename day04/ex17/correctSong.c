/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correctSong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:39:16 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/17 12:39:18 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	correctSong(struct s_bit *bit, int l, int row, int col, int dist)
{
	int i;

	if (!bit || row >= bit->n || col >= l)
		return ;
	i = row;
	while (i < bit->n && dist)
	{
		bit->arr[i] = 1 << col;
		i++;
		dist--;
	}
}
