/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:41:32 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/02 04:20:41 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_figure.h"
#include "rt_vector.h"
#include "rt_mlx.h"

#include "rt_scene.h"

static t_ray	calculate_cam_ray(t_camera *cam, int i, int j);
static t_color	calculate_figure_color(t_ray *cam_ray, t_mlx *mlx);
static int		has_color(t_color color);

void	draw_scene(t_mlx *mlx)
{
	t_ray	cam_ray;
	t_color	color;
	int		color_value;
	int		i;
	int		j;

	j = 0;
	while (j < RT_HEIGHT)
	{
		i = 0;
		while (i < RT_WIDTH)
		{
			cam_ray = calculate_cam_ray(&mlx->scene.cam, i, j);
			color = calculate_figure_color(&cam_ray, mlx);
			if (has_color(color))
				color_value = to_rgb_color(color);
			else
				color_value = to_rgb_color(mlx->scene.amb_light.color);
			draw_pixel_to_img(&mlx->img_data, i, j, color_value);
			++i;
		}
		++j;
	}
}

static t_ray	calculate_cam_ray(t_camera *cam, int i, int j)
{
	t_coord	pixel;
	t_vec	ray_direction;

	pixel = v_add(v_mul(cam->pixel_delta_u, i), v_mul(cam->pixel_delta_v, j));
	pixel = v_add(cam->pixel_zero_loc, pixel);
	ray_direction = v_sub(pixel, cam->center);
	return ((t_ray){cam->center, ray_direction});
}

static t_color	calculate_figure_color(t_ray *cam_ray, t_mlx *mlx)
{
	t_figure	*figure;
	t_color		color;
	double		hit;

	figure = mlx->scene.figures.head;
	color = (t_color){-1, 0, 0};
	while (figure)
	{
		hit = hit_figure(figure, cam_ray);
		if (hit > 0)
			color = color_figure(cam_ray, &mlx->scene.light, figure, hit);
		figure = figure->next;
	}
	return (color);
}

static int	has_color(t_color color)
{
	return (color.x >= 0);
}
