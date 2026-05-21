/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:00:00 by azhuri            #+#    #+#             */
/*   Updated: 2024/05/18 00:00:00 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	words_add_from_dict(t_words *words, t_dict *dict, const char *key)
{
	char	*value;

	value = find_value(dict, key);
	if (value == NULL)
		return (0);
	return (words_push(words, value));
}

void	words_print(t_words *words)
{
	int	index;
	int	first;

	index = 0;
	first = 1;
	while (index < words->size)
	{
		if (!first)
			write(1, " ", 1);
		else
			first = 0;
		ft_putstr(words->items[index]);
		index++;
	}
}

int	words_finish(t_words *words, int status)
{
	if (status)
	{
		words_print(words);
		write(1, "\n", 1);
	}
	words_free(words);
	return (status);
}
