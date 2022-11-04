/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:00:39 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 21:00:40 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	len;
	size_t	i;

	i = -1;
	len = ft_strlen(s1);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (s1[++i])
		result[i] = s1[i];
	result[i] = 0;
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	i;

	if (destsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (destsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	size_t			total_len;

	i = 0;
	if (start > ft_strlen(s))
		total_len = 0;
	else if (ft_strlen(s) - start > len)
		total_len = len;
	else
		total_len = ft_strlen(s) - start;
	str = (char *)malloc(total_len + 1);
	if (!str)
		return (NULL);
	if (str)
		ft_strlcpy(str, s + start, total_len + 1);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	size_t	i;
	char	*res;

	size1 = -1;
	size2 = -1;
	i = -1;
	while (s1[++size1])
		;
	while (s2[++size2])
		;
	res = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!res)
		return (NULL);
	while (++i < size1)
		res[i] = s1[i];
	while (i - size1 < size2)
	{
		res[i] = s2[i - size1];
		i++;
	}
	res[i] = 0;
	return (res);
}
