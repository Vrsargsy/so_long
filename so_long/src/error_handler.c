/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:59:26 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 20:59:27 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_input_errors(char *file_name)
{
	int		fd;
	int		read_count;
	int		len;
	char	temp[5];

	len = ft_strlen(file_name);
	if (len < 5 || ft_strcmp(file_name +(len - 4), ".ber"))
		exit_game_with_error(WRONG_FILE_NAME);
	fd = open(file_name, O_RDONLY);
	if (fd == ERROR)
		exit_game_with_error(CANNOT_READ);
	read_count = read(fd, temp, 0);
	if (read_count == -1)
		exit_game_with_error(CANNOT_READ);
	close(fd);
}

static void	check_for_attributes(t_env *env, int error_code)
{
	t_v_data	val_data;
	t_vector	iter;

	val_data = new_v_data(0, 0, 0);
	iter = new_vector(-1, -1);
	while (++iter.x < env->map_height)
	{
		iter.y = -1;
		while (env->map[iter.x][++iter.y])
		{
			if (env->map[iter.x][iter.y] == START)
				val_data.start++;
			else if (env->map[iter.x][iter.y] == EXIT)
				val_data.end++;
			else if (env->map[iter.x][iter.y] == COLLECTABLE)
				val_data.cols++;
		}
	}
	if (val_data.cols < 1 || val_data.start != 1 || val_data.end != 1)
		error_code = MISSING_PART;
	if (error_code != 0)
	{
		clear_map(env);
		exit_game_with_error(error_code);
	}
}

void	check_map_errors(t_env *env)
{
	int			error_code;
	char		ch;
	t_vector	iter;

	iter = new_vector(-1, -1);
	error_code = 0;
	while (++iter.x < env->map_height && error_code == 0)
	{
		iter.y = -1;
		while (env->map[iter.x][++iter.y] && error_code == 0)
		{
			ch = env->map[iter.x][iter.y];
			if ((iter.x == 0 || iter.x == env->map_height - 1 || iter.y == 0
					|| iter.y == env->map_width - 1) && ch != WALL)
				error_code = NOT_SURROUNDED_WALLS;
			if (!(ch == WALL || ch == EMPTY || ch == COLLECTABLE
					|| ch == EXIT || ch == START))
				error_code = WRONG_LETTER;
		}
		if (iter.y != env->map_width)
			error_code = NOT_RECTANGULAR;
	}
	check_for_attributes(env, error_code);
}
