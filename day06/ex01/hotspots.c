/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:52:31 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/19 10:52:33 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int selectHotspots(struct s_hotspot **hotspots)
{
	int left;
	int count;

	if (!hotspots || !hotspots[0])
		return (0);
	left = hotspots[0]->pos + hotspots[0]->radius;
	count = 1;
	for (int i = 1; hotspots[i]; i++)
	{
		if (hotspots[i]->pos - hotspots[i]->radius >= left)
		{
			left = hotspots[i]->pos + hotspots[i]->radius;
			count++;
		}
		else
			left = hotspots[i]->pos - hotspots[i]->radius;
	}
	return (count);
}