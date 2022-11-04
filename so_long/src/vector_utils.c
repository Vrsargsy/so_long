/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:02:38 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 21:02:39 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	get_vector(int dir)
{
	t_vector	vector;

	vector.x = 0;
	vector.y = 0;
	if (dir == LEFT)
		vector.x = -1;
	else if (dir == RIGHT)
		vector.x = 1;
	else if (dir == UP)
		vector.y = -1;
	else
		vector.y = 1;
	return (vector);
}

t_vector	get_move_vector(int dir)
{
	t_vector	vector;

	vector.x = 0;
	vector.y = 0;
	if (dir == LEFT_DIR)
		vector.x = -1;
	else if (dir == RIGHT_DIR)
		vector.x = 1;
	else if (dir == UP_DIR)
		vector.y = -1;
	else
		vector.y = 1;
	return (vector);
}

t_vector	unit_vector(t_vector vector)
{
	int	len;

	len = vector.x + vector.y;
	return (new_vector(vector.x / len, vector.y / len));
}

int	vectors_are_diff(t_vector first, t_vector second)
{
	int	x_dif;
	int	y_dif;

	x_dif = first.x - second.x;
	y_dif = first.y - second.y;
	if (first.x < second.x)
		x_dif = -x_dif;
	if (first.y < second.y)
		y_dif = -y_dif;
	return (x_dif + y_dif);
}
