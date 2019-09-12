/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:45:23 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/11 11:45:25 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_tank *initTank(void)
{
	struct s_tank *tank;
	struct s_stack **stacks;

	tank = (struct s_tank *)malloc(sizeof(struct s_tank));
	if (!tank)
		return (NULL);
	tank->n = 0;
	stacks = (struct s_stack **)malloc(sizeof(struct s_stack *));
	if (!stacks)
		return (NULL);
	(*stacks) = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (!(*stacks))
		return (NULL);
	tank->stacks = stacks;
	(*stacks)->elem = NULL;
	(*stacks)->sum = 0;
	return (tank);
}

void tankPush(struct s_tank *tank, int energy)
{
	struct s_elem *elem;
	struct s_stack **stacks;
	
	if (!tank)
		return ;
	if (tank->stacks[tank->n]->sum + energy > 1000)
	{
		tank->n = tank->n + 1;
		stacks = (struct s_stack **)malloc(sizeof(struct s_stack *) * (tank->n));
		if (!stacks)
			return ;
		memmove(stacks, tank->stacks, sizeof(struct s_stack *) * (tank->n));
		tank->stacks = stacks;
		tank->stacks[tank->n] = (struct s_stack *)malloc(sizeof(struct s_stack));
		if (!tank->stacks[tank->n])
			return ;
		tank->stacks[tank->n]->elem = NULL;
		tank->stacks[tank->n]->sum = 0;
	}
	elem = (struct s_elem *)malloc(sizeof(struct s_elem));
	if (!elem)
			return ;
	elem->next = tank->stacks[tank->n]->elem;
	tank->stacks[tank->n]->elem = elem;
	elem->energy = energy;
	tank->stacks[tank->n]->sum = tank->stacks[tank->n]->sum + energy;
}

int tankPop(struct s_tank *tank)
{
	struct s_elem *elem;
	struct s_stack *stack;
	int energy;

	if (!tank)
		return (0);
	stack = tank->stacks[tank->n];
	elem = stack->elem;
	energy = elem->energy;
	stack->sum = stack->sum - energy;
	stack->elem = stack->elem->next;
	free(elem);
	if (stack->sum == 0 && tank->n > 0)
	{
		free(stack);
		tank->n = tank->n - 1;
	}
	return (energy);
}
