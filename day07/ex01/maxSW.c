/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:59:24 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/19 14:59:26 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_deque *dequeInit(void)
{
	struct s_deque *deque;

	deque = (struct s_deque *)malloc(sizeof(struct s_deque));
	deque->first = NULL;
	deque->last = NULL;
	return (deque);
}

void pushFront(struct s_deque *deque, int value)
{
	struct s_dequeNode *current;

	if (!deque)
		return ;
	current = (struct s_dequeNode *)malloc(sizeof(struct s_dequeNode));
	current->value = value;
	current->prev = NULL;
	if (!deque->first)
	{
		current->next = NULL;
		deque->last = current;
	}	
	else
	{
		deque->first->prev = current;
		current->next = deque->first;
	}
	deque->first = current;
}

void pushBack(struct s_deque *deque, int value)
{
	struct s_dequeNode *current;

	if (!deque)
		return ;
	current = (struct s_dequeNode *)malloc(sizeof(struct s_dequeNode));
	current->value = value;
	current->next = NULL;
	if (!deque->last)
	{
		deque->first = current;
		current->prev = NULL;
	}	
	else
	{
		deque->last->next = current;
		current->prev = deque->last;
	}	
	deque->last = current;
}

int popFront(struct s_deque *deque)
{
	int value;
	struct s_dequeNode *temp;

	if (!deque || !deque->first)
		return (INT_MIN);
	value = deque->first->value;
	temp = deque->first;
	deque->first = temp->next;
	if (!deque->first)
		deque->last = NULL;
	else
		deque->first->prev = NULL;
	free(temp);
	return (value);
}

int popBack(struct s_deque *deque)
{
	int value;
	struct s_dequeNode *temp;

	if (!deque || !deque->last)
		return (INT_MIN);
	value = deque->last->value;
	temp = deque->last;
	deque->last = temp->prev;
	if (!deque->last)
		deque->first = NULL;
	else
		deque->last->next = NULL;
	free(temp);
	return (value);
}

int peekFront(struct s_deque *deque)
{
	if (!deque || !deque->first)
		return (INT_MIN);
	return (deque->first->value);
}

int peekBack(struct s_deque *deque)
{
	if (!deque || !deque->last)
		return (INT_MIN);
	return (deque->last->value);
}

struct s_max *maxSlidingWindow(int *arr, int n, int k)
{
	struct s_max *new = (struct s_max *)malloc(sizeof(struct s_max));
	struct s_deque *deque = dequeInit();
	int i;

	if (!arr || k < 0 || k > n)
		return (NULL);
	new->length = n - k + 1;
	new->max = (int *)malloc(sizeof(int) *  new->length);
	for (i = 0; i < k; i++)
	{
		while (deque->last && peekBack(deque) != INT_MIN && arr[peekBack(deque)] <= arr[i])
			popBack(deque);
		pushBack(deque, i);
	}
	for (i = k; i < n; i++)
	{
		new->max[i - k] = arr[peekFront(deque)];
		while (deque->first && peekFront(deque) != INT_MIN && peekFront(deque) <= i - k)
			popFront(deque);
		while (deque->last && peekBack(deque) != INT_MIN && arr[peekBack(deque)] <= arr[i])
			popBack(deque);
		pushBack(deque, i);
	}
	new->max[i - k] = arr[peekFront(deque)];
	return (new);
}
