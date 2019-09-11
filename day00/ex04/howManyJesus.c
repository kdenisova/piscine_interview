/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:44:31 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/09 18:44:32 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int findPow(int len)
{
	int h;
	int i;

	h = 1;
	i = 0;
	while (i < len - 1)
	{
		h = (h * AL) % PRIME;
		i++;
	}
	return (h);
}

int findHash(char *str, int len)
{
	int i;
	int hash;

	i = 0;
	hash = 0;
	while (i < len)
	{
		hash = (hash * AL + str[i]) % PRIME;
		i++;
	}
	return (hash);
}

int howManyJesus(char *bible, char *jesus)
{
	int len;
	int total;
	int count;
	int ph;
	int th;
	int h;
	int i;

	len = strlen(jesus);
	total = strlen(bible);
	ph = findHash(jesus, len);
	th = findHash(bible, len);
	h = findPow(len);
	i = 0;
	count = 0;
	while (i <= total - len)
	{
		if (ph == th && !strncmp(jesus, &bible[i], len))
			count++;
		if (i < total - len)
		{
			th = (AL * (th - bible[i] * h) + bible[i + len]) % PRIME;
			if (th < 0)
				th = th + PRIME;
		}
		i++;
	}
	return (count);
}

