#include "../cub3d.h"

 void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

 void	replace_all(char *linemap, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		linemap[i] = line[i];
}

 char	*make_line_insize(char *line, int size)
{
	char	*lineinsize;

	lineinsize = malloc(sizeof(char) * (size + 1));
	//ft_lstadd_back(&g_cub.grbg_colct, ft_grbg_new(lineinsize));
	if (lineinsize)
	{
		(void)line;
		ft_memset(lineinsize, '2', size);
		replace_all(lineinsize, line);
		return (lineinsize);
	}
	return (NULL);
}

char	**maping_themap( t_cub3d *cub)
{
	char	**mymap;
	int		i;
	
	i = -1;
	mymap = malloc(sizeof(char *) * (cub->len_l + 1));
	if (!mymap)
		exit_msg("Allocation of mymap(Failed)...\n");
	//ft_lstadd_back(&g_cub.grbg_colct, ft_grbg_new(mymap));
	while (++i < cub->len_l)
	{
		mymap[i] = make_line_insize(cub->map[i], cub->long_l);
		if (!mymap[i])
			break ;
	}
	mymap[i] = NULL;
	return (mymap);
}