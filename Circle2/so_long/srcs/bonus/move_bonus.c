/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:20:11 by jikoo             #+#    #+#             */
/*   Updated: 2022/10/26 17:38:46 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_move_up(t_game *game)
{
	int	cur;
	int	nxt;

	if (game->player.x % 32)
		return ;
	cur = game->map.col * game->player.row + game->player.col;
	nxt = cur - game->map.col;
	if (game->map.map_str[nxt] == 'E' && game->collectible)
		return ;
	if (game->map.map_str[nxt] != '1')
	{
		game->player.y -= 8;
		if (game->player.y % 32 == 0)
		{
			if (game->map.map_str[nxt] == 'C')
				game->collectible--;
			if (game->map.map_str[nxt] == 'E' && !game->collectible)
				ft_exit_game(game);
			game->player.row--;
			game->map.map_str[cur] = '0';
			game->map.map_str[nxt] = 'P';
		}
		game->player.cnt++;
		game->player.direction = Up;
		ft_set_sprites(game);
	}
}

void	ft_move_down(t_game *game)
{
	int	cur;
	int	nxt;

	if (game->player.x % 32)
		return ;
	cur = game->map.col * game->player.row + game->player.col;
	nxt = cur + game->map.col;
	if (game->map.map_str[nxt] == 'E' && game->collectible)
		return ;
	if (game->map.map_str[nxt] != '1')
	{
		game->player.y += 8;
		if (game->player.y % 32 == 0)
		{
			if (game->map.map_str[nxt] == 'C')
				game->collectible--;
			if (game->map.map_str[nxt] == 'E' && !game->collectible)
				ft_exit_game(game);
			game->player.row++;
			game->map.map_str[cur] = '0';
			game->map.map_str[nxt] = 'P';
		}
		game->player.cnt++;
		game->player.direction = Down;
		ft_set_sprites(game);
	}
}

void	ft_move_left(t_game *game)
{
	int	cur;
	int	nxt;

	if (game->player.y % 32)
		return ;
	cur = game->map.col * game->player.row + game->player.col;
	nxt = cur - 1;
	if (game->map.map_str[nxt] == 'E' && game->collectible)
		return ;
	if (game->map.map_str[nxt] != '1')
	{
		game->player.x -= 8;
		if (game->player.x % 32 == 0)
		{
			if (game->map.map_str[nxt] == 'C')
				game->collectible--;
			if (game->map.map_str[nxt] == 'E' && !game->collectible)
				ft_exit_game(game);
			game->player.col--;
			game->map.map_str[cur] = '0';
			game->map.map_str[nxt] = 'P';
		}
		game->player.cnt++;
		game->player.direction = Left;
		ft_set_sprites(game);
	}
}

void	ft_move_right(t_game *game)
{
	int	cur;
	int	nxt;

	if (game->player.y % 32)
		return ;
	cur = game->map.col * game->player.row + game->player.col;
	nxt = cur + 1;
	if (game->map.map_str[nxt] == 'E' && game->collectible)
		return ;
	if (game->map.map_str[nxt] != '1')
	{
		game->player.x += 8;
		if (game->player.x % 32 == 0)
		{
			if (game->map.map_str[nxt] == 'C')
				game->collectible--;
			if (game->map.map_str[nxt] == 'E' && !game->collectible)
				ft_exit_game(game);
			game->player.col++;
			game->map.map_str[cur] = '0';
			game->map.map_str[nxt] = 'P';
		}
		game->player.cnt++;
		game->player.direction = Right;
		ft_set_sprites(game);
	}
}
