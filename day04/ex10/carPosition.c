/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:02:25 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/16 18:02:28 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int carPosition(unsigned int parkingRow)
{
    int pos;
    int count;

    pos = -1;
    count = 0;
    while (parkingRow)
    {
        if (parkingRow & 1)
            count++;
        parkingRow = parkingRow >> 1;
        pos++;
    }
    if (pos < 0 || count > 1)
        return (-1);
    return (pos);
}
