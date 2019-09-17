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
    int res;

    i = strlen(a) - 1;
    left = 0;
    while (i >= 0)
    {
        res = (a[i] - '0') + (b[i] - '0') + left;
        if (res >= 2)
        {
            res = res % 2;
            left = 1;
        }
        else
            left = 0;
        a[i] = res + '0';
        i--;
    }
    return (a);
}

int toInt(char *bits)
{
	int i;
    int d;
    int res;

    i = strlen(bits) - 1;
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