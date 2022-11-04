/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:00:55 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 21:00:56 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	data_init(t_env *env)
{
	env->map_height = 0;
	env->map_width = 0;
	env->map = NULL;
	env->player.data.collectibles = 0;
	env->player.data.steps = 0;
	env->coll_index = 0;
	env->dir_change_timer = 0;
	env->enemy_anim_timer = 0;
}

t_img	img_init(t_env *env, char *addr)
{
	t_img	img;

	img.addr = addr;
	img.mlx_img = mlx_xpm_file_to_image(env->mlx, img.addr,
			&img.width, &img.height);
	return (img);
}

static void	window_init(t_env *env)
{
	env->window_width = env->map_width * env->img_width;
	env->window_height = env->map_height * env->img_height;
	env->mlx_window = mlx_new_window(env->mlx, env->window_width,
			env->window_height, "Game window");
}

void	init_all(t_env *env, char *argv)
{	
	data_init(env);
	check_input_errors(argv);
	parse_map(argv, env);
	check_map_errors(env);
	create_enemies(env);
	env->mlx = mlx_init();
	textures_init(env);
	get_player_data(env);
	window_init(env);
	mlx_hook(env->mlx_window, 2, 1L << 2, (void *)add_listeners, env);
	mlx_hook(env->mlx_window, 17, 1L << 17, (void *)exit_game, env);
	mlx_loop_hook(env->mlx, update, env);
}
