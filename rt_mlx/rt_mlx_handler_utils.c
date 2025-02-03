/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_handler_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:58:40 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/02 22:30:40 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include "rt_component.h"

#include "rt_mlx.h"

void	*get_handler_arg(t_mlx *mlx)
{
	if (!mlx->trans_arg.arg)
		return (NULL);
	if (mlx->trans_mode == RT_TRANSLATE)
	{
		if (mlx->trans_arg.type == RT_C)
			return (&mlx->scene.cam.center);
		else if (mlx->trans_arg.type == RT_L)
			return (&mlx->scene.light.center);
		else if (mlx->trans_arg.type == RT_F)
			return (&((t_figure *)mlx->trans_arg.arg)->center);
	}
	else if (mlx->trans_mode == RT_ROTATE)
	{
		if (mlx->trans_arg.type == RT_C)
			return (&mlx->scene.cam.cam_dir);
		else if (mlx->trans_arg.type == RT_F)
			return (&((t_figure *)mlx->trans_arg.arg)->vector);
	}
	else
		if (mlx->trans_arg.type == RT_F)
			return (mlx->trans_arg.arg);
	return (NULL);
}

double	sin_cos(int sin_cos_flag, int positive_flag)
{
	static bool		init;
	static double	tri[4];
	int				idx;

	if (!init)
	{
		init = true;
		tri[0] = sin(-RT_RADIAN);
		tri[1] = sin(RT_RADIAN);
		tri[2] = cos(-RT_RADIAN);
		tri[3] = cos(RT_RADIAN);
	}
	idx = (sin_cos_flag * 2 + positive_flag);
	return (tri[idx]);
}
