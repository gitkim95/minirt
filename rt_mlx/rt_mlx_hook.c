/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:08:21 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/03 18:33:36 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include "mlx.h"

#include "rt_mlx.h"

static char	*get_data_addr(t_mlx *mlx);

int	rt_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		mlx_loop_end(mlx->mlx);
	return (0);
}

int	rt_loop_hook(t_mlx *mlx)
{
	if (mlx->img_data.img)
		mlx_destroy_image(mlx->mlx, mlx->img_data.img);
	mlx->img_data.img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->img_data.addr = get_data_addr(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_data.img, 0, 0);
	return (0);
}

static char	*get_data_addr(t_mlx *mlx)
{
	void	*img_ptr;
	int		*bits_per_pixel;
	int		*size_line;
	int		*endian;

	img_ptr = mlx->img_data.img;
	bits_per_pixel = &mlx->img_data.bits_per_pixel;
	size_line = &mlx->img_data.line_length;
	endian = &mlx->img_data.endian;
	return (mlx_get_data_addr(img_ptr, bits_per_pixel, size_line, endian));
}
