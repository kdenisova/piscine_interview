/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:21:09 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/18 15:21:10 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double probaDistance(int dist, int *locations, int n)
{
	double prob;

	prob = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (locations[i] - locations[j] > dist)
				prob++;
		}
	}
	prob = prob / n;
	return (prob);
}
