/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:45:08 by kdenisov          #+#    #+#             */
/*   Updated: 2019/10/02 15:45:10 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


struct s_elem {
	char *word;
	int  occurence;
};

struct s_list {
	struct s_elem **elems;
	int           len;
};

struct s_string {
  char *content;
  int  length; //the current length of 'content'
  int  capacity; //the allocated size of 'content'
};

struct s_string *stringInit(void)
{
	struct s_string *str;

	str = (struct s_string *)malloc(sizeof(struct s_string));
	str->content = NULL;
	str->length = 0;
	str->capacity = 0;
}
int	stringAppend(struct s_string *s, char *add); //return 0 = FAIL, 1 = SUCCESS
char *decompress(char *cBook);