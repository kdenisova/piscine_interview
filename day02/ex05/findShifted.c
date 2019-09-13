/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:41:49 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/12 12:41:51 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int binarySearch(int *rocks, int value, int start, int end)
{
	int middle;

	if (start <= end)
	{
		middle = start + (end - start) / 2;
		if (rocks[middle] == value)
			return (middle);
		if (rocks[start] <= rocks[middle])
		{
			if (rocks[start] <= value && value < rocks[middle])
				end = middle - 1;
			else
				start = middle + 1;
		}
		else
		{
			if (rocks[middle] < value && value <= rocks[end])
				start = middle + 1;
			else
				end = middle - 1;
		}
		return (binarySearch(rocks, value, start, end));
	}
	return (-1);
}

int searchShifted(int *rocks, int length, int value)
{
	int index;

	if (length <= 0)
		return (-1);
	if (rocks[0] == value)
		return (0);
	index = binarySearch(rocks, value, 0, length - 1);
	while (index > 0 && rocks[index - 1] == value)
		index--;
	return (index);
}
