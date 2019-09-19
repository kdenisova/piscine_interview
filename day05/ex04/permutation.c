/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:18:32 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/18 10:18:34 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap(char *str, int i, int pos)
{
    char c;

    c = str[i];
    str[i] = str[pos];
    str[pos] = c;
}

void	permutations(char *str, int len, int pos)
{
    if (pos == len)
    {
        printf("%s\n", str);
        return ;
    }   
    for (int i = pos; i <= len; i++)
    {
        swap(str, i, pos);
        permutations(str, len, pos + 1);
        swap(str, i, pos);
    }
}

void	printPermutations(char *str)
{
    permutations(str, strlen(str) - 1, 0);
}
