/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:43:11 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/03 17:52:29 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <stdlib.h>
#include <errno.h>
#include "mlx.h"
#include "rt_error.h"

#include "rt_mlx.h"

void	init_mlx_data(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!(mlx->mlx))
		exit_on_error(ENOMEM);
	mlx->win = mlx_new_window(mlx->mlx, 800, 600, "miniRT");
	mlx->img_data.img = NULL;
	mlx_hook(mlx->win, DestroyNotify, 0, mlx_loop_end, mlx->mlx);
	mlx_hook(mlx->win, KeyPress, KeyPressMask, rt_mlx_key_hook, mlx);
}

void	destroy_mlx_data(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}
