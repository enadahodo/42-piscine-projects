/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehodo <ehodo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:42:29 by ehodo             #+#    #+#             */
/*   Updated: 2025/09/13 18:27:58 by ehodo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

/* Global variables */
extern int	**g_grid;
extern int	*g_constraints;

/* Memory Management - memory.c */
int		allocate_memory(void);
void	free_memory(void);

/* Printing - print.c */
void	print_grid(void);
void	print_error(void);

/* Visibility Check - visibility.c */
int		check_visibility(int row, int col, int direction);

/* Validations - validation.c */
int		is_valid_placement(int row, int col, int num);
int		is_row_complete(int row);
int		is_col_complete(int col);
int		check_all_constraints(void);
int		check_partial_constraints(int row, int col);

/* Solver - solver.c */
int		solve(int pos);

/* Parser - parser.c sh1*/
int		parse_input(char *input);

/* Grid Initialization - grid.c */
void	init_grid(void);

/* Input Processor - process.c */
int		process_input(char *input);

#endif