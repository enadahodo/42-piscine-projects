/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:00:00 by azhuri            #+#    #+#             */
/*   Updated: 2024/05/18 00:00:00 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	handle_line(t_dict *dict, const char *line, size_t len)
{
	if (!dict_parse_line(dict, line, len))
	{
		free_dict(dict);
		return (0);
	}
	return (1);
}

int	parse_dict(const char *content, t_dict *dict)
{
	size_t	i;
	size_t	start;

	dict->entries = NULL;
	dict->size = 0;
	dict->capacity = 0;
	i = 0;
	start = 0;
	while (content[i] != '\0')
	{
		if (content[i] == '\n')
		{
			if (!handle_line(dict, content + start, i - start))
				return (0);
			start = i + 1;
		}
		i++;
	}
	if (!handle_line(dict, content + start, i - start))
		return (0);
	return (dict->size > 0);
}
