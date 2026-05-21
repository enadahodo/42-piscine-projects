/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbushi <fbushi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:49:36 by fbushi            #+#    #+#             */
/*   Updated: 2025/09/06 16:23:32 by fbushi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

static void	print_char(int row, int col, int x, int y)
{
	if (row == 1)
	{
		if (col == 1)
			ft_putchar('A');
		else if (col == x)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else if (row == y)
	{
		if (col == 1)
			ft_putchar('A');
		else if (col == x)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if (col == 1 || col == x)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	row;
	int	col;

	if (x <= 0 || y <= 0)
		return ;
	row = 1;
	while (row <= y)
	{
		col = 1;
		while (col <= x)
		{
			print_char(row, col, x, y);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
