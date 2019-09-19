/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeThemEat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:54:51 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/18 11:54:52 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int checkPossible(struct s_people **people, int *tables, int nbTable, int totalTime, int pos)
{
	if (!people[pos])
		return (1);
	for (int i = 0; i < nbTable; i++)
	{
		if (tables[i] + people[pos]->time <= totalTime)
		{
			tables[i] += people[pos]->time;
			if (checkPossible(people, tables, nbTable, totalTime, pos + 1))
				return (1);
			tables[i] -= people[pos]->time;
		}
	}
	return (0);
}

int isPossible(struct s_people **people, int nbTable, int totalTime)
{
	int ret;
	int *tables = (int *)malloc(sizeof(int) * nbTable);
	
	for (int i = 0; i < nbTable; i++)
		tables[i] = 0;
	ret = checkPossible(people, tables, nbTable, totalTime, 0);
	free(tables);
	return (ret);
}
