/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:23:14 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/12 15:30:08 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_line_i2(int im, int jm, t_mlx *mlx)
{
	mlx->j2 = jm * mlx->coef / 2 - (im + 1) * mlx->coef / 2 + mlx->w_win
		/ 4 + mlx->x;
	mlx->i2 = (im + 1) * mlx->coef / 2 + jm * mlx->coef / 2
		- (mlx->map[im + 1][jm] * mlx->c_z) + mlx->y + 20;
	if ((mlx->dx = mlx->j2 - mlx->j1) != 0)
	{
		if (mlx->dx > 0)
		{
			if ((mlx->dy = mlx->i2 - mlx->i1) != 0)
				dy_nonull(mlx);
			else
				dy_null1(mlx);
		}
		else
		{
			if ((mlx->dy = mlx->i2 - mlx->i1) != 0)
				dy_nonull2(mlx);
			else
				dy_null2(mlx);
		}
	}
	else
		dx_null(mlx);
}

void	put_line_j2(int im, int jm, t_mlx *mlx)
{
	mlx->j2 = (jm + 1) * mlx->coef / 2 - im * mlx->coef / 2 + mlx->w_win
		/ 4 + mlx->x;
	mlx->i2 = im * mlx->coef / 2 + (jm + 1) * mlx->coef / 2
		- (mlx->map[im][jm + 1] * mlx->c_z) + mlx->y + 20;
	if ((mlx->dx = mlx->j2 - mlx->j1) != 0)
	{
		if (mlx->dx > 0)
		{
			if ((mlx->dy = mlx->i2 - mlx->i1) != 0)
				dy_nonull(mlx);
			else
				dy_null1(mlx);
		}
		else
		{
			if ((mlx->dy = mlx->i2 - mlx->i1) != 0)
				dy_nonull2(mlx);
			else
				dy_null2(mlx);
		}
	}
	else
		dx_null(mlx);
}

void	put_line_i1(int im, int jm, t_mlx *mlx)
{
	mlx->j2 = jm * mlx->coef / 2 + mlx->map[im + 1][jm] * mlx->c_z / 3
		+ mlx->w_win / 4 + mlx->x;
	mlx->i2 = (im + 1) * mlx->coef / 2 + mlx->map[im + 1][jm] * mlx->c_z / 3
		+ mlx->y + 20;
	if ((mlx->dx = mlx->j2 - mlx->j1) != 0)
	{
		if (mlx->dx > 0)
		{
			if ((mlx->dy = mlx->i2 - mlx->i1) != 0)
				dy_nonull(mlx);
			else
				dy_null1(mlx);
		}
		else
		{
			if ((mlx->dy = mlx->i2 - mlx->i1) != 0)
				dy_nonull2(mlx);
			else
				dy_null2(mlx);
		}
	}
	else
		dx_null(mlx);
}

void	put_line_j1(int im, int jm, t_mlx *mlx)
{
	mlx->j2 = (jm + 1) * mlx->coef / 2 + mlx->map[im][jm + 1] * mlx->c_z / 3
		+ mlx->w_win / 4 + mlx->x;
	mlx->i2 = im * mlx->coef / 2 + mlx->map[im][jm + 1] * mlx->c_z / 3
		+ mlx->y + 20;
	if ((mlx->dx = mlx->j2 - mlx->j1) != 0)
	{
		if (mlx->dx > 0)
		{
			if ((mlx->dy = mlx->i2 - mlx->i1) != 0)
				dy_nonull(mlx);
			else
				dy_null1(mlx);
		}
		else
		{
			if ((mlx->dy = mlx->i2 - mlx->i1) != 0)
				dy_nonull2(mlx);
			else
				dy_null2(mlx);
		}
	}
	else
		dx_null(mlx);
}
