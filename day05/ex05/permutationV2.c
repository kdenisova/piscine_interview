/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutationV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:14:50 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/18 11:14:52 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_fact(int len)
{
	int f;

	f = 1;
	while (len)
	{
		f = f * len;
		len--;
	}
	return (f);
}

void	swap(char *str, int i, int pos)
{
	char c;

	c = str[i];
	str[i] = str[pos];
	str[pos] = c;
}

void	permutations(struct s_dict *dict, char *str, int len, int pos)
{
	if (pos == len)
	{
		if (dictSearch(dict, str) < 0)
		{
			dictInsert(dict, str, 1);
			printf("%s\n", str);
		}
		return ;
	}
	for (int i = pos; i <= len; i++)
	{
		swap(str, i, pos);
		permutations(dict, str, len, pos + 1);
		swap(str, i, pos);
	}
}

void	printUniquePermutations(char *str)
{
	struct s_dict *dict;

	dict = dictInit(ft_fact(strlen(str)));
	if (str)
		permutations(dict, str, strlen(str) - 1, 0);
}
