/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:44:06 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/13 16:09:17 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include "libft.h"
#include "fdf.h"

static void	aff_2(t_mlx *mlx)
{
	int im;
	int jm;

	im = -1;
	while (++im < mlx->line)
	{
		jm = -1;
		while (++jm < mlx->col)
		{
			mlx->j1 = jm * mlx->coef / 2 - im * mlx->coef / 2 + mlx->w_win
				/ 4 + mlx->x;
			mlx->i1 = im * mlx->coef / 2 + jm * mlx->coef / 2
				- (mlx->map[im][jm] * mlx->c_z) + mlx->y + 20;
			if (im < mlx->line - 1 && mlx->i1 <= mlx->h_win && mlx->j1 <= mlx->w_win)
				put_line_i2(im, jm, mlx);
			mlx->j1 = jm * mlx->coef / 2 - im * mlx->coef / 2 + mlx->w_win
				/ 4 + mlx->x;
			mlx->i1 = im * mlx->coef / 2 + jm * mlx->coef / 2
				- (mlx->map[im][jm] * mlx->c_z) + mlx->y + 20;
			if (jm < mlx->col - 1 && mlx->i1 <= mlx->h_win && mlx->j1 <= mlx->w_win)
				put_line_j2(im, jm, mlx);
		}
	}
}

static void	aff_1(t_mlx *mlx)
{
	int im;
	int jm;

	im = -1;
	while (++im < mlx->line)
	{
		jm = -1;
		while (++jm < mlx->col)
		{
			mlx->j1 = jm * mlx->coef / 2 + mlx->map[im][jm] * mlx->c_z / 3
				+ mlx->w_win / 4 + mlx->x;
			mlx->i1 = im * mlx->coef / 2 + mlx->map[im][jm] * mlx->c_z / 3
				+ mlx->y + 20;
			if (im < mlx->line - 1)
				put_line_i1(im, jm, mlx);
			mlx->j1 = jm * mlx->coef / 2 + mlx->map[im][jm] * mlx->c_z / 3
				+ mlx->w_win / 4 + mlx->x;
			mlx->i1 = im * mlx->coef / 2 + mlx->map[im][jm] * mlx->c_z / 3
				+ mlx->y + 20;
			if (jm < mlx->col - 1)
				put_line_j1(im, jm, mlx);
		}
	}
}

void		perspec_aff(t_mlx *mlx)
{
	if (mlx->perspec == 0)
		aff_2(mlx);
	else
		aff_1(mlx);
	mlx_string_put(mlx->init, mlx->win, 20, 20, mlx->color, "Quit = esc");
	mlx_string_put(mlx->init, mlx->win, 20, 60, mlx->color, "Change aff = tab");
	mlx_string_put(mlx->init, mlx->win, 20, 140, mlx->color
				, "Change relief = + and -");
	mlx_string_put(mlx->init, mlx->win, 20, 220, mlx->color
				, "Change zoom = |page up| and |page down|");
	mlx_string_put(mlx->init, mlx->win, 20, 100, mlx->color
				, "Move camera = arrow");
	mlx_string_put(mlx->init, mlx->win, 20, 180, mlx->color
				, "Reset position and relief = |clear|");
	mlx_string_put(mlx->init, mlx->win, 20, 260, mlx->color, "color :");
	mlx_string_put(mlx->init, mlx->win, 20, 280, mlx->color, "o = orange");
	mlx_string_put(mlx->init, mlx->win, 20, 300, mlx->color, "p = purple");
	mlx_string_put(mlx->init, mlx->win, 20, 320, mlx->color, "y = yellow");
	mlx_string_put(mlx->init, mlx->win, 20, 340, mlx->color, "r = red");
	mlx_string_put(mlx->init, mlx->win, 20, 360, mlx->color, "b = blue");
	mlx_string_put(mlx->init, mlx->win, 20, 380, mlx->color, "g = green");
	mlx_string_put(mlx->init, mlx->win, 20, 400, mlx->color, "[ = pink");
	mlx_string_put(mlx->init, mlx->win, 20, 420, mlx->color, "w = white");
	mlx_string_put(mlx->init, mlx->win, 20, 440, mlx->color, "n = brown");
	mlx_string_put(mlx->init, mlx->win, 20, 460, mlx->color, "h = grey");
}
