/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:01:52 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 21:01:53 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_text_background(t_env *env, int start_x, int start_y, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < env->img_height - 5)
	{
		j = -1;
		while (++j < len)
		{
			if (i == 0 || j == 0 || i == env->img_height - 1 || j == len - 1)
				mlx_pixel_put(env->mlx, env->mlx_window, start_x + j,
					start_y + i, GREEN1);
			else
				mlx_pixel_put(env->mlx, env->mlx_window, start_x + j,
					start_y + i, WHITE);
		}
	}
}

void	draw_stat(t_env *env, char *str, int num, t_vector coord)
{
	char	*temp;
	char	*text_to_draw;

	temp = ft_itoa(num);
	text_to_draw = ft_strjoin(str, temp);
	mlx_string_put(env->mlx, env->mlx_window, coord.x + env->img_width / 2,
		coord.y, 0, text_to_draw);
	free(temp);
	free(text_to_draw);
}

void	draw_stats(t_env *env)
{
	t_vector	steps_coord;
	t_vector	cols_coord;

	steps_coord = new_vector(0, 0);
	cols_coord = new_vector(5 * env->img_width, 0);
	draw_text_background(env, 0, 0, 5 * env->img_width);
	draw_stat(env, "STEPS: ", env->player.data.steps, steps_coord);
	draw_text_background(env, cols_coord.x, cols_coord.y, 8 * env->img_width);
	draw_stat(env, "COLLECTABLES: ", env->player.data.collectibles,
		cols_coord);
}
