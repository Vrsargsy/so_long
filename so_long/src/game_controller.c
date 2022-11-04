/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:00:24 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 21:00:25 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_timers(t_env *env)
{
	env->coll_timer++;
	env->enemy_timer++;
	env->enemy_anim_timer++;
	env->dir_change_timer++;
}

void	update_animations(t_env *env)
{
	int	i;

	if (env->coll_timer >= COIN_ANIMATION_SPEED)
	{
		env->coll_timer = 0;
		env->coll_index = (env->coll_index + 1) % 5;
	}
	if (env->enemy_timer >= ENEMY_MOVE_SPEED)
		env->enemy_timer = 0;
	if (env->dir_change_timer >= CHANGE_DIR_SPEED)
		env->dir_change_timer = 0;
	i = -1;
	while (++i)
	{
		if (env->dir_change_timer == i * CHANGE_DIR_SPEED / ENEMY_COUNT)
			env->enemies[i].move_dir = (env->enemies[i].move_dir + 1) % 4;
	}
	if (env->enemy_anim_timer == ENEMY_ANIM_SPEED)
	{
		env->enemy_anim_timer = 0;
		env->enemy_anim_index = (env->enemy_anim_index + 1) % 3;
	}
}

void	check_lose(t_env *env)
{
	int	i;

	i = -1;
	while (++i < ENEMY_COUNT)
	{
		if (!vectors_are_diff(env->enemies[i].pos, env->player.index))
			lose_game(env);
	}
}

int	update(t_env *env)
{
	update_timers(env);
	update_animations(env);
	patrol(env);
	draw_window(env);
	check_lose(env);
	return (0);
}
