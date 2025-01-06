/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:43:11 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/06 19:19:17 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <stdlib.h>
#include <errno.h>
#include "mlx.h"
#include "mlx_int.h"
#include "rt_error.h"
#include "rt_scene.h"
#include "rt_utils.h"
#include "libft.h"

#include "rt_mlx.h"

void	init_mlx_data(t_mlx *mlx)
{
	ft_bzero(mlx, sizeof(t_mlx));
	mlx->mlx = mlx_init();
	if (!(mlx->mlx))
		exit_on_error(ENOMEM);
	mlx->width = RT_WIDTH;
	mlx->height = RT_HEIGHT;
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "miniRT");
	mlx->scene = make_scene(mlx, "file");
	mlx_hook(mlx->win, DestroyNotify, 0, mlx_loop_end, mlx->mlx);
	mlx_hook(mlx->win, KeyPress, KeyPressMask, rt_key_hook, mlx);
	mlx_loop_hook(mlx->mlx, rt_loop_hook, mlx);
}

void	destroy_mlx_data(t_mlx *mlx)
{
	if (mlx->img_data.img)
		mlx_destroy_image(mlx->mlx, mlx->img_data.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	rt_free_figure(&mlx->scene.figures);
}

void	draw_pixel_to_img(t_data *data, int x, int y, unsigned int color)
{
	t_img	*img;
	char	*dst;

	img = data->img;
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*((unsigned int *)dst) = color;
}
