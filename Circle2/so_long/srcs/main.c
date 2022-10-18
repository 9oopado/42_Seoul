/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:51:58 by jikoo             #+#    #+#             */
/*   Updated: 2022/10/18 19:43:48 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	(void)game;
	(void)argv;
	if (argc == 1)
		ft_return_error("Map file is required.");
	if (argc == 2)
	{
		ft_init_map(&game.map, argv[1]);
		return (0);
	}
	ft_return_error("Too many arguments.");
}
