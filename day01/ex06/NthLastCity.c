/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:02:39 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/11 13:02:40 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *NthLastCity(struct s_city *city, int n)
{
    struct s_city *current;
    struct s_city *tail;
    int i;

    if (!city || n < 0)
        return (NULL);
    current = city;
    tail = city;
    i = 0;
    while (i < n && tail->next)
    {
        tail = tail->next;
        i++;
    }
    while (tail)
    {
        if (!tail->next)
            return (current->name);
        tail = tail->next;
        current = current->next;
    }
    return (NULL);
}
