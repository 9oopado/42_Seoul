/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:09:18 by jikoo             #+#    #+#             */
/*   Updated: 2022/10/20 18:43:07 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_print_err_and_exit(char *message)
{
	printf("Error\n" RED "%s\n" RESET, message);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		ft_print_err_and_exit("Invalid number of arguments!");
	ft_init_map(&game.map, argv[1]);
	ft_start_game(&game);
	return (0);
}
