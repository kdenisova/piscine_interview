/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:29:42 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/17 18:29:43 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void sinkIsland(int **map, int row, int col)
{
    map[row][col] = 0;
    if (map[row][col + 1] == 1)
        sinkIsland(map, row, col + 1);
    if (col - 1 >= 0 && map[row][col - 1] == 1)
        sinkIsland(map, row, col - 1);
    if (map[row + 1] && map[row + 1][col] == 1)
        sinkIsland(map, row + 1, col);
    if (row - 1 >= 0 && map[row - 1][col] == 1)
        sinkIsland(map, row - 1, col);
}
