/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectables.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:58:50 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 20:58:52 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_collectable(t_env *env, int i, int j)
{
	t_vector	pos;

	pos = new_vector(i * env->img_width,
			j * env->img_height);
	mlx_put_image_to_window(env->mlx, env->mlx_window,
		env->textures.coin[env->coll_index].mlx_img,
		pos.x, pos.y);
}
