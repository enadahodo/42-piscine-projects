/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehodo <ehodo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:42:29 by ehodo             #+#    #+#             */
/*   Updated: 2025/09/13 17:45:28 by ehodo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_error();
		return (1);
	}
	if (!allocate_memory())
	{
		print_error();
		return (1);
	}
	if (!process_input(argv[1]))
	{
		free_memory();
		return (1);
	}
	free_memory();
	return (0);
}
