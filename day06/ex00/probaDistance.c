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
	double prob = 0;
	double total = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			total++;
			if (locations[i] - locations[j] > dist || locations[j] - locations[i] > dist)
				prob++;
		}
	}
	prob = prob / total;
	return (prob);
}
