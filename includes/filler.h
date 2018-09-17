/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:35:23 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/11/21 13:35:32 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>

# include "../libft/libft.h"

typedef struct	s_info
{
	int			nbr;
	int			pivot;
	int			i_col;
	int			i_row;
	int			stop_agr;
	int			stop;
	int			cantmv;
	int			finish;
	char		letter;
	char		**map;
}				t_info;

typedef struct	s_piece
{
	int			p_col;
	int			p_row;
	int			x;
	int			y;
	char		**piece;
}				t_piece;

int				main(void);
int				player(t_info *info, t_piece *piece);
int				check_piece_info(t_info *info, t_piece *piece, int x, int y);
void			move_top(t_info *info, t_piece *piece);
void			move_bottom(t_info *info, t_piece *piece);
void			place_left(t_info *info, t_piece *piece);
void			get_play_info(t_info *info);
void			get_num_player(t_info *info);
void			get_row_and_col(t_info *info);
void			get_play_chr(t_info *info);
void			get_pivotmap(t_info *info);
void			get_piece(t_piece *piece);
void			get_map(t_info *info, t_piece *piece);

#endif
