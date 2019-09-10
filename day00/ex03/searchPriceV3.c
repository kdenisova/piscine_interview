/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:53:11 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/09 14:53:13 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t hash(char *input)
{
    size_t h;
    int i;
    int len;

    i = 0;
    h = 0;
    len = strlen(input);
    while (input[i])
    {
        h = h + (unsigned)input[i] % len;
        i++;
    }
    return (h);
}

struct s_dict *dictInit(int capacity)
{
    struct s_dict *dict;
    int i;

    dict = (struct s_dict *)malloc(sizeof(struct s_dict));
    dict->capacity = capacity;
    dict->items = (struct s_item **)malloc(sizeof(struct s_item *) * capacity);
    i = 0;
    while (i < capacity)
    {
        dict->items[i] = NULL;
        i++;
    }
    return (dict);
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
    int i;
    struct s_item *current;
    
    i = hash(key) % dict->capacity;
    current = dict->items[i];
    if (!current)
    {
        dict->items[i] = (struct s_item *)malloc(sizeof(struct s_item));
        current = dict->items[i];
    }  
    else
    {
        while (current->next)
            current = current->next;
        current->next = (struct s_item *)malloc(sizeof(struct s_item));
        current = current->next;
    }
    current->key = key;
    current->value = value;
    current->next = NULL;
    return (0);
}

struct s_art *dictSearch(struct s_dict *dict, char *key)
{
    int i;

    i = hash(key) % dict->capacity;
    while (dict->items[i])
    {
        if (!strcmp(dict->items[i]->key, key))
            return (dict->items[i]->value);  
        dict->items[i] = dict->items[i]->next;
    }
    return (NULL);
}

int searchPrice(struct s_dict *dict, char *name)
{
    struct  s_art *res;

    res = dictSearch(dict, name);
    if (!res)
        return (-1);
    return (res->price);
}