/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:20:44 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/02 20:23:16 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <stddef.h>
#include <errno.h>
#include "mlx.h"
#include "rt_error.h"
#include "rt_mlx_hook.h"

#include "minirt.h"

static void	init_mlx_data(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!(mlx->mlx))
		exit_on_error(ENOMEM);
	mlx->win = mlx_new_window(mlx->mlx, 800, 600, "miniRT");
	mlx->img_data.img = NULL;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argc;
	(void)argv;
	init_mlx_data(&mlx);
	mlx_hook(mlx.win, DestroyNotify, 0, mlx_close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
