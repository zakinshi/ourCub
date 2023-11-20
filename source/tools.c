#include "cub3d.h"

int	lenlines(char **rows)
{
	int i = -1;
	while (rows[++i])
		;
	return i;
} 

void	exit_msg(char *msg)
{
	int	len;

	len = strlen(msg);	// ft_strlen();
	write(2, msg, len);
	exit(1);
}

void	free_2d_char(char **s)
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

void	free_rays(t_rays **s)
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
