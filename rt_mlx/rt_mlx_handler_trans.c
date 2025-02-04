/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_handler_trans.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:29:08 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/04 18:55:48 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_figure.h"

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
	t_vec	*vec;
	t_vec	tmp;
	int		flg;

	vec = (t_vec *)arg;
	tmp = *vec;
	flg = RT_POS;
	if (x < 0 || y < 0 || z < 0)
		flg = RT_NEG;
	if (x)
	{
		vec->y = tmp.y * sin_cos(RT_COS, flg) - tmp.z * sin_cos(RT_SIN, flg);
		vec->z = tmp.y * sin_cos(RT_SIN, flg) + tmp.z * sin_cos(RT_COS, flg);
	}
	else if (y)
	{
		vec->x = tmp.x * sin_cos(RT_COS, flg) - tmp.z * sin_cos(RT_SIN, flg);
		vec->z = tmp.x * sin_cos(RT_SIN, flg) + tmp.z * sin_cos(RT_COS, flg);
	}
	else
	{
		vec->x = tmp.x * sin_cos(RT_COS, flg) - tmp.y * sin_cos(RT_SIN, flg);
		vec->y = tmp.x * sin_cos(RT_SIN, flg) + tmp.y * sin_cos(RT_COS, flg);
	}
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
