/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:14:20 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/09 14:14:22 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int searchPrice(struct s_art **arts, int n, char *name)
{
    int start;
    int end;
    int middle;

    start = 0;
    end = n - 1;
    while (start <= end)
    {
        middle = (start + end) / 2;
        if (strcmp(arts[middle]->name, name) > 0)
            end = middle - 1;
        else if (strcmp(arts[middle]->name, name) < 0)
            start = middle + 1;
        else
            return (arts[middle]->price);
    }
    return (-1);
}
