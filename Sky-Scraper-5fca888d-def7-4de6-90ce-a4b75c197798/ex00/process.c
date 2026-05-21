/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elecini <elecini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:42:29 by ehodo             #+#    #+#             */
/*   Updated: 2025/09/14 19:04:58 by elecini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	process_input(char *input)
{
	if (!parse_input(input))
	{
		print_error();
		return (0);
	}
	init_grid();
	if (solve(0))
		print_grid();
	else
	{
		print_error();
		return (0);
	}
	return (1);
}
