/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:11:39 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/11 23:38:53 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mlx_set(t_mlx *mlx, char *name)
{
	mlx->fd = -1;
	mlx->h_win = 1440;
	mlx->w_win = 2560;
	mlx->line = -1;
	mlx->col = -1;
	mlx->name = name;
	mlx->coef = 50;
	mlx->c_z = 0;
	mlx->x = 0;
	mlx->y = 0;
	mlx->color = 13369599;
	mlx->i1 = 0;
	mlx->j1 = 0;
	mlx->i2 = 0;
	mlx->j2 = 0;
	mlx->dx = 0;
	mlx->dy = 0;
	mlx->perspec = 0;
	return (0);
}
