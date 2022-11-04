/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:01:58 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 21:02:00 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_col_textures(t_env *env)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		mlx_destroy_image(env->mlx, env->textures.coin[i].mlx_img);
	}
	free(env->textures.coin);
}

static void	destroy_enemy_textures(t_env *env)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		mlx_destroy_image(env->mlx, env->textures.enemy[i].mlx_img);
	}
	free(env->textures.enemy);
}

void	destroy_textures(t_env *env)
{
	destroy_col_textures(env);
	destroy_enemy_textures(env);
	mlx_destroy_image(env->mlx, env->textures.wall.mlx_img);
	mlx_destroy_image(env->mlx, env->textures.empty.mlx_img);
	mlx_destroy_image(env->mlx, env->textures.exit.mlx_img);
	mlx_destroy_image(env->mlx, env->player_sprites.up.mlx_img);
	mlx_destroy_image(env->mlx, env->player_sprites.down.mlx_img);
	mlx_destroy_image(env->mlx, env->player_sprites.left.mlx_img);
	mlx_destroy_image(env->mlx, env->player_sprites.right.mlx_img);
}
