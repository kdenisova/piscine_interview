/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:37:55 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/16 18:37:57 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int carPosition(unsigned int parkingRow)
{
    int pos;

    if (parkingRow == 0)
        return (-1);
    pos = 0;
    while (parkingRow && (parkingRow % 2 == 0))
    {
        parkingRow /= 2;
        pos++;
    }
    if (parkingRow / 2 != 0)
        return (-1);
    return (pos);
}
