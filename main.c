/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:21:16 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/12 16:31:05 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
	{
		ft_putstr("Usage : ./fdf map");
		return (0);
	}
	mlx_set(&mlx, av[1]);
	parsor(&mlx);
	fdf(&mlx);
	return (0);
}
