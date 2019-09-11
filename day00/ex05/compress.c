/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:40:38 by kdenisov          #+#    #+#             */
/*   Updated: 2019/09/10 11:40:39 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t hash(char *input)
{
    size_t h;
    int i;

    i = 0;
    h = 0;
    while (input[i])
    {
        h = h + (unsigned)input[i] % 101;
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

int	dictInsert(struct s_dict *dict, char *key, int value)
{
    int i;
    struct s_item *current;
    
    i = hash(key) % dict->capacity;
    current = dict->items[i];
    if (!current)
    {
        dict->items[i] = (struct s_item *)malloc(sizeof(struct s_item));
        if (!dict->items[i])
            return (0);
        current = dict->items[i];
    }  
    else
    {
        while (current->next)
            current = current->next;
        current->next = (struct s_item *)malloc(sizeof(struct s_item));
        if (!current->next)
            return (0);
        current = current->next;
    }
    current->key = key;
    current->value = value;
    current->next = NULL;
    return (1);
}

int	dictSearch(struct s_dict *dict, char *key)
{
    int i;
    struct s_item *current;

    i = hash(key) % dict->capacity;
    current = dict->items[i];
    while (current)
    {
        if (!strcmp(current->key, key))
            return (i);  
        current = current->next;
    }
    return (-1);
}

int dictSize(struct s_dict *dict)
{
    int i;
    int size;
    struct s_item *current;

    i = 0;
    size = 0;
    current = dict->items[i];
    while (current)
    {
        size = size + strlen(current->key) + 1;
        current = current->next;
    }
    return (size + 1);
}

char *dictHeader(struct s_dict *dict, int size)
{
    struct s_item *current;
    char *header;
    char *temp;
    int i;
    int len;

    header = (char *)malloc(sizeof(char) * size + 1);
    i = 0;
    header[0] = '<';
    temp = header;
    temp++;
    while (i < dict->capacity)
    {
        current = dict->items[i];
        while (current)
        {
            len = strlen(current->key);
            strncpy(temp, current->key, len);
            temp[len] = ',';
            temp = temp + len + 1;
            current = current->next;
        }
        i++;
    }
    temp--;
    *temp = '>'; 
    return (header);
}

char *compress(char *book, struct s_dict *dict)
{
    int i;
    int j;
    int k;
    int size;
    int len;
    int hash;
    char *new;
    char *word;
    char *header;

    size = dictSize(dict);
    header = dictHeader(dict, size);
    new = (char *)malloc(sizeof(char) * strlen(book) + size + 1);
    i = 0;
    while (header[i])
    {
        new[i] = header[i];
        i++;
    }
    free(header);
    j = 0;
    k = 0;
    while (book[j])
	{
		while (book[j] && !isalpha(book[j]))
        {
            new[i] = book[j];
            i++;
            j++;
        }
        k = j;
        while (book[k] && isalpha(book[k]))
            k++;
        len = k - j;
		word = (char *)calloc(1, len + 1);
		strncpy(word, &book[j], len);
        hash = dictSearch(dict, word);
        if (hash != -1)
        {
            new[i] = '@';
            new[i + 1] = hash;
            i = i + 2;
        }
        else
        {
            strncpy(&new[i], &book[j], len);
            i = i + len;
        }
        free(word);
        j = k;
	}
    while (new[i])
    {
        new[i] = '\0';
        i++;
    }
    return (new);
}