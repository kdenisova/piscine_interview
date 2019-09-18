/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:07:29 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/17 15:07:31 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// double possiblePrice(int pizzaSize, double *prices, double *max)
// {
// 	double current;

//     if (!pizzaSize)
// 		return (0);
//     for (int i = pizzaSize; i > 0; i--)
// 	{
// 		current = prices[i] + possiblePrice(pizzaSize - i, prices, max);
// 		if (*max < current)
// 			*max = current;
// 	}
// 	return (current);
// }

void possiblePrice(int pizzaSize, double *prices, double *max, double current)
{
    if (!pizzaSize && *max < current)
		*max = current;
    for (int i = pizzaSize; i > 0; i--)
		possiblePrice(pizzaSize - i, prices, max, current + prices[i]);
}

double bestPrice(int pizzaSize, double *prices)
{
	double max;

	max = 0;
	possiblePrice(pizzaSize, prices, &max, 0);
	return (max);
}
