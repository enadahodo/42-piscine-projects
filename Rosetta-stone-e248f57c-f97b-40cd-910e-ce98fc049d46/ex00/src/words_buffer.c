/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:00:00 by azhuri            #+#    #+#             */
/*   Updated: 2024/05/18 00:00:00 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	words_grow(t_words *words)
{
	char	**items;
	int		capacity;
	int		index;

	capacity = words->capacity + 16;
	items = (char **)malloc(sizeof(char *) * capacity);
	if (items == NULL)
		return (0);
	index = 0;
	while (index < words->size)
	{
		items[index] = words->items[index];
		index++;
	}
	free(words->items);
	words->items = items;
	words->capacity = capacity;
	return (1);
}

void	words_init(t_words *words)
{
	words->items = NULL;
	words->size = 0;
	words->capacity = 0;
}

int	words_push(t_words *words, char *value)
{
	if (words->size == words->capacity && !words_grow(words))
		return (0);
	words->items[words->size] = value;
	words->size++;
	return (1);
}

void	words_free(t_words *words)
{
	free(words->items);
	words->items = NULL;
	words->size = 0;
	words->capacity = 0;
}
