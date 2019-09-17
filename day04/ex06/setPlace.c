/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:03:14 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/16 15:03:15 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int setPlace(unsigned int parkingRow, int pos)
{
	return (parkingRow | (1 << pos));
}
