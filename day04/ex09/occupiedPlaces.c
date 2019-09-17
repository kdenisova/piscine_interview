/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:51:34 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/16 17:51:36 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int occupiedPlaces(unsigned int parkingRow)
{
    int m;

    m = 0;
    while (parkingRow)
    {
        parkingRow &= (parkingRow - 1);
        m++;
    }
    return (m);
}
