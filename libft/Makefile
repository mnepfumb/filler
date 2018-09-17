# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 12:36:47 by mnepfumb          #+#    #+#              #
#    Updated: 2017/11/20 11:23:57 by mnepfumb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isdigit.c ft_putnbr.c ft_strjoin.c ft_atoi.c ft_putchar.c ft_toupper.c \
		ft_strsplit.c get_next_line.c ft_strcat.c ft_strdup.c ft_strlen.c ft_strcpy.c \
		ft_strsub.c ft_memalloc.c ft_strlen.c ft_strchr.c ft_bzero.c ft_memset.c

OBJ = $(SRC:.c=.o)

HEADER = libft.h

FLAGS = -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc libft.a $(OBJ)
	ranlib libft.a
	echo "libft compiled"

clean:
	rm -f $(OBJ)
	echo "libft clean"

fclean: clean
	rm -rf $(NAME)
	echo "libft fclean"

re: fclean all
