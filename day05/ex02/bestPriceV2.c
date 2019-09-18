/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:33:35 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/17 16:33:37 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double possiblePrice(int pizzaSize, double *prices, double *max)
{
	double current;

	if (!pizzaSize || max[pizzaSize] > 0)
		return (max[pizzaSize]);
	max[pizzaSize] = prices[pizzaSize];
	for (int i = pizzaSize; i > 0; i--)
	{
		current = max[i] + possiblePrice(pizzaSize - i, prices, max);
		if (max[pizzaSize] < current)
			max[pizzaSize] = current;
	}
	return (max[pizzaSize]);
}

double optimizedBestPrice(int pizzaSize, double *prices)
{
	double max[pizzaSize];

	for (int i = 1; i <= pizzaSize; i++)
		max[i] = 0;
	max[1] = prices[1];
	return (possiblePrice(pizzaSize, prices, max));
}
