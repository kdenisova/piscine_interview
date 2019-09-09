/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:24:44 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/09 11:24:46 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <string.h>

/*--------------------------------
  !! required structure
--------------------------------*/

struct  s_art {
    char *name;
    int price;
};


/*--------------------------------
  :) function you must implement
--------------------------------*/

int  searchPrice(struct s_art **arts, char *name);


/*--------------------------------
  ?? test function used in main 
--------------------------------*/

struct s_art		**getArts(void);


/*--------------------------------
  &  your own other function
--------------------------------*/


#endif
