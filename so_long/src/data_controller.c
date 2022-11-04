/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:58:59 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 20:59:00 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_data(t_env *env)
{
	int	i;
	int	j;

	i = -1;
	while (++i < env->map_height)
	{
		j = -1;
		while (++j < env->map_width)
		{
			if (env->map[i][j] == COLLECTABLE)
				env->player.data.collectibles++;
			if (env->map[i][j] == START)
			{
				env->map[i][j] = EMPTY;
				set_player_pos(env, j, i);
			}
		}
	}
}

void	update_data(t_env *env)
{
	env->player.data.steps++;
	if (env->map[env->player.index.y][env->player.index.x] == COLLECTABLE)
	{
		env->map[env->player.index.y][env->player.index.x] = EMPTY;
		env->player.data.collectibles--;
	}
}
