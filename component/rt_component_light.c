/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_component_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:30:53 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/06 07:18:11 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "rt_vector.h"

#include "rt_component.h"

double hit_light(t_light *light, t_ray *ray)
{
    double max_distance = 50.0; // 광원의 최대 영향 범위
    
    t_vec offset = v_sub(light->center, ray->origin);
    double distance = v_length(offset);
    
    if (distance > max_distance)
        return (-1.0);
    
    return (distance);
}

double calculate_attenuation(t_coord point, t_light *light)
{
    t_vec distance_vec = v_sub(point, light->center);
    double distance = v_length(distance_vec);
    
    // 거리에 따른 감쇠 계수 (inverse square law)
    double constant = 1.0;
    double linear = 0.09;
    double quadratic = 0.032;
    
    return (1.0 / (constant + linear * distance + quadratic * distance * distance));
}
// 그림자 광선을 생성하는 함수
t_ray create_shadow_ray(t_coord hit_point, t_light *light)
{
    t_ray shadow_ray;
    t_vec light_dir = v_sub(light->center, hit_point);
    
    // 시작점을 약간 오프셋하여 자체 교차 방지
    shadow_ray.origin = v_add(hit_point, v_mul(v_unit(light_dir), 0.001));
    shadow_ray.direction = v_unit(light_dir);
    
    return shadow_ray;
}

// 그림자 검사 함수
bool is_in_shadow(t_coord hit_point, t_light *light, t_figure *fig)
{
    t_ray shadow_ray = create_shadow_ray(hit_point, light);
    double dist_to_light = v_length(v_sub(light->center, hit_point));
    
    // 모든 물체에 대해 교차 검사
    while(fig)
    {
        double t = fig->calculate_hit(fig, &shadow_ray);
        // 교차점이 있고, 그 거리가 광원까지의 거리보다 작으면 그림자
        if (t > 0.001 && t < dist_to_light)
            return true;
		fig = fig->next;
    }
    return false;
}

// 수정된 color_light 함수
t_color color_light(t_color color, t_coord hit_point, t_light *light, t_figure *fig)
{
    
    // 그림자 검사
    if (is_in_shadow(hit_point, light, fig))
        return color;
    
    // 그림자가 아닌 경우 기존의 조명 계산 수행
    double attenuation = calculate_attenuation(hit_point, light);
    
    // 감쇠값이 최소 밝기보다 작지 않도록 조정
    attenuation = fmax(attenuation, 0.1);
    
	if (color.x < 0)
		color.x = 0;
	color.x = fmin(1.0, color.x + (light->color_bright.x * attenuation));
	color.y = fmin(1.0, color.y + (light->color_bright.y * attenuation));
	color.z = fmin(1.0, color.z + (light->color_bright.z * attenuation));
    
    return color;
}