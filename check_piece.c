/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:32:55 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/11/21 13:33:00 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

static int	check_piece_size(t_info *info, t_piece *piece, int x, int y)
{
	if (x > info->i_row || x < 0)
		return (0);
	if (y > info->i_col || y < 0)
		return (0);
	if (x + piece->p_row > info->i_row)
		return (0);
	if (y + piece->p_col > info->i_col)
		return (0);
	return (1);
}

static int	check_piece_pos(t_info *info, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		tmp;
	int		count;

	i = -1;
	tmp = x;
	count = 0;
	while (++i < piece->p_col)
	{
		j = -1;
		x = tmp;
		while (++j < piece->p_row)
		{
			if (info->nbr == 1)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'O')
					count++;
			if (info->nbr == 2)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'X')
					count++;
			x++;
		}
		y++;
	}
	return ((count > 1) ? 0 : 1);
}

static int	check_piece_adverse_pos(t_info *info, t_piece *piece, int x, int y)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	tmp = x;
	while (i < piece->p_col)
	{
		j = 0;
		x = tmp;
		while (j < piece->p_row)
		{
			if (info->nbr == 1)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'X')
					return (0);
			if (info->nbr == 2)
				if (piece->piece[i][j] == '*' && info->map[y][x] == 'O')
					return (0);
			j++;
			x++;
		}
		i++;
		y++;
	}
	return (1);
}

int			check_piece_info(t_info *info, t_piece *piece, int x, int y)
{
	if (check_piece_size(info, piece, x, y) == 0)
		return (0);
	if (check_piece_pos(info, piece, x, y) == 0)
		return (0);
	if (check_piece_adverse_pos(info, piece, x, y) == 0)
		return (0);
	return (1);
}
