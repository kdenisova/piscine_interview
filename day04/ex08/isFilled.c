/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:49:31 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/16 15:49:32 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int isFilled(unsigned int parkingRow)
{
	return (parkingRow && (parkingRow & (-(~parkingRow))) == 0);
}
