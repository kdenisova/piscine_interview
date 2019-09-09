/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:52:11 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/09 10:52:13 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int searchPrice(struct s_art **arts, char *name)
{
	int i;

	i = 0;
	if (!arts)
		return (-1);
	while (arts[i])
	{
		if (!strcmp(arts[i]->name, name))
			return (arts[i]->price);
		i++;
	}
	return (-1);
}
