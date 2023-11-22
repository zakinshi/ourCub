/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakbouha <zakbouha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:47:51 by enaam             #+#    #+#             */
/*   Updated: 2023/11/22 22:12:09 by zakbouha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sig;
	size_t	res;

	i = 0;
	sig = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sig *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i])
		exit_msg("error in number\n");
	return (res * sig);
}

int	count_word(char const *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			cont++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cont);
}

static char	*cut_word(char const *s, char c, int *idx)
{
	int		w;
	int		i;
	int		j;
	char	*word;

	i = *idx;
	while (s[i] == c)
		i++;
	j = i;
	while (s[i] && s[i] != c)
		i++;
	word = malloc((i - j + 1) * sizeof(char));
	if (!word)
		return (NULL);
	w = 0;
	while (i > j)
		word[w++] = s[j++];
	word[w] = '\0';
	*idx = i;
	return (word);
}

static void	ft_free(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(&s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		w;
	char	**sp;
	char	*word;
	int		len;

	len = count_word(s, c);
	i = 0;
	sp = malloc((len + 1) * sizeof(char *));
	if (!sp)
		return (NULL);
	w = 0;
	while (w < len)
	{
		word = cut_word(s, c, &i);
		if (!word)
			ft_free(word);
		sp[w++] = word;
	}
	sp[w] = NULL;
	return (sp);
}
