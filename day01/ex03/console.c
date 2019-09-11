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

struct s_stack *initStack(void)
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
		return (0);
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

char *ft_delline(char *line, int i, int len)
{
	while (i < len)
	{
		line[i] = '\0';
		i++;
	}
	return (line);
}

char *console(void)
{
	struct s_stack *stack;
	char *line;
	char *buf;
	size_t len;
	int idx;
	int size;

	stack = initStack();
	len = 255;
	line = (char *)malloc(sizeof(char) * 255 + 1);
	line[0] = '\0';
	printf("?: ");
	while ((getline(&buf, &len, stdin) > 0) && strncmp(buf, "SEND", 4))
	{
		if (!strncmp(buf, "UNDO", 4))
		{
			if (line[0])
			{
				idx = pop(stack) - size - 1;
				line = ft_delline(line, idx, strlen(line));
				line[idx] = '\0';
			}
			printf("%s\n\n", line);
		}
		else
		{
			if (!line[0])
			{
				strcpy(line, buf);
				push(stack, 0);
				idx = strlen(buf);
				size = idx;
				line[idx - 1] = '\0';
				printf("%s\n\n", line);
			}
			else
			{
				strcat(line, " ");
				size = strlen(buf);
				strncat(line, buf, size);
				idx = strlen(line);
				push(stack, idx);
				line[idx - 1] = '\0';
				printf("%s\n\n", line);
			}
		}
		printf("?: ");
	}
	free(buf);
	return (line);
}
