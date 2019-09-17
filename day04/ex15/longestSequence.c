/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:30:49 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/17 11:30:51 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int longestSequence(unsigned int parkingRow)
{
    int count;

    count = 0;
    while (parkingRow)
    {
        parkingRow &= (parkingRow << 1);
        count++;
    }
    return (count);
}
