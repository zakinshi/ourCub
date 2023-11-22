/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:20:39 by enaam             #+#    #+#             */
/*   Updated: 2023/11/22 22:25:12 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*ft_read(int fd, char *save)
{
	char	*buff;
	ssize_t	r_read;

	if (!save)
		save = ft_dup("");
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(buff), free(save), NULL);
	r_read = 1;
	while (!ft_chr(save, '\n') && r_read != 0)
	{
		r_read = read(fd, buff, BUFFER_SIZE);
		if (r_read < 0)
			return (free(buff), free(save), NULL);
		buff[r_read] = '\0';
		save = ft_join(save, buff);
	}
	return (free(buff), save);
}

static char	*ft_line(char *save)
{
	char	*line;
	size_t	i;
	size_t	count;

	count = 0;
	if (save[count] == '\0')
		return (NULL);
	while (save[count] && save[count] != '\n')
		count++;
	if (save[count] == '\n')
		count++;
	line = malloc((count + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i])
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_rest(char *s)
{
	size_t	i;
	size_t	len;
	char	*rest;
	char	*str;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			str = &s[i + 1];
			len = ft_strlen(str);
			rest = malloc((len + 1) * sizeof(char));
			if (!rest)
				return (NULL);
			rest = ft_cpy(rest, str);
			rest[len] = '\0';
			return (free(s), rest);
		}
		i++;
	}
	return (free(s), NULL);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*gtnl;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_read(fd, line);
	if (!line)
		return (NULL);
	gtnl = ft_line(line);
	line = ft_rest(line);
	return (gtnl);
}
