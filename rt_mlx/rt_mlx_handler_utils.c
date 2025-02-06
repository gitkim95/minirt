/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_handler_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:58:40 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/06 04:34:26 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
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
			return (&mlx->scene.cam.rotate);
		else if (mlx->trans_arg.type == RT_F)
			return (&((t_figure *)mlx->trans_arg.arg)->rotate);
	}
	else
		if (mlx->trans_arg.type == RT_F)
			return (mlx->trans_arg.arg);
	return (NULL);
}
