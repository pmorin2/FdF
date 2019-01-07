/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dy_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:28:29 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/12 15:48:32 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	dy_null1(t_mlx *mlx)
{
	while (++mlx->j1 != mlx->j2)
		mlx_pixel_put(mlx->init, mlx->win, mlx->j1, mlx->i1, mlx->color);
}

void	dy_null2(t_mlx *mlx)
{
	while (--mlx->j1 != mlx->j2)
		mlx_pixel_put(mlx->init, mlx->win, mlx->j1, mlx->i1, mlx->color);
}

void	dx_null(t_mlx *mlx)
{
	if ((mlx->dy = mlx->i2 - mlx->i1) != 0)
	{
		if (mlx->dy > 0)
			while (++mlx->i1 != mlx->i2)
				mlx_pixel_put(mlx->init, mlx->win, mlx->j1, mlx->i1
							, mlx->color);
		else
			while (--mlx->i1 != mlx->i2)
				mlx_pixel_put(mlx->init, mlx->win, mlx->j1, mlx->i1
							, mlx->color);
	}
}
