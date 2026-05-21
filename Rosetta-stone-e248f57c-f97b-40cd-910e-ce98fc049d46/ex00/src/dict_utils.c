/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:00:00 by azhuri            #+#    #+#             */
/*   Updated: 2024/05/18 00:00:00 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	dict_grow(t_dict *dict)
{
	t_entry	*entries;
	int		capacity;
	int		index;

	capacity = dict->capacity + 16;
	entries = (t_entry *)malloc(sizeof(t_entry) * capacity);
	if (entries == NULL)
		return (0);
	index = 0;
	while (index < dict->size)
	{
		entries[index] = dict->entries[index];
		index++;
	}
	free(dict->entries);
	dict->entries = entries;
	dict->capacity = capacity;
	return (1);
}

int	dict_store(t_dict *dict, char *key, char *value)
{
	int	index;

	index = 0;
	while (index < dict->size)
	{
		if (ft_strcmp(dict->entries[index].key, key) == 0)
		{
			free(key);
			free(value);
			return (0);
		}
		index++;
	}
	if (dict->size == dict->capacity && !dict_grow(dict))
	{
		free(key);
		free(value);
		return (0);
	}
	dict->entries[dict->size].key = key;
	dict->entries[dict->size].value = value;
	dict->size++;
	return (1);
}

void	free_dict(t_dict *dict)
{
	int	index;

	index = 0;
	while (index < dict->size)
	{
		free(dict->entries[index].key);
		free(dict->entries[index].value);
		index++;
	}
	free(dict->entries);
	dict->entries = NULL;
	dict->size = 0;
	dict->capacity = 0;
}

char	*find_value(t_dict *dict, const char *key)
{
	int	index;

	index = 0;
	while (index < dict->size)
	{
		if (ft_strcmp(dict->entries[index].key, key) == 0)
			return (dict->entries[index].value);
		index++;
	}
	return (NULL);
}
