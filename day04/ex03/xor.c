/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:28:13 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/16 14:28:15 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *getXor(char *a, char *b)
{
    int i;

	i = 0;
    while (a[i])
    {
        if (a[i] == b[i])
			a[i] = '0';
        else
        	a[i] ='1';
        i++;
    }
    return (a);
}

int toInt(char *bits)
{
	int i;
    int p;
    int res;

    i = 5;
    p = 1;
    res = 0;
    while (i >= 0)
    {
        res += (bits[i] - '0') * p;
		p = p << 1;
        i--;
    }
    return (res);
}
