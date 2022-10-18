/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:44:10 by jikoo             #+#    #+#             */
/*   Updated: 2022/10/18 19:46:39 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

typedef struct s_map
{
	int		col;
	int		row;
	char	*map_str;
}	t_map;

typedef struct s_game
{
	t_map	map;
}	t_game;

// UTILS
void	ft_return_error(char *message);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strrepl(char *str, char c1, char c2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strldup(char *str, int start, int size);

// MAP
void	ft_init_map(t_map *map, char *file_name);

// GET_NEXT_LINE
char	*ft_get_next_line(int fd);

#endif
