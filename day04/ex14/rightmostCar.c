/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightmostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:30:00 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/17 11:30:02 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int rightmostCar(unsigned int parkingRow)
{
    int pos;
    int one;

    if (parkingRow == 0)
        return (-1);
    pos = 0;
    one = 1;
    while (!(parkingRow & one))
    {
        one = one << 1;
        pos++;
    }
    return (pos);
}
