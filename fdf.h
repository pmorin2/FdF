/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:05:11 by pmorin            #+#    #+#             */
/*   Updated: 2018/12/12 18:22:07 by pmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct		s_mlx
{
	void			*init;
	void			*win;
	char			*name;
	int				fd;
	int				**map;
	int				h_win;
	int				w_win;
	int				line;
	int				col;
	int				coef;
	int				c_z;
	int				x;
	int				y;
	int				color;
	int				i1;
	int				j1;
	int				i2;
	int				j2;
	int				dx;
	int				dy;
	int				perspec;
}					t_mlx;

int					fdf(t_mlx *mlx);
int					parsor(t_mlx *mlx);
int					mlx_set(t_mlx *mlx, char *name);
void				perspec_aff(t_mlx *mlx);
void				dy_nonull(t_mlx *mlx);
void				dy_nonull2(t_mlx *mlx);
void				dy_null1(t_mlx *mlx);
void				dy_null2(t_mlx *mlx);
void				dx_null(t_mlx *mlx);
void				put_line_i2(int im, int jm, t_mlx *mlx);
void				put_line_j2(int im, int jm, t_mlx *mlx);
void				put_line_i1(int im, int jm, t_mlx *mlx);
void				put_line_j1(int im, int jm, t_mlx *mlx);
void				free_map(int ***map);
#endif
