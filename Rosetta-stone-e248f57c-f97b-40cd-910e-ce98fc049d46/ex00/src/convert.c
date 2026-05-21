/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:00:00 by azhuri            #+#    #+#             */
/*   Updated: 2024/05/18 00:00:00 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	init_state(t_state *state, const char *number)
{
	state->number = number;
	state->len = (int)ft_strlen(number);
	state->groups = (state->len + 2) / 3;
	state->first_len = state->len - (state->groups - 1) * 3;
	state->pos = 0;
	state->index = 0;
}

static int	build_value(t_state *state, int digits)
{
	int	value;
	int	i;

	value = 0;
	i = 0;
	while (i < digits)
	{
		value = value * 10 + (state->number[state->pos + i] - '0');
		i++;
	}
	return (value);
}

static int	append_scale(t_state *state, t_dict *dict, t_words *words)
{
	char	scale[1024];
	int		remaining;

	remaining = state->groups - state->index - 1;
	if (remaining <= 0)
		return (1);
	build_scale_key(remaining, scale);
	if (!words_add_from_dict(words, dict, scale))
		return (0);
	return (1);
}

static int	process_group(t_state *state, t_dict *dict, t_words *words)
{
	int	value;
	int	digits;

	digits = state->first_len;
	if (state->index > 0)
		digits = 3;
	value = build_value(state, digits);
	if (value > 0)
	{
		if (!append_group(value, dict, words))
			return (0);
		if (!append_scale(state, dict, words))
			return (0);
	}
	state->pos += digits;
	state->index++;
	return (1);
}

int	convert_number(const char *number, t_dict *dict)
{
	t_words		words;
	t_state		state;

	words_init(&words);
	if (ft_strcmp(number, "0") == 0)
	{
		if (!words_add_from_dict(&words, dict, "0"))
			return (words_finish(&words, 0));
		return (words_finish(&words, 1));
	}
	init_state(&state, number);
	while (state.index < state.groups)
	{
		if (!process_group(&state, dict, &words))
			return (words_finish(&words, 0));
	}
	if (words.size == 0)
		return (words_finish(&words, 0));
	return (words_finish(&words, 1));
}
