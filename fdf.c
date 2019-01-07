/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:58:12 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/12 17:56:07 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

static int	relief(int key, t_mlx *mlx)
{
	if (key == 69 && mlx->c_z < 100)
		mlx->c_z += 1;
	else if (key == 78 && mlx->c_z > -100)
		mlx->c_z -= 1;
	else if (key == 116 && mlx->coef < 95)
		mlx->coef += 5;
	else if (key == 121 && mlx->coef > 5)
		mlx->coef -= 5;
	else if (key == 123)
		mlx->x -= 50;
	else if (key == 124)
		mlx->x += 50;
	else if (key == 125)
		mlx->y += 50;
	else if (key == 126)
		mlx->y -= 50;
	else if (key == 71)
	{
		mlx->y = 0;
		mlx->x = 0;
		mlx->c_z = 0;
	}
	mlx_clear_window(mlx->init, mlx->win);
	perspec_aff(mlx);
	return (0);
}

static int	color_change(int key, t_mlx *mlx)
{
	if (key == 31)
		mlx->color = 16735744;
	else if (key == 35)
		mlx->color = 13369599;
	else if (key == 16)
		mlx->color = 15662848;
	else if (key == 15)
		mlx->color = 16711680;
	else if (key == 11)
		mlx->color = 255;
	else if (key == 5)
		mlx->color = 65280;
	else if (key == 33)
		mlx->color = 16730798;
	else if (key == 13)
		mlx->color = 16777215;
	else if (key == 45)
		mlx->color = 5379592;
	else if (key == 4)
		mlx->color = 9868950;
	mlx_clear_window(mlx->init, mlx->win);
	perspec_aff(mlx);
	return (0);
}

static int	key_press(int key, t_mlx *mlx_ptr)
{
	if (key == 53)
	{
		free_map(&(mlx_ptr->map));
		mlx_destroy_window(mlx_ptr->init, mlx_ptr->win);
		exit(0);
	}
	if (key == 69 || key == 78 || key == 116 || key == 121 || key == 71
		|| (key < 127 && key > 122))
		relief(key, mlx_ptr);
	if (key == 31 || key == 35 || key == 16 || key == 15 || key == 11
		|| key == 5 || key == 33 || key == 13 || key == 45 || key == 4)
		color_change(key, mlx_ptr);
	if (key == 48)
	{
		if (mlx_ptr->perspec == 0)
			mlx_ptr->perspec = 1;
		else
			mlx_ptr->perspec = 0;
		relief(71, mlx_ptr);
	}
	return (0);
}

static int	mouse_press(int button, int x, int y, t_mlx *mlx_ptr)
{
	if (button == 3)
		mlx_string_put(mlx_ptr->init, mlx_ptr->win, x, y
					, mlx_ptr->color, "That's a 125 !");
	return (0);
}

int			fdf(t_mlx *mlx)
{
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, mlx->w_win, mlx->h_win, "FdF");
	perspec_aff(mlx);
	mlx_key_hook(mlx->win, key_press, mlx);
	mlx_mouse_hook(mlx->win, mouse_press, mlx);
	mlx_loop(mlx->init);
	return (0);
}
