/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:44:18 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/16 10:44:20 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *getSum(char *a, char *b)
{
	int i;
    int left;

    i = 5;
    left = 0;
    while (i >= 0)
    {
        if (a[i] == '0' && b[i] == '0')
        {
            a[i] = left + '0';
            left = 0;
        }
        else if (a[i] != b[i])
        {
            if (left)
            {
                a[i] = '0';
                left = 1;
            }
            else
                a[i] = '1';
        }
        else
        {
            a[i] = left + '0';
            left = 1;
        }
        i--;
    }
    return (a);
}

int toInt(char *bits)
{
	int i;
    int d;
    int res;

    i = 5;
    d = 1;
    res = 0;
    while (i >= 0)
    {
        res += (bits[i] - '0') * d;
		d = d << 1;
        i--;
    }
    return (res);
}