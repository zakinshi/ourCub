/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:43:53 by enaam             #+#    #+#             */
/*   Updated: 2023/11/21 17:52:11 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	ft_len(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_dup(char *s)
{
	char		*dup;
	size_t		len;
	size_t		i;

	len = ft_len(s);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (len > i)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_cpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_join(char *s1, char *s2)
{
	size_t	i;
	size_t	len;
	size_t	len1;
	size_t	len2;
	char	*join;

	i = 0;
	len1 = ft_len(s1);
	len2 = ft_len(s2);
	len = (len1 + len2) + 1;
	join = malloc(len * sizeof(char));
	if (!join)
		return (NULL);
	join = ft_cpy(join, s1);
	while (s2[i])
	{
		join[len1 + i] = s2[i];
		i++;
	}
	join[len1 + i] = '\0';
	return (free(s1), join);
}

char	*ft_chr(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
