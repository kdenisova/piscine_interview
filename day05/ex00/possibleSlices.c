/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:18:16 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/17 14:18:18 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void possibleSlices(struct s_array *arr, int pizzaSize)
{
    struct s_array *slices;
    
    if (!pizzaSize)
        arrayPrint(arr);
    for (int i = pizzaSize; i > 0; i--)
    {
        slices = arrayClone(arr);
        arrayAppend(slices, i);
        possibleSlices(slices, pizzaSize - i);
    }
}

void printPossibleSlices(int pizzaSize)
{
    struct s_array *arr = arrayInit();
   
    if (pizzaSize > 0)
        possibleSlices(arr, pizzaSize);
}
