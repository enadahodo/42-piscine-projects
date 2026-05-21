/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:00:00 by azhuri            #+#    #+#             */
/*   Updated: 2024/05/18 00:00:00 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static const char	*skip_spaces(const char *ptr, const char *end)
{
	while (ptr < end && is_space(*ptr))
		ptr++;
	return (ptr);
}

static int	read_number(const char **ptr, const char *end, char **key)
{
	const char	*start;
	const char	*finish;

	*ptr = skip_spaces(*ptr, end);
	if (*ptr == end || **ptr < '0' || **ptr > '9')
		return (0);
	start = *ptr;
	while (*ptr < end && **ptr >= '0' && **ptr <= '9')
		(*ptr)++;
	finish = *ptr;
	*ptr = skip_spaces(*ptr, end);
	while (start + 1 < finish && *start == '0')
		start++;
	*key = ft_strndup(start, (size_t)(finish - start));
	return (*key != NULL);
}

static int	read_value(const char **ptr, const char *end, char **value)
{
	const char	*start;
	const char	*finish;

	*ptr = skip_spaces(*ptr, end);
	start = *ptr;
	finish = end;
	while (finish > start && is_space(*(finish - 1)))
		finish--;
	if (start >= finish)
		return (0);
	*value = ft_strndup(start, (size_t)(finish - start));
	if (*value == NULL)
		return (0);
	*ptr = end;
	return (1);
}

int	dict_parse_line(t_dict *dict, const char *line, size_t len)
{
	const char	*ptr;
	const char	*end;
	char		*key;
	char		*value;

	if (len == 0)
		return (1);
	ptr = line;
	end = line + len;
	if (!read_number(&ptr, end, &key))
		return (0);
	if (ptr == end || *ptr != ':')
	{
		free(key);
		return (0);
	}
	ptr++;
	if (!read_value(&ptr, end, &value))
	{
		free(key);
		return (0);
	}
	if (!dict_store(dict, key, value))
		return (0);
	return (1);
}
