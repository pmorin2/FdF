/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:11:54 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/12 18:02:06 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "fdf.h"
#include <fcntl.h>

static int	**def_map(t_mlx *mlx)
{
	int	**tab;
	int i;

	if (!(tab = malloc(sizeof(*tab) * mlx->line + 1)))
		return (NULL);
	i = -1;
	while (++i < mlx->line)
		if (!(tab[i] = malloc(sizeof(**tab) * mlx->col + 1)))
			return (NULL);
	tab[i] = 0;
	return (tab);
}

static int	close_open(int fd, char *name)
{
	if (fd != -1)
		close(fd);
	return (open(name, O_RDONLY));
}

static int	nb_line_col(t_mlx *mlx)
{
	int		i_j_k[3];
	char	*line;

	i_j_k[0] = 0;
	while (get_next_line(mlx->fd, &line) > 0)
	{
		i_j_k[1] = 0;
		i_j_k[2] = 0;
		i_j_k[0]++;
		while (line[i_j_k[2]])
		{
			while (line[i_j_k[2]] == ' ')
				i_j_k[2]++;
			if (line[i_j_k[2]])
				i_j_k[1]++;
			while (line[i_j_k[2]] != ' ' && line[i_j_k[2]])
				i_j_k[2]++;
		}
		if (mlx->col == -1)
			mlx->col = i_j_k[1];
		ft_strdel(&line);
		if (mlx->col != i_j_k[1])
			return (-2);
	}
	return (i_j_k[0]);
}

static int	remp_tab(t_mlx *mlx, char *line, int i)
{
	int k;
	int j;

	k = 0;
	j = 0;
	while (line[k])
	{
		while (line[k] == ' ')
			k++;
		if (line[k])
		{
			mlx->map[i][j] = ft_atoi(&line[k]);
			j++;
		}
		while (line[k] != ' ' && line[k])
			k++;
	}
	return (0);
}

int			parsor(t_mlx *mlx)
{
	char	*line;
	int		i;

	mlx->fd = close_open(mlx->fd, mlx->name);
	if ((mlx->line = nb_line_col(mlx)) == -2)
	{
		ft_putstr("error map");
		exit(0);
	}
	mlx->fd = close_open(mlx->fd, mlx->name);
	mlx->map = def_map(mlx);
	i = -1;
	while (get_next_line(mlx->fd, &line) > 0)
	{
		i++;
		remp_tab(mlx, line, i);
		ft_strdel(&line);
	}
	close(mlx->fd);
	return (0);
}
