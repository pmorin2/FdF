/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dy_nonull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:07:24 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/12 15:34:03 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

static void	cas1(t_mlx *mlx)
{
	int e;

	e = mlx->dx;
	mlx->dx *= 2;
	mlx->dy *= 2;
	while (++mlx->j1 != mlx->j2)
	{
		mlx_pixel_put(mlx->init, mlx->win, mlx->j1, mlx->i1, mlx->color);
		if ((e -= mlx->dy) < 0)
		{
			mlx->i1++;
			e += mlx->dx;
		}
	}
}

static void	cas2(t_mlx *mlx)
{
	int e;

	e = mlx->dy;
	mlx->dx *= 2;
	mlx->dy *= 2;
	while (++mlx->i1 != mlx->i2)
	{
		mlx_pixel_put(mlx->init, mlx->win, mlx->j1, mlx->i1, mlx->color);
		if ((e -= mlx->dx) < 0)
		{
			mlx->j1++;
			e += mlx->dy;
		}
	}
}

static void	cas3(t_mlx *mlx)
{
	int e;

	e = mlx->dx;
	mlx->dx *= 2;
	mlx->dy *= 2;
	while (++mlx->j1 != mlx->j2)
	{
		mlx_pixel_put(mlx->init, mlx->win, mlx->j1, mlx->i1, mlx->color);
		if ((e += mlx->dy) < 0)
		{
			mlx->i1--;
			e += mlx->dx;
		}
	}
}

static void	cas4(t_mlx *mlx)
{
	int e;

	e = mlx->dy;
	mlx->dx *= 2;
	mlx->dy *= 2;
	while (--mlx->i1 != mlx->i2)
	{
		mlx_pixel_put(mlx->init, mlx->win, mlx->j1, mlx->i1, mlx->color);
		if ((e += mlx->dx) > 0)
		{
			mlx->j1++;
			e += mlx->dy;
		}
	}
}

void		dy_nonull(t_mlx *mlx)
{
	if (mlx->dy > 0)
	{
		if (mlx->dx >= mlx->dy)
			cas1(mlx);
		else
			cas2(mlx);
	}
	else
	{
		if (mlx->dx >= -mlx->dy)
			cas3(mlx);
		else
			cas4(mlx);
	}
}
