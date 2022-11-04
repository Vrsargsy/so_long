/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:59:09 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 20:59:11 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_env *env, int i, int j)
{
	if (env->map[i][j] == WALL)
		mlx_put_image_to_window(env->mlx, env->mlx_window,
			env->textures.wall.mlx_img,
			j * env->img_width, i * env->img_height);
	else
	{
		mlx_put_image_to_window(env->mlx, env->mlx_window,
			env->textures.empty.mlx_img,
			j * env->img_width, i * env->img_height);
		if (env->map[i][j] == COLLECTABLE)
			draw_collectable(env, j, i);
		else if (env->map[i][j] == EXIT && env->player.data.collectibles == 0)
			mlx_put_image_to_window(env->mlx, env->mlx_window,
				env->textures.exit.mlx_img,
				j * env->img_width, i * env->img_height);
	}
}

void	draw_map(t_env *env)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(env->mlx, env->mlx_window);
	while (++i < env->map_height)
	{
		j = -1;
		while (++j < env->map_width)
		{
			draw_tile(env, i, j);
		}
	}
}

void	draw_player(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->mlx_window,
		env->player.sprite.mlx_img,
		env->player.pos.x, env->player.pos.y);
}

void	draw_enemies(t_env *env)
{
	int	i;

	i = -1;
	while (++i < ENEMY_COUNT)
	{
		mlx_put_image_to_window(env->mlx, env->mlx_window,
			env->textures.enemy[env->enemy_anim_index].mlx_img,
			env->enemies[i].pos.x * env->img_width,
			env->enemies[i].pos.y * env->img_height);
	}
}

void	draw_window(t_env *env)
{
	draw_map(env);
	draw_player(env);
	draw_enemies(env);
	draw_stats(env);
}
