/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPersons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:34:45 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/19 11:34:47 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		minPersons(int elements, int minPercentage)
{
	double other = 1.0;
	int i = 1;

	while (i < elements && 1 - other <= (double)minPercentage / 100)
	{
		other = other * (double)(elements - i) / elements;
		i++;
	}
	return (i);
}
