/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnepfumb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:11:25 by mnepfumb          #+#    #+#             */
/*   Updated: 2017/11/20 11:33:40 by mnepfumb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# define BUFF_SIZE 1024

int					ft_atoi(const char *nptr);
int					ft_isdigit(int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
int					ft_toupper(int c);
void				ft_putnbr(int n);
void				ft_putchar(char c);
int					get_next_line(const int fd, char **line);

char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
void				*ft_memalloc(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);

#endif
