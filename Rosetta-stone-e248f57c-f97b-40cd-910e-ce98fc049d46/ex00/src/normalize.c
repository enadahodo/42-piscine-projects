/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:00:00 by azhuri            #+#    #+#             */
/*   Updated: 2024/05/18 00:00:00 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	skip_spaces(const char *str, size_t *index)
{
	while (str[*index] != '\0' && is_space(str[*index]))
		(*index)++;
}

char	*normalize_number(const char *str)
{
	size_t	start;
	size_t	end;
	size_t	trim;
	size_t	index;

	index = 0;
	skip_spaces(str, &index);
	if (str[index] == '-' || str[index] == '\0')
		return (NULL);
	if (str[index] == '+')
		index++;
	start = index;
	while (str[index] >= '0' && str[index] <= '9')
		index++;
	end = index;
	skip_spaces(str, &index);
	if (start == end || str[index] != '\0')
		return (NULL);
	trim = start;
	while (trim + 1 < end && str[trim] == '0')
		trim++;
	return (ft_strndup(str + trim, end - trim));
}
