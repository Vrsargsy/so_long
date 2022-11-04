/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:01:12 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 21:01:14 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(char *file_name, t_env *env)
{
	int		fd;
	int		i;
	char	*current_line;

	i = -1;
	fd = open(file_name, O_RDONLY);
	current_line = get_next_line(fd);
	while (current_line != 0)
	{
		free(current_line);
		current_line = get_next_line(fd);
		env->map_height++;
	}
	free(current_line);
	close(fd);
	env->map = malloc(env->map_height * sizeof(char *));
	fd = open(file_name, O_RDONLY);
	while (++i < env->map_height)
	{
		env->map[i] = get_next_line(fd);
	}
	close(fd);
	while (env->map[i - 1][env->map_width])
		env->map_width++;
}

void	clear_map(t_env *env)
{
	int	i;

	i = env->map_height;
	while (--i >= 0)
	{
		free(env->map[i]);
	}
	free(env->map);
}
