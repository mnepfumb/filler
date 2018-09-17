/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:33:16 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/11/21 13:33:19 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

static int	move_right(t_info *info, t_piece *piece, int y, int x)
{
	int		i;
	int		j;

	i = piece->p_col - 1;
	while (i >= 0)
	{
		j = piece->p_row - 1;
		while (j >= 0)
		{
			if (piece->piece[i][j] == '*')
			{
				if (check_piece_info(info, piece, x - j, y - i))
				{
					ft_putnbr(y - i);
					ft_putchar(' ');
					ft_putnbr(x - j);
					ft_putchar('\n');
					return (1);
				}
			}
			j--;
		}
		i--;
	}
	return (0);
}

static int	move_left(t_info *info, t_piece *piece, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < piece->p_col)
	{
		j = 0;
		while (j < piece->p_row)
		{
			if (piece->piece[i][j] == '*')
			{
				if (check_piece_info(info, piece, x - j, y - i))
				{
					ft_putnbr(y - i);
					ft_putchar(' ');
					ft_putnbr(x - j);
					ft_putchar('\n');
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void		move_top(t_info *info, t_piece *piece)
{
	int		y;
	int		x;

	y = 0;
	while (y < info->i_col)
	{
		x = 0;
		while (x < info->i_row)
		{
			if (info->map[y][x] == info->letter)
				if (move_right(info, piece, y, x) == 1)
					return ;
			x++;
		}
		y++;
	}
	info->stop = 1;
}

void		move_bottom(t_info *info, t_piece *piece)
{
	int		y;
	int		x;

	y = info->i_col - 1;
	while (y > 0)
	{
		x = info->i_row - 1;
		while (x > 0)
		{
			if (info->map[y][x] == info->letter)
				if (move_left(info, piece, y, x) == 1)
					return ;
			x--;
		}
		y--;
	}
	info->finish = 1;
}

void		place_left(t_info *info, t_piece *piece)
{
	int		y;
	int		x;

	y = info->pivot + (info->i_col / 10) - (info->i_col / 11);
	while (y < info->pivot + (info->i_col / 10) + (info->i_col / 11))
	{
		x = 0;
		while (x < info->i_row)
		{
			if (info->map[y][x] == info->letter)
				if (move_right(info, piece, y, x) == 1)
					return ;
			x++;
		}
		y++;
	}
	info->cantmv = 1;
}
