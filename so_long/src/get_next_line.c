/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:00:30 by vrsargsy          #+#    #+#             */
/*   Updated: 2022/07/23 21:00:31 by vrsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return (str + i);
	return (NULL);
}

static char	*get_line(char **buffer, char **line)
{
	char	*next_buffer;
	int		i;

	i = 0;
	next_buffer = NULL;
	while (*(*buffer + i) != '\n' && *(*buffer + i) != '\0')
		i++;
	if (*(*buffer + i) == '\n')
	{
		i++;
		*line = ft_substr(*buffer, 0, i - 1);
		next_buffer = ft_strdup(*buffer + i);
	}
	else
		*line = ft_strdup(*buffer);
	free_ptr(buffer);
	return (next_buffer);
}

static int	read_line(int fd, char **reading_buffer, char **backup, char **line)
{
	char	*temporary;
	int		bytes_read;
	int		end_found;

	bytes_read = 1;
	end_found = 0;
	if (!ft_strchr(*backup, '\n'))
	{
		while (!end_found && bytes_read)
		{
			bytes_read = read(fd, *reading_buffer, BUFFER_SIZE);
			(*reading_buffer)[bytes_read] = '\0';
			temporary = *backup;
			*backup = ft_strjoin(temporary, *reading_buffer);
			free(temporary);
			if (ft_strchr(*reading_buffer, '\n'))
				end_found = 1;
		}
	}
	free_ptr(reading_buffer);
	*backup = get_line(backup, line);
	if ((**line))
		return (ft_strlen(*line));
	free_ptr(line);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*reading_buffer;
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	reading_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!reading_buffer)
		return (NULL);
	if (read(fd, reading_buffer, 0) < 0)
	{
		free(reading_buffer);
		return (NULL);
	}
	if (!buffer)
		buffer = ft_strdup("");
	if (!read_line(fd, &reading_buffer, &buffer, &line) && !line)
		return (NULL);
	return (line);
}
