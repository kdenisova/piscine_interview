/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:43:03 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/10 18:43:05 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node *cloneGameBoard(struct s_node *node)
{
	struct s_node *current;
	struct s_node *head;
	struct s_node *clone;

	if (!node)
		return (NULL);
	head = node;
	while (head)
	{
		current = (struct s_node *)malloc(sizeof(struct s_node));
		current->value = head->value;
		current->next = head->next;
		current->random = NULL;
		head->next = current;
		head = head->next->next;
	}
	head = node;
	while (head)
	{
		if (head->random)
			head->next->random = head->random->next;
		head = head->next->next;
	}
	clone = NULL;
	head = node;
	while (head)
	{
		if (clone)
		{
			current->next = head->next;
			current = current->next;
		}
		else
		{
			clone = head->next;
			current = clone;
		}
		head->next = head->next->next;
		head = head->next;
	}
	return (clone);
}
