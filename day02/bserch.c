/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bserch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:03:52 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/12 15:03:56 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int binarySearch(int *rocks, int value, int start, int end)
// {
// 	int middle;
	
// 	if (start <= end)
// 	{
// 		middle = start + (end - start) / 2;
// 		if (rocks[middle] == value)
// 			return (middle);
// 		if (rocks[start] <= rocks[middle])
// 		{
// 			if (rocks[start] <= value && value < rocks[middle])
// 				end = middle - 1;
// 			else
// 				start = middle + 1;
// 		}
// 		else
// 		{
// 			if (rocks[middle] < value && value <= rocks[end])
// 				start = middle + 1;
// 			else
// 				end = middle - 1;
// 		}
// 		return (binarySearch(rocks, value, start, end));
// 	}
// 	return (-1);
// }
