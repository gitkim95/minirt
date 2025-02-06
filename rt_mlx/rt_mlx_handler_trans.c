/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_handler_trans.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:29:08 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/06 04:32:17 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_figure.h"
#include "rt_vector.h"

#include "rt_mlx.h"

static void		translate(void *arg, int x, int y, int z);
static void		rotate(void *arg, int x, int y, int z);
static void		resize(void *arg, int x, int y, int z);

t_trans	get_transform_handler(t_mlx *mlx)
{
	if (mlx->trans_mode == RT_TRANSLATE)
		return (translate);
	else if (mlx->trans_mode == RT_ROTATE)
		return (rotate);
	else
		return (resize);
}

static void	translate(void *arg, int x, int y, int z)
{
	t_coord	*coord;

	coord = (t_coord *)arg;
	coord->x += x;
	coord->y += y;
	coord->z += z;
}

static void	rotate(void *arg, int x, int y, int z)
{
	t_rotate	*rotate;
	t_axis		axis;
	int			positive_flag;

	rotate = (t_rotate *)arg;
	positive_flag = RT_POS;
	if (x < 0 || y < 0 || z < 0)
		positive_flag = RT_NEG;
	if (x)
	{
		axis = rotate_axis_x(rotate, positive_flag);
		rotate->vector = rotate_vec(rotate->vector, axis.x, positive_flag);
	}
	else if (y)
	{
		axis = rotate_axis_y(rotate, positive_flag);
		rotate->vector = rotate_vec(rotate->vector, axis.y, positive_flag);
	}
	else
	{
		axis = rotate_axis_z(rotate, positive_flag);
		rotate->vector = rotate_vec(rotate->vector, axis.z, positive_flag);
	}
	rotate->axis = axis;
}

static void	resize(void *arg, int x, int y, int z)
{
	t_figure	*figure;

	(void)z;
	figure = (t_figure *)arg;
	if (figure->identifier == RT_CY)
		resize_cylinder(figure, x, y);
	else if (figure->identifier == RT_SP)
		resize_sphere(figure, x);
}
