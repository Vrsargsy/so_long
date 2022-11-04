/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:01:20 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 21:01:20 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_env *env, int dir)
{
	t_vector	vector;

	vector = vector_sum(get_vector(dir), env->player.index);
	if (env->map[vector.y][vector.x] == EXIT &&
			env->player.data.collectibles == 0)
		return (WINMOVE);
	if (env->map[vector.y][vector.x] != WALL)
		return (POSMOVE);
	return (CANTMOVE);
}

static void	change_dir(t_env *env, int dir)
{
	if (dir == RIGHT)
		env->player.sprite = env->player_sprites.right;
	else if (dir == LEFT)
		env->player.sprite = env->player_sprites.left;
	else if (dir == UP)
		env->player.sprite = env->player_sprites.up;
	else if (dir == DOWN)
		env->player.sprite = env->player_sprites.down;
}

void	set_player_pos(t_env *env, int i, int j)
{
	env->player.index.x = i;
	env->player.index.y = j;
	env->player.pos.x = env->player.index.x * env->img_width;
	env->player.pos.y = env->player.index.y * env->img_height;
}

void	player_move(t_env *env, int dir)
{
	t_vector	new_pos;

	change_dir(env, dir);
	if (check_move(env, dir) == CANTMOVE)
		return ;
	new_pos = vector_sum(get_vector(dir), env->player.index);
	env->player.index = new_pos;
	env->player.pos = new_vector(new_pos.x * env->img_width,
			new_pos.y * env->img_height);
	if (env->map[env->player.index.y][env->player.index.x] == EXIT
			&& env->player.data.collectibles == 0)
		win_game(env);
	update_data(env);
}
