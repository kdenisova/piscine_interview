/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:56:47 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/17 13:56:48 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void aloneCans(int *arr, int n)
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
