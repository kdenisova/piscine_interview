/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:10:30 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/16 15:10:32 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
	return ((parkingRow & ~(1 << pos)) | (value << pos));
}
