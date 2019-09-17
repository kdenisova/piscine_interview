/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:12:26 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/16 12:12:28 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *rightShift(char *bin, int k)
{
	int i;
	int len;
	char sign;

	i = k;
	sign = bin[0];
	len = strlen(bin);
    if (k < 6)
	{
		while (i < len)
		{
			bin[i] = bin[i - k];
			i++;
		}
	}
	i = 0;
	while (i < k && bin[i])
	{
		bin[i] = sign;
		i++;
	}
    return (bin);
}

char *leftShift(char *bin, int k)
{
	int i;
	int len;
	char sign;

	sign = bin[0];
	len = strlen(bin);
    if (k < 6)
	{
		i = 0;
		while (i + k < len)
		{
			bin[i] = bin[i + k];
			i++;
		}
	}
	i = len - 1;
	while (i >= 0 && k > 0)
	{
		bin[i] = '0';
		i--;
		k--;
	}
    return (bin);
}

int toInt(char *bits)
{
	int i;
    int d;
    int res;

    i = strlen(bits) - 1;
    d = 1;
    res = 0;
    while (i >= 1)
    {
        res += (bits[i] - '0') * d;
		d = d << 1;
        i--;
    }
	if (bits[0] == '1')
		res -= d;
    return (res);
}