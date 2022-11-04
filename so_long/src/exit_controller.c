/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:59:41 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 20:59:43 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_env *env)
{
	destroy_textures(env);
	clear_map(env);
	mlx_destroy_window(env->mlx, env->mlx_window);
	exit(0);
}

void	exit_game_with_error(int error_code)
{
	if (error_code == CANNOT_READ)
		print_error_text(CANNOT_READ_TEXT);
	else if (error_code == WRONG_LETTER)
		print_error_text(WRONG_LETTER_TEXT);
	else if (error_code == MISSING_PART)
		print_error_text(MISSING_PART_TEXT);
	else if (error_code == NOT_RECTANGULAR)
		print_error_text(NOT_RECTANGULAR_TEXT);
	else if (error_code == NOT_SURROUNDED_WALLS)
		print_error_text(NOT_SURROUNDED_WALLS_TEXT);
	else if (error_code == WRONG_NUM_OF_ARGS)
		print_error_text(WRONG_NUM_OF_ARGS_TEXT);
	else if (error_code == WRONG_FILE_NAME)
		print_error_text(WRONG_FILE_NAME_TEXT);
	exit(error_code);
}

void	win_game(t_env *env)
{
	print_win_text(env->player.data.steps);
	exit_game(env);
}

void	lose_game(t_env *env)
{
	print_lose_text();
	exit_game(env);
}
