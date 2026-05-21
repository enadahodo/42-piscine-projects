/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehodo <ehodo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:42:29 by ehodo             #+#    #+#             */
/*   Updated: 2025/09/14 20:11:49 by ehodo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**g_grid;
int	*g_constraints;

static	void	free_partial_grid(int limit)
{
	while (--limit >= 0)
		free(g_grid[limit]);
}

static	int	allocate_grid_rows(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		g_grid[i] = malloc(4 * sizeof * g_grid[i]);
		if (!g_grid[i])
		{
			free_partial_grid(i);
			free(g_grid);
			g_grid = NULL;
			free(g_constraints);
			g_constraints = NULL;
			return (0);
		}
		i++;
	}
	return (1);
}

int	allocate_memory(void)
{
	g_constraints = malloc(16 * sizeof * g_constraints);
	if (!g_constraints)
		return (0);
	g_grid = malloc(4 * sizeof * g_grid);
	if (!g_grid)
	{
		free(g_constraints);
		g_constraints = NULL;
		return (0);
	}
	if (!allocate_grid_rows())
		return (0);
	return (1);
}

void	free_memory(void)
{
	int	i;

	if (g_grid)
	{
		i = 0;
		while (i < 4)
		{
			if (g_grid[i])
				free(g_grid[i]);
			i++;
		}
		free(g_grid);
		g_grid = NULL;
	}
	if (g_constraints)
	{
		free(g_constraints);
		g_constraints = NULL;
	}
}
