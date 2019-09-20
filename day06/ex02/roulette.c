/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 11:19:07 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/19 11:19:09 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame)
{
	double red;
	double green;

	if (firstDollarsBet >= dollarsWanted)
		return (1);
	if (!firstDollarsBet || !nbGame)
		return (0);
	red = (18.0 / 37.0) * probabilityWin(firstDollarsBet * 2.0, dollarsWanted, nbGame - 1);
	green = (1.0 / 37.0) * probabilityWin(firstDollarsBet / 2.0, dollarsWanted, nbGame - 1);
	return (red + green);
}
