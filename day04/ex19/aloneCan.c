/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:08:30 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/17 13:08:32 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void aloneCan(int *arr, int n)
{
	int i;
	int unique;

	i = 0;
	unique = 0;
	while (i < n)
	{
		unique = unique ^ arr[i];
		i++;
	}
	printf("%d\n", unique);
}
