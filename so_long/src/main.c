/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:01:02 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 21:01:03 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc == 2)
	{
		init_all(&env, argv[1]);
	}
	else
		exit_game_with_error(WRONG_NUM_OF_ARGS);
	mlx_loop(env.mlx);
	return (0);
}
