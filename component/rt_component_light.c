/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_component_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:30:53 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/07 02:15:55 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "rt_vector.h"

#include "rt_component.h"

double hit_light(t_light *light, t_ray *ray) {
    // 광원의 위치와 카메라 광선 상의 충돌 여부 검사

    // 광원을 구(Sphere)로 가정하고 광선과의 교차점 계산
    t_coord oc = v_sub(ray->origin, light->center);
    double a = v_dot(ray->direction, ray->direction);
    double b = 2.0 * v_dot(oc, ray->direction);
    double c = v_dot(oc, oc) - 400;

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double t1 = (-b - sqrt(discriminant)) / (2 * a);
        double t2 = (-b + sqrt(discriminant)) / (2 * a);
        double t = (t1 + t2) / 2;

        if (t >= 0) {
            return t; // 충돌 발생
        }
    }

    return -1; // 충돌 없음
}

t_color color_light(t_color color, t_coord hit_point, t_light *light)
{
    // 광원의 표면 좌표를 이용해 색상 계산
    t_coord light_dir = v_sub(light->center, hit_point); // 광원 -> 충돌 지점 방향 벡터
    double distance = v_length(light_dir); // 광원과 충돌 지점 사이의 거리

    // 자연스러운 감쇠 효과 적용 (거리 제곱에 반비례)
    double attenuation = 1.0 / (1.0 + distance * distance);

    // 광원의 색상과 세기를 이용하여 최종 색상 계산

	if (color.x < 0)
		color.x = 0;
	color.x = fmin(1.0, color.x + light->color.x * attenuation);
	color.y = fmin(1.0, color.y + light->color.y * attenuation);
	color.z = fmin(1.0, color.z + light->color.z * attenuation);
    return color;
}