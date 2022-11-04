/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:59:17 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 20:59:19 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy	create_enemy(t_env *env, t_vector *iter)
{
	t_enemy	enemy;
	int		found;

	found = 0;
	while (iter->x < env->map_height && !found)
	{
		while (env->map[iter->x][iter->y] && !found)
		{
			if (env->map[iter->x][iter->y] != WALL)
			{
				enemy.pos = new_vector(iter->y, iter->x);
				enemy.sprite = env->player.sprite;
				iter->y = (iter->y + 19) % env->map_width;
				iter->x += (iter->y + 19) / env->map_width;
				found = 1;
			}
			else
				iter->y++;
		}
		if (!found)
			*iter = new_vector(iter->x++, -1);
	}
	return (enemy);
}

void	create_enemies(t_env *env)
{
	int			i;
	t_vector	iter;

	i = -1;
	iter = new_vector(1, 1);
	env->enemies = malloc(sizeof(t_enemy) * ENEMY_COUNT);
	while (++i < ENEMY_COUNT)
	{
		env->enemies[i] = create_enemy(env, &iter);
		env->enemies[i].move_dir = i % 4;
	}
}

int	check_enemy_move(t_env *env, int current_index)
{
	t_vector	expected_pos;
	t_enemy		*enemy;
	t_vector	move_vector;

	enemy = &env->enemies[current_index];
	move_vector = get_move_vector(enemy->move_dir);
	expected_pos = vector_sum(env->enemies[current_index].pos, move_vector);
	if (env->map[expected_pos.y][expected_pos.x] == WALL)
	{
		enemy->move_dir = (enemy->move_dir + 1) % 4;
		return (1);
	}
	return (0);
}

void	enemy_move(t_env *env, int current_index)
{
	t_vector	move_dir;
	t_enemy		*enemy;

	enemy = &env->enemies[current_index];
	while (check_enemy_move(env, current_index))
		;
	move_dir = get_move_vector(enemy->move_dir);
	enemy->pos = vector_sum(enemy->pos, move_dir);
}

void	patrol(t_env *env)
{
	int	i;

	i = -1;
	if (env->enemy_timer == 0)
	{
		while (++i < ENEMY_COUNT)
		{
			enemy_move(env, i);
		}
	}
}
