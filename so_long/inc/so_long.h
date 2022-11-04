/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:57:47 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 20:57:48 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "so_long_structs.h"
# include "so_long_macros.h"
# include "get_next_line.h"

//map parse and clear
void		parse_map(char *file_path, t_env *env);
void		clear_map(t_env *env);

//init functions
t_img		img_init(t_env *env, char *addr);
void		init_all(t_env *env, char *map_path);

//adding listeners with key_code
int			add_listeners(int key_code, void *params);

//function which is being called every frame
int			update(t_env *env);

//game control
void		exit_game(t_env *env);
void		exit_game_with_error(int error_code);
void		win_game(t_env *env);
void		lose_game(t_env *env);

//checks
void		check_input_errors(char *file_name);
void		check_map_errors(t_env *env);

//player functions
void		update_data(t_env *env);
void		get_player_data(t_env *env);
void		player_move(t_env *env, int dir);
void		set_player_pos(t_env *env, int i, int j);

//drawing functions
void		draw_stats(t_env *env);
void		draw_window(t_env *env);
void		draw_win_text(t_env *env);
void		draw_collectable(t_env *env, int i, int j);

//printing functions
void		print_error_text(char *text);
void		print_win_text(int steps);
void		print_lose_text(void);

//enemy controls
void		create_enemies(t_env *env);
void		patrol(t_env *env);

//texture init and destroy
void		textures_init(t_env *env);
void		destroy_textures(t_env *env);

//utils
char		*ft_itoa(int n);
void		print_char(int ch);
void		print_str(char *str);
int			ft_strcmp(const char *s1, const char *s2);

//vector operations
t_vector	new_vector(int i, int j);
t_vector	get_vector(int dir);
t_vector	get_move_vector(int dir);
t_vector	unit_vector(t_vector vector);
t_vector	vector_sum(t_vector first, t_vector second);
t_v_data	new_v_data(int i, int j, int k);
t_vector	vector_difference(t_vector first, t_vector second);
int			vectors_are_diff(t_vector first, t_vector second);

#endif
