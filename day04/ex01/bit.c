/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:40:11 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/16 11:40:13 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

char *getNeg(char *a)
{
	int i;

	a++;
	i = 0;
	while (a[i])
	{
		if (a[i] == '1')
			a[i] = '0';
		else
			a[i] = '1';
		i++;
	}
	return (a);
}

char *getAnd(char *a, char *b)
{
	int i;

	if (a[0] == '~')
		a = getNeg(a);
	if (b[0] == '~')
		b = getNeg(b);
	i = 0;
    while (a[i])
    {
        if (a[i] == '1' && b[i] == '1')
			a[i] = '1';
        else
        	a[i] ='0';
        i++;
    }
    return (a);
}

char *getOr(char *a, char *b)
{
	int i;

	if (a[0] == '~')
		a = getNeg(a);
	if (b[0] == '~')
		b = getNeg(b);
	i = 0;
    while (a[i])
    {
        if (a[i] == '1' || b[i] == '1')
			a[i] = '1';
        else
        	a[i] ='0';
        i++;
    }
    return (a);
}

int toInt(char *bits)
{
	int i;
    int p;
    int res;

    i = 3;
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
