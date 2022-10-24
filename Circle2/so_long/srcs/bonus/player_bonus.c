/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:06:02 by jikoo             #+#    #+#             */
/*   Updated: 2022/10/24 21:12:34 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_init_player(t_game *game)
{
	int	col;
	int	row;

	game->player.cnt = 0;
	game->player.direction = Stop;
	row = 0;
	while (row < game->map.row)
	{
		col = 0;
		while (col < game->map.col)
		{
			if (game->map.map_str[row * game->map.col + col] == 'P')
			{
				game->player.col = col;
				game->player.row = row;
			}
			col++;
		}
		row++;
	}
	game->player.x = game->player.col * SIZE;
	game->player.y = game->player.row * SIZE;
}
