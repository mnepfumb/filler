/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:33:49 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/11/23 23:48:39 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void			get_play_chr(t_info *info)
{
	if (info->nbr == 1)
		info->letter = 'O';
	else
		info->letter = 'X';
}

void			get_row_and_col(t_info *info)
{
	char		*line;

	get_next_line(0, &line);
	info->i_col = ft_atoi(&line[8]);
	info->i_row = ft_atoi(&line[11]);
}

void			get_play_info(t_info *info)
{
	get_num_player(info);
	get_play_chr(info);
	get_row_and_col(info);
}

static void		init_strt_val(t_info *info, t_piece *piece)
{
	info->nbr = 0;
	info->pivot = 0;
	info->stop_agr = 0;
	info->stop = 0;
	info->cantmv = 0;
	info->finish = 0;
	piece->p_col = 0;
	piece->p_row = 0;
}

int				main(void)
{
	t_info		info;
	t_piece		piece;

	init_strt_val(&info, &piece);
	get_play_info(&info);
	while (1)
	{
		if (info.nbr == 1 || info.nbr == 2)
			if (player(&info, &piece) == 0)
				break ;
	}
}
