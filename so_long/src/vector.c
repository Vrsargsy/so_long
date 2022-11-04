/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:02:23 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 21:02:31 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	new_vector(int i, int j)
{
	t_vector	vector;

	vector.x = i;
	vector.y = j;
	return (vector);
}

t_v_data	new_v_data(int i, int j, int k)
{
	t_v_data	data;

	data.start = i;
	data.end = j;
	data.cols = k;
	return (data);
}

t_vector	vector_sum(t_vector first, t_vector second)
{
	t_vector	result;

	result.x = first.x + second.x;
	result.y = first.y + second.y;
	return (result);
}

t_vector	vector_difference(t_vector first, t_vector second)
{
	return (new_vector(first.x - second.x, first.y - second.y));
}
