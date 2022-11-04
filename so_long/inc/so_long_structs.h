/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:58:05 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 20:58:08 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_data
{
	int	steps;
	int	collectibles;
}				t_data;

typedef struct s_v_data
{
	int	start;
	int	end;
	int	cols;
}				t_v_data;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		width;
	int		height;
}				t_img;

typedef struct s_player
{
	t_vector	index;
	t_vector	pos;
	t_img		sprite;
	t_data		data;
	int			current_sprite;
}				t_player;

typedef struct s_enemy
{
	t_vector	pos;
	t_img		sprite;
	int			move_dir;
	int			current_sprite;
}				t_enemy;

typedef struct s_textures
{
	t_img	wall;
	t_img	empty;
	t_img	*coin;
	t_img	*enemy;
	t_img	exit;
}				t_textures;

typedef struct s_psprites
{
	t_img	left;
	t_img	right;
	t_img	up;
	t_img	down;
}				t_psprites;

typedef struct s_env
{
	t_enemy		*enemies;
	t_player	player;
	t_psprites	player_sprites;
	t_textures	textures;
	void		*mlx;
	void		*mlx_window;
	char		**map;
	int			window_width;
	int			window_height;
	int			img_width;
	int			img_height;
	int			map_width;
	int			map_height;
	int			enemy_timer;
	int			coll_index;
	int			coll_timer;
	int			dir_change_timer;
	int			enemy_anim_timer;
	int			enemy_anim_index;
}				t_env;
#endif
