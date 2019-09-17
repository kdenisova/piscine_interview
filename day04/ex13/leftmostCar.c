/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftmostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:29:42 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/17 11:29:44 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int leftmostCar(unsigned int parkingRow)
{
    int pos;

    pos = -1;
    while (parkingRow)
    {
        parkingRow = parkingRow >> 1;
        pos++;
    }
    return (pos);
}
