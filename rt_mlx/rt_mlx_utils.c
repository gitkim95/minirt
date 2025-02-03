/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:43:11 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/03 21:04:12 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <stdlib.h>
#include "mlx.h"
#include "mlx_int.h"
#include "rt_error.h"
#include "rt_parse.h"
#include "rt_scene.h"
#include "rt_utils.h"
#include "libft.h"

#include "rt_mlx.h"

static char	*stat_str(t_mlx *mlx, char *buf, int flg);

void	init_mlx_data(t_mlx *mlx, char *file_path)
{
	ft_bzero(mlx, sizeof(t_mlx));
	parse_data(mlx, file_path);
	mlx->mlx = mlx_init();
	if (!(mlx->mlx))
		exit_on_error(&mlx->scene.figures, RT_ERR_MEM);
	mlx->win = mlx_new_window(mlx->mlx, RT_WIDTH, RT_HEIGHT, "miniRT");
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

void	print_status(t_mlx *mlx)
{
	char	buf[256];

	mlx_string_put(mlx->mlx, mlx->win, 2, 10, RT_WHITE, "mode");
	mlx_string_put(mlx->mlx, mlx->win, 2, 21, RT_WHITE, "select");
	mlx_string_put(mlx->mlx, mlx->win, 2, 32, RT_WHITE, "  X   -Q +W");
	mlx_string_put(mlx->mlx, mlx->win, 2, 43, RT_WHITE, "  Y   -A +S");
	mlx_string_put(mlx->mlx, mlx->win, 2, 54, RT_WHITE, "  Z   -Z +X");
	mlx_string_put(mlx->mlx, mlx->win, 2, 65, RT_WHITE, "change mode    M");
	mlx_string_put(mlx->mlx, mlx->win, 2, 76, RT_WHITE, "select light   L");
	mlx_string_put(mlx->mlx, mlx->win, 2, 87, RT_WHITE, "select camera  C");
	mlx_string_put(mlx->mlx, mlx->win, 2, 98, RT_WHITE, "select figure  F");
	mlx_string_put(mlx->mlx, mlx->win, 50, 10, RT_WHITE, stat_str(mlx, buf, 1));
	mlx_string_put(mlx->mlx, mlx->win, 50, 21, RT_WHITE, stat_str(mlx, buf, 0));
}

static char	*stat_str(t_mlx *mlx, char *buf, int flg)
{
	buf[0] = '\0';
	if (flg)
		return (RT_MLX_MODE + mlx->trans_mode);
	if (!mlx->trans_arg.type)
		return (buf);
	if (mlx->trans_arg.type != RT_F)
		return (RT_SCENE + mlx->trans_arg.type);
	rt_strcat(buf, "F  ");
	rt_strcat(buf, RT_FIGURE + ((t_figure *)mlx->trans_arg.arg)->identifier);
	return (buf);
}
