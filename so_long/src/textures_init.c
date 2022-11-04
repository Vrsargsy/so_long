/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:02:14 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 21:02:15 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_enemy_textures(t_env *env)
{
	env->textures.enemy = malloc(sizeof(t_img) * 3);
	env->textures.enemy[0] = img_init(env, "./sprites/pleft.xpm");
	env->textures.enemy[1] = img_init(env, "./sprites/pright.xpm");
	env->textures.enemy[2] = img_init(env, "./sprites/pleft.xpm");
}

static void	init_coin_textures(t_env *env)
{
	env->textures.coin = malloc(sizeof(t_img) * 5);
	env->textures.coin[0] = img_init(env, "./sprites/left_coin.xpm");
	env->textures.coin[1] = img_init(env, "./sprites/right_coin.xpm");
	env->textures.coin[2] = img_init(env, "./sprites/left_coin.xpm");
	env->textures.coin[3] = img_init(env, "./sprites/right_coin.xpm");
	env->textures.coin[4] = img_init(env, "./sprites/left_coin.xpm");
}

void	textures_init(t_env *env)
{
	init_coin_textures(env);
	init_enemy_textures(env);
	env->textures.wall = img_init(env, "./sprites/ice_block.xpm");
	env->textures.empty = img_init(env, "./sprites/background.xpm");
	env->player_sprites.up = img_init(env, "./sprites/hero_right.xpm");
	env->player_sprites.down = img_init(env, "./sprites/hero_left.xpm");
	env->player_sprites.right = img_init(env, "./sprites/hero_right.xpm");
	env->player_sprites.left = img_init(env, "./sprites/hero_left.xpm");
	env->textures.exit = img_init(env, "./sprites/finish.xpm");
	env->img_width = env->textures.wall.width;
	env->img_height = env->textures.wall.height;
	env->player.sprite = env->player_sprites.right;
}
