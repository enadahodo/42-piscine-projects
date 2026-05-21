/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehodo <ehodo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:42:29 by ehodo             #+#    #+#             */
/*   Updated: 2025/09/13 17:45:38 by ehodo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	parse_digit(char *input, int *i, int *j)
{
	if (input[*i] < '1' || input[*i] > '4')
		return (0);
	g_constraints[*j] = input[*i] - '0';
	(*j)++;
	(*i)++;
	return (1);
}

static int	parse_space(char *input, int *i, int j)
{
	if (j < 16)
	{
		if (input[*i] != ' ')
			return (0);
		(*i)++;
		if (input[*i] < '1' || input[*i] > '4')
			return (0);
	}
	return (1);
}

int	parse_input(char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i] && j < 16)
	{
		if (!parse_digit(input, &i, &j))
			return (0);
		if (!parse_space(input, &i, j))
			return (0);
	}
	if (j != 16 || input[i] != '\0')
		return (0);
	return (1);
}
