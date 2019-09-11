/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:21:17 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/10 17:21:19 by kdenisov         ###   ########.fr       */
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

void *pop(struct s_stack *stack)
{
    struct s_item *temp;
	char *word;

	if (!stack || !stack->item)
		return (NULL);
	word = stack->item->word;
	temp = stack->item;
	stack->item = temp->next;
	free(temp);
	return (word);
}

void push(struct s_stack *stack, char *word)
{
    struct s_item *item;

	if (!stack)
		return ;
	item = (struct s_item *)malloc(sizeof(struct s_item));
	item->word = word;
	item->next = stack->item;
	stack->item = item;
}

void printReverseV2(struct s_node *lst)
{
    struct s_stack *stack;

    if (!lst)
        return ;
    stack = stackInit();
    while (lst)
    {
        push(stack, lst->word);
        lst = lst->next;
    }
    printf("%s", pop(stack));
    while (stack->item)
        printf(" %s", pop(stack));
}
