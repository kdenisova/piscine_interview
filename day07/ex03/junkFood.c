/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:54:18 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/20 12:54:20 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int isEmpty(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (1);
	return (0);
}

struct s_sellers *closestSellers(struct s_graph *graph, char *youAreHere)
{
	struct s_sellers *sellers = (struct s_sellers *)malloc(sizeof(struct s_sellers));
	struct s_queue *queue = queueInit();
	struct s_queue *places = queueInit();
	struct s_node *temp;
	struct s_node *root = NULL;
	int found = 0;
	int distance = 0;

	if (!graph)
		return (NULL);
	for (int i = 0; graph->places[i]; i++)
	{
		if (!strcmp(graph->places[i]->name, youAreHere))
		{
			root = graph->places[i];
			break ;
		}
	}
	if (!root)
		return (NULL);
	root->visited = 1;
	enqueue(queue, root);
	enqueue(queue, NULL);
	while (!isEmpty(queue))
	{
		while ((temp = dequeue(queue)))
		{
			temp->visited = 1;
			if (temp->hasCerealBar)
			{
				found++;
				enqueue(places, temp);
			}
			else
			{
				for (int i = 0; temp->connectedPlaces[i]; i++)
				{
					if (!temp->connectedPlaces[i]->visited)
					{
						temp->connectedPlaces[i]->visited = 1;
						enqueue(queue, temp->connectedPlaces[i]);
					}
				}
			}
		}
		enqueue(queue, NULL);
		if (found)
			break ;
		distance++;
	}
	if (!found)
		return (NULL);
	sellers->distance = distance;
	sellers->placeNames = (char **)malloc(sizeof(char *) * found + 1);
	for (int i = 0; i < found; i++)
	{
		sellers->placeNames[i] = dequeue(places)->name;
	}
	sellers->placeNames[found] = NULL;
	return (sellers);
}
