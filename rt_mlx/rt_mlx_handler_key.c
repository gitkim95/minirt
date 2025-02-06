/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_handler_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:29:08 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/06 03:51:26 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <X11/keysym.h>
#include "rt_component.h"

#include "rt_mlx.h"

static int	change_mode(int keycode, t_mlx *mlx);
static int	select_element(int keycode, t_mlx *mlx);
static int	transform_element(int keycode, t_mlx *mlx);
static void	post_transform(t_mlx *mlx);

t_handler	get_handler(int keycode)
{
	static t_handler	handler[127];

	if (keycode < 32 || keycode > 126)
		return (NULL);
	if (!handler[0])
	{
		handler[0] = change_mode;
		handler[XK_m] = change_mode;
		handler[XK_l] = select_element;
		handler[XK_c] = select_element;
		handler[XK_f] = select_element;
		handler[XK_q] = transform_element;
		handler[XK_w] = transform_element;
		handler[XK_a] = transform_element;
		handler[XK_s] = transform_element;
		handler[XK_z] = transform_element;
		handler[XK_x] = transform_element;
	}
	return (handler[keycode]);
}

static int	change_mode(int keycode, t_mlx *mlx)
{
	(void) keycode;
	if (mlx->trans_mode == RT_TRANSLATE)
		mlx->trans_mode = RT_ROTATE;
	else if (mlx->trans_mode == RT_ROTATE)
		mlx->trans_mode = RT_RESIZE;
	else
		mlx->trans_mode = RT_TRANSLATE;
	return (0);
}

static int	select_element(int keycode, t_mlx *mlx)
{
	if (keycode == XK_l)
	{
		mlx->trans_arg.type = RT_L;
		mlx->trans_arg.arg = &mlx->scene.light;
	}
	else if (keycode == XK_c)
	{
		mlx->trans_arg.type = RT_C;
		mlx->trans_arg.arg = &mlx->scene.cam;
	}
	else if (keycode == XK_f)
	{
		if (mlx->trans_arg.type != RT_F)
		{
			mlx->trans_arg.type = RT_F;
			mlx->trans_arg.arg = mlx->scene.figures.head;
		}
		else
		{
			mlx->trans_arg.arg = ((t_figure *)mlx->trans_arg.arg)->next;
			if (!mlx->trans_arg.arg)
				mlx->trans_arg.arg = mlx->scene.figures.head;
		}
	}
	return (0);
}

static int	transform_element(int keycode, t_mlx *mlx)
{
	t_trans	transform_handler;
	void	*arg;

	transform_handler = get_transform_handler(mlx);
	arg = get_handler_arg(mlx);
	if (!arg)
		return (0);
	if (keycode == XK_q)
		transform_handler(arg, -1, 0, 0);
	else if (keycode == XK_w)
		transform_handler(arg, 1, 0, 0);
	else if (keycode == XK_a)
		transform_handler(arg, 0, -1, 0);
	else if (keycode == XK_s)
		transform_handler(arg, 0, 1, 0);
	else if (keycode == XK_z)
		transform_handler(arg, 0, 0, -1);
	else if (keycode == XK_x)
		transform_handler(arg, 0, 0, 1);
	if (mlx->trans_mode != RT_RESIZE)
		post_transform(mlx);
	return (0);
}

static void	post_transform(t_mlx *mlx)
{
	t_camera	*cam;
	t_figure	*fig;

	if (mlx->trans_arg.type == RT_C)
	{
		cam = &mlx->scene.cam;
		mlx->scene.cam = make_camera(cam->center, cam->rotate, cam->fov);
		mlx->trans_arg.arg = &mlx->scene.cam;
	}
	else if (mlx->trans_arg.type == RT_F)
	{
		fig = (t_figure *) mlx->trans_arg.arg;
		fig->vector = fig->rotate.vector;
	}
}
