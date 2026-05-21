/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:00:00 by azhuri            #+#    #+#             */
/*   Updated: 2024/05/18 00:00:00 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	build_key(int value, char *buf)
{
	int	len;
	int	tmp;

	if (value == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return ;
	}
	len = 0;
	tmp = value;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	buf[len] = '\0';
	while (len > 0)
	{
		len--;
		buf[len] = '0' + (value % 10);
		value /= 10;
	}
}

static int	append_under_hundred(int value, t_dict *dict, t_words *words)
{
	char	key[4];

	if (value == 0)
		return (1);
	if (value < 20)
	{
		build_key(value, key);
		return (words_add_from_dict(words, dict, key));
	}
	build_key((value / 10) * 10, key);
	if (!words_add_from_dict(words, dict, key))
		return (0);
	if (value % 10 == 0)
		return (1);
	build_key(value % 10, key);
	return (words_add_from_dict(words, dict, key));
}

int	append_group(int value, t_dict *dict, t_words *words)
{
	char	key[4];

	if (value >= 100)
	{
		build_key(value / 100, key);
		if (!words_add_from_dict(words, dict, key))
			return (0);
		if (!words_add_from_dict(words, dict, "100"))
			return (0);
	}
	return (append_under_hundred(value % 100, dict, words));
}

void	build_scale_key(int groups_left, char *buf)
{
	int	index;

	buf[0] = '1';
	index = 0;
	while (index < groups_left * 3)
	{
		buf[index + 1] = '0';
		index++;
	}
	buf[index + 1] = '\0';
}
