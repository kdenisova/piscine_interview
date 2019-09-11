/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:51:16 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/10 16:51:17 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void printReverse(struct s_node *lst)
{
	if (!lst->next)
	{
		printf("%s", lst->word);
		return ;
	}
	else
		printReverse(lst->next);
	printf(" %s", lst->word);
}
