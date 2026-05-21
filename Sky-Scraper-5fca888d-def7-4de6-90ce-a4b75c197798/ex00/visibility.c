/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehodo <ehodo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:42:29 by ehodo             #+#    #+#             */
/*   Updated: 2025/09/13 17:46:40 by ehodo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	count_visible(int *line, int size, int reverse)
{
	int	count;
	int	max_height;
	int	i;
	int	current;

	count = 0;
	max_height = 0;
	i = 0;
	while (i < size)
	{
		if (reverse)
			current = line[size - 1 - i];
		else
			current = line[i];
		if (current > max_height)
		{
			max_height = current;
			count++;
		}
		i++;
	}
	return (count);
}

static void	get_row(int row, int *line)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = g_grid[row][i];
		i++;
	}
}

static void	get_col(int col, int *line)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = g_grid[i][col];
		i++;
	}
}

static int	get_expected_value(int row, int col, int direction)
{
	if (direction == 0)
		return (g_constraints[8 + row]);
	else if (direction == 1)
		return (g_constraints[12 + row]);
	else if (direction == 2)
		return (g_constraints[col]);
	else
		return (g_constraints[4 + col]);
}

int	check_visibility(int row, int col, int direction)
{
	int	line[4];
	int	expected;
	int	reverse;

	reverse = (direction == 1 || direction == 3);
	if (direction == 0 || direction == 1)
		get_row(row, line);
	else
		get_col(col, line);
	expected = get_expected_value(row, col, direction);
	return (count_visible(line, 4, reverse) == expected);
}
