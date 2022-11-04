/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:01:25 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 21:01:26 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_sep_line(int ch, int len)
{
	int	i;

	i = -1;
	print_char('\n');
	while (++i < len)
		print_char(ch);
	print_char('\n');
}

void	print_error_text(char *text)
{
	size_t	len;

	len = ft_strlen(text);
	if (len < ft_strlen(WARNING_TEXT))
		len = ft_strlen(WARNING_TEXT);
	print_str(SEP_COLOR);
	print_sep_line('-', len);
	print_str(RED_WRITE);
	print_str(text);
	print_str(WARNING_TEXT);
	print_str(SEP_COLOR);
	print_sep_line('-', len);
}

void	print_win_text(int steps)
{
	int		len;
	char	*steps_text;

	len = 30;
	steps_text = ft_itoa(steps);
	print_str(SEP_COLOR);
	print_sep_line('-', len);
	print_str(GREEN_WRITE);
	print_str("           YOU WON\n          STEPS : ");
	print_str(steps_text);
	print_str(SEP_COLOR);
	print_sep_line('-', len);
	free(steps_text);
}

void	print_lose_text(void)
{
	int	len;

	len = 30;
	print_str(SEP_COLOR);
	print_sep_line('-', len);
	print_str(RED_WRITE);
	print_str("           YOU LOST\n    BEST OF LUCK NEXT TIME");
	print_str(SEP_COLOR);
	print_sep_line('-', len);
}
