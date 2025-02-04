/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_handler_trans.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:29:08 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/05 03:30:59 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_figure.h"
#include "rt_vector.h"

#include "rt_mlx.h"

static void		translate(void *arg, int x, int y, int z);
static void		rotate(void *arg, int x, int y, int z);
static void		resize(void *arg, int x, int y, int z);
static t_vec	rotate_vec(t_vec v, t_vec axis, int flg);

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
	t_rotate	*vec;
	t_axis		tmp;
	int			flg;

	vec = (t_rotate *)arg;
	flg = RT_POS;
	if (x < 0 || y < 0 || z < 0)
		flg = RT_NEG;
	if (x)
	{
		tmp.x = vec->axis.x;
		tmp.y = rotate_vec(vec->axis.y, vec->axis.x, flg);
		tmp.z = rotate_vec(vec->axis.z, vec->axis.x, flg);
		*vec->vector = rotate_vec(*vec->vector, vec->axis.x, flg);
	}
	else if (y)
	{
		tmp.x = rotate_vec(vec->axis.x, vec->axis.y, flg);
		tmp.y = vec->axis.y;
		tmp.z = rotate_vec(vec->axis.z, vec->axis.y, flg);
		*vec->vector = rotate_vec(*vec->vector, vec->axis.y, flg);
	}
	else
	{
		tmp.x = rotate_vec(vec->axis.x, vec->axis.z, flg);
		tmp.y = rotate_vec(vec->axis.y, vec->axis.z, flg);
		tmp.z = vec->axis.z;
		*vec->vector = rotate_vec(*vec->vector, vec->axis.z, flg);
	}
	vec->axis = tmp;
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

static t_vec	rotate_vec(t_vec v, t_vec axis, int flg)
{
	double	cos;
	double	sin;
	double	dot;
	t_vec	cross;
	t_vec	rotated_v;

	cos = sin_cos(RT_COS, flg);
	sin = sin_cos(RT_SIN, flg);
	cross = v_cross(axis, v);
	dot = v_dot(axis, v);
	rotated_v.x = v.x * cos + cross.x * sin + axis.x * dot * (1 - cos);
	rotated_v.y = v.y * cos + cross.y * sin + axis.y * dot * (1 - cos);
	rotated_v.z = v.z * cos + cross.z * sin + axis.z * dot * (1 - cos);
	return (rotated_v);
}
