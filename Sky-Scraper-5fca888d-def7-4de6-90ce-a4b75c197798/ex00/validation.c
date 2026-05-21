/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehodo <ehodo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:42:29 by ehodo             #+#    #+#             */
/*   Updated: 2025/09/13 17:45:54 by ehodo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_valid_placement(int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g_grid[row][i] == num)
			return (0);
		if (g_grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	is_row_complete(int row)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g_grid[row][i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_col_complete(int col)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g_grid[i][col] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_all_constraints(void)
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		if (!check_visibility(r, 0, 0) || !check_visibility(r, 0, 1))
			return (0);
		r++;
	}
	c = 0;
	while (c < 4)
	{
		if (!check_visibility(0, c, 2) || !check_visibility(0, c, 3))
			return (0);
		c++;
	}
	return (1);
}

int	check_partial_constraints(int row, int col)
{
	int	valid;

	valid = 1;
	if (is_row_complete(row))
	{
		if (!check_visibility(row, 0, 0) || !check_visibility(row, 0, 1))
			valid = 0;
	}
	if (valid && is_col_complete(col))
	{
		if (!check_visibility(0, col, 2) || !check_visibility(0, col, 3))
			valid = 0;
	}
	return (valid);
}
