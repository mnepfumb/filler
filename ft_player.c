/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:33:33 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/11/23 23:47:25 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

static int		check_column(t_info *info, int x)
{
	int		y;

	y = 0;
	while (y < info->i_col)
	{
		if (info->map[y][x] == info->letter)
			return (1);
		y++;
	}
	return (0);
}

static int		check_line(t_info *info, int y, char c)
{
	int		x;

	x = 0;
	while (x < info->i_row)
	{
		if (info->map[y][x] == c || info->map[y][x] == ft_toupper(c))
			return (1);
		x++;
	}
	return (0);
}

static int		check_aggresive(t_info *info)
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
			{
				if (check_line(info, y, 'x') == 1
						|| check_line(info, y, 'o') == 1)
					return (1);
				else
					return (0);
			}
			x--;
		}
		y--;
	}
	return (0);
}

static void		stop_aggresive(t_info *info)
{
	int		x;

	x = 0;
	while (x < info->i_col)
	{
		if (info->map[0][x] == info->letter
				|| info->map[info->i_col - 1][x] == info->letter)
		{
			info->stop_agr = 1;
			return ;
		}
		x++;
	}
	info->stop_agr = 0;
}

int				player(t_info *info, t_piece *piece)
{
	info->stop = 0;
	get_map(info, piece);
	get_pivotmap(info);
	stop_aggresive(info);
	if (check_column(info, info->i_row - 1) == 0 &&
			check_column(info, 0) == 0 &&
			check_line(info, info->pivot, 'o') == 1 &&
			check_aggresive(info) == 0)
		place_left(info, piece);
	else if (check_aggresive(info) == 1 && info->stop_agr == 0)
		move_top(info, piece);
	else
		move_bottom(info, piece);
	if (info->stop == 1 || info->cantmv == 1)
		move_bottom(info, piece);
	if (info->finish == 1)
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
		return (0);
	}
	return (1);
}
