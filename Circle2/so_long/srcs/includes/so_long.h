/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:38:13 by jikoo             #+#    #+#             */
/*   Updated: 2022/10/20 19:32:09 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE 32
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"

typedef struct s_sprite
{
	void	*black;
	void	*pacfood;
	void	*pacman;
	void	*portal;
	void	*wall;
}	t_sprite;

typedef struct s_map
{
	int		col;
	int		row;
	char	*map_str;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_sprite	sprites;
	t_map		map;
}	t_game;

void	ft_print_err_and_exit(char *message);

void	ft_init_map(t_map *map, char *file_name);

void	ft_start_game(t_game *game);

int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strrepl(char *str, char c1, char c2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strldup(char *str, int start, int size);

char	*ft_get_next_line(int fd);

#endif