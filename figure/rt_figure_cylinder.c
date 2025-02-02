/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:21:13 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/02 23:36:27 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>
#include "rt_utils.h"
#include "rt_vector.h"
#include "libft.h"

#include "rt_figure.h"

/**
 * Cylinder: cy	50.0,0.0,20.6	0.0,0.0,1.0		14.2	21.42	10,0,255
 * identifier: cy
 * x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
 * 3d normalized vector of axis of cylinder. 
 * 		In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
 * the cylinder diameter: 14.2
 * the cylinder height: 21.42
 * R,G,B colors in range [0,255]: 10, 0, 255
 */

t_figure	*parse_cylinder(char **figure_attr)
{
	t_figure	*figure;

	figure = (t_figure *)ft_calloc(1, sizeof(t_figure));
	figure->identifier = RT_CY;
	figure->center = parse_to_coord(figure_attr[1]);
	figure->vector = parse_to_coord(figure_attr[2]);
	figure->diameter = rt_atof(figure_attr[3]);
	figure->height = rt_atof(figure_attr[4]);
	figure->color = parse_to_color(figure_attr[5]);
	return (figure);
}

double	hit_cylinder(t_figure *figure, t_ray *ray)
{
    t_vec offset, hit_point;
    double discrim[4];
    double t_cyl[3]; // 원통의 곡면
    double t_cap[2]; // 원통의 아랫면과 윗면
    double min_t = -1.0;

    offset = v_sub(ray->origin, figure->center);

    // 1. 원통 곡면 충돌 검사
    discrim[0] = v_length_squared(ray->direction) - pow(v_dot(ray->direction, v_unit(figure->vector)), 2);
    discrim[1] = 2 * (v_dot(ray->direction, offset) - v_dot(ray->direction, v_unit(figure->vector)) * v_dot(offset, v_unit(figure->vector)));
    discrim[2] = v_length_squared(offset) - pow(v_dot(offset, v_unit(figure->vector)), 2) - pow(figure->diameter / 2.0, 2);

    discrim[3] = discrim[1] * discrim[1] - 4 * discrim[0] * discrim[2];
    if (discrim[3] >= 0)
    {
        t_cyl[0] = (-discrim[1] - sqrt(discrim[3])) / (2 * discrim[0]);
        t_cyl[1] = (-discrim[1] + sqrt(discrim[3])) / (2 * discrim[0]);

        if (t_cyl[0] > t_cyl[1]) 
        {
            t_cyl[2] = t_cyl[0];
            t_cyl[0] = t_cyl[1];
            t_cyl[1] = t_cyl[2];
        }

        // 원통 곡면 충돌이 원통 높이 범위 내에 있는지 체크
        hit_point = v_add(ray->origin, v_mul(ray->direction, t_cyl[0]));
        double hit_height = v_dot(v_sub(hit_point, figure->center), v_unit(figure->vector));
        if (hit_height >= -figure->height / 2.0 && hit_height <= figure->height / 2.0)
            min_t = t_cyl[0];
        else
        {
            hit_point = v_add(ray->origin, v_mul(ray->direction, t_cyl[1]));
            hit_height = v_dot(v_sub(hit_point, figure->center), v_unit(figure->vector));
            if (hit_height >= -figure->height / 2.0 && hit_height <= figure->height / 2.0)
                min_t = t_cyl[1];
        }
    }

    // 2. 원통의 아랫면과 윗면 충돌 검사 (둥글게 계산)
    // 아랫면 (figure->center를 기준으로 원통의 높이만큼 아래)
    t_cap[0] = v_dot(v_sub(v_add(figure->center, v_mul(v_unit(figure->vector), -figure->height / 2.0)), ray->origin), v_unit(figure->vector)) /
               v_dot(ray->direction, v_unit(figure->vector));
    hit_point = v_add(ray->origin, v_mul(ray->direction, t_cap[0]));
    if (v_length_squared(v_sub(hit_point, v_add(figure->center, v_mul(v_unit(figure->vector), -figure->height / 2.0)))) 
        <= pow(figure->diameter / 2.0, 2) && t_cap[0] > 0)
    {
        if (min_t < 0 || t_cap[0] < min_t)
            min_t = t_cap[0];
    }

    // 윗면 (figure->center를 기준으로 원통의 높이만큼 위)
    t_cap[1] = v_dot(v_sub(v_add(figure->center, v_mul(v_unit(figure->vector), figure->height / 2.0)), ray->origin), v_unit(figure->vector)) /
               v_dot(ray->direction, v_unit(figure->vector));
    hit_point = v_add(ray->origin, v_mul(ray->direction, t_cap[1]));
    if (v_length_squared(v_sub(hit_point, v_add(figure->center, v_mul(v_unit(figure->vector), figure->height / 2.0)))) 
        <= pow(figure->diameter / 2.0, 2) && t_cap[1] > 0)
    {
        if (min_t < 0 || t_cap[1] < min_t)
            min_t = t_cap[1];
    }

    return min_t;
}

t_color	color_cylinder(t_coord hit_point, t_light *light, t_figure *figure)
{
	(void)hit_point;
	(void)light;
	return (figure->color);
}
