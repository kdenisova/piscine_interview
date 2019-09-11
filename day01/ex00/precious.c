/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:12:42 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/10 16:12:44 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node *createNode(char c)
{
	struct s_node *node;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->c = c;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

struct s_node *createList(void)
{
	struct s_node *head;
	struct s_node *temp;
	struct s_node *current;
	int i;
	int len;
	head = createNode(CS[0]);
	temp = head;
	i = 1;
	len = strlen(CS);
	while (i < len)
	{
		current = createNode(CS[i]);
		temp->next = current;
		current->prev = temp;
		if (i < len - 1)
		{
			temp = temp->next;
			current = current->next;
		}
		i++;
	}
	current->next = head;
	head->prev = current;
	return (head);
}

char *precious(int *text, int size)
{
	struct s_node *head;
	int i;
	int j;
	char *new;

	new = (char *)malloc(sizeof(char) * size + 1);
	head = createList();
	i = 0;
	j = 0;
	while (i < size)
	{
		if (text[i] < 0)
		{
			while (text[i])
			{
				head = head->prev;
				text[i]++;
			}
			new[j] = head->c;
			j++;
		}
		else
		{
			while (text[i])
			{
				head = head->next;
				text[i]--;
			}
			new[j] = head->c;
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (new);
}
