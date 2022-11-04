/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:59:49 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 20:59:51 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static char	*make_str(long n, int hassign)
{
	int				len;
	char			*str;
	unsigned int	num;

	len = 0;
	num = n;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	len += hassign;
	str = malloc(len + 1);
	if (!str)
		return (0);
	str[len] = 0;
	while (len)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
	if (hassign)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*str;

	num = (long)n;
	if (n == 0)
	{
		str = malloc(2);
		str[0] = '0';
		str[1] = 0;
	}
	else if (n < 0)
		str = make_str(-num, 1);
	else
		str = make_str(num, 0);
	return (str);
}
