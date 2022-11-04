/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:59:35 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 20:59:37 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	add_listeners(int key, void *params)
{
	t_env	*env;

	env = (t_env *) params;
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		player_move(env, key);
	else if (key == EXITCODE)
		exit_game(env);
	return (0);
}
