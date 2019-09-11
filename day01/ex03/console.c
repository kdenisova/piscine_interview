/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:24:29 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/10 18:24:32 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack *stackInit(void)
{
    struct s_stack *stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

int pop(struct s_stack *stack)
{
    struct s_item *temp;
	int idx;

	if (!stack || !stack->item)
		return (NULL);
	idx = stack->item->idx;
	temp = stack->item;
	stack->item = temp->next;
	free(temp);
	return (idx);
}

void push(struct s_stack *stack, int idx)
{
    struct s_item *item;

	if (!stack)
		return ;
	item = (struct s_item *)malloc(sizeof(struct s_item));
	item->idx = idx;
	item->next = stack->item;
	stack->item = item;
}

char *console(void)
{

}
