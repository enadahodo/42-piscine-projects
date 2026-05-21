/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehodo <ehodo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:42:29 by ehodo             #+#    #+#             */
/*   Updated: 2025/09/13 17:45:49 by ehodo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	try_number(int pos, int row, int col, int num)
{
	g_grid[row][col] = num;
	if (check_partial_constraints(row, col))
	{
		if (solve(pos + 1))
			return (1);
	}
	g_grid[row][col] = 0;
	return (0);
}

int	solve(int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == 16)
		return (check_all_constraints());
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_valid_placement(row, col, num))
		{
			if (try_number(pos, row, col, num))
				return (1);
		}
		num++;
	}
	return (0);
}
