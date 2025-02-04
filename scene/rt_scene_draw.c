/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:41:32 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/04 21:35:49 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_figure.h"
#include "rt_mlx.h"
#include "rt_ray.h"
#include "rt_vector.h"

#include "rt_scene.h"

static t_ray	calculate_cam_ray(t_camera *cam, int i, int j);
static t_color	calculate_figure_color(t_ray *ray, t_mlx *mlx, t_figure	*fig);
static t_coord	get_surface_coord(t_ray *cam_ray, double hit, t_vec offset);
static int		has_color(t_color color);

void	draw_scene(t_mlx *mlx)
{
	t_ray		cam_ray;
	t_color		color;
	t_figure	*head;
	int			i;
	int			j;

	head = mlx->scene.figures.head;
	j = 0;
	while (j < RT_HEIGHT)
	{
		i = 0;
		while (i < RT_WIDTH)
		{
			cam_ray = calculate_cam_ray(&mlx->scene.cam, i, j);
			color = calculate_figure_color(&cam_ray, mlx, head);
			if (has_color(color))
				draw_pixel_to_img(&mlx->img_data, i, j, to_rgb_color(color));
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

static t_color	calculate_figure_color(t_ray *ray, t_mlx *mlx, t_figure	*fig)
{
	t_coord		coord;
	t_color		color;
	t_vec		offset;
	double		hit;
	double		hit_min;

	color = (t_color){RT_COLOR_NONE, 0, 0};
	offset = v_mul(ray->direction, -RT_EPSILON);
	hit_min = INFINITY;
	while (fig)
	{
		hit = fig->calculate_hit(fig, ray);
		if (hit > 0 && hit_min > hit)
		{
			hit_min = hit;
			coord = get_surface_coord(ray, hit, offset);
			color = color_figure(coord, ray, &mlx->scene, fig);
		}
		fig = fig->next;
	}
	return (color);
}

static t_coord	get_surface_coord(t_ray *cam_ray, double hit, t_vec offset)
{
	return (v_add(ray_at(cam_ray, hit), offset));
}

static int	has_color(t_color color)
{
	return (color.x >= 0);
}
