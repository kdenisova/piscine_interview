/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:05:51 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/10 18:05:53 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_queue *queueInit(void)
{
	struct s_queue *queue;

	queue = (struct s_queue *)malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

char *dequeue(struct s_queue *queue)
{
	char	*message;
	struct s_node *temp;

	if (isEmpty(queue))
		return (NULL);
	message = queue->first->message;
	temp = queue->first;
	queue->first = temp->next;
	free(temp);
	return (message);
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node *current;

	if (!queue)
		return ;
	current = (struct s_node *)malloc(sizeof(struct s_node));
	current->message = message;
	current->next = NULL;
	if (!queue->first)
		queue->first = current;
	else
		queue->last->next = current;
	queue->last = current;
}

char *peek(struct s_queue *queue)
{
	if (isEmpty(queue))
		return (NULL);
	return (queue->first->message);
}

int isEmpty(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (1);
	return (0);
}

