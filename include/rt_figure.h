/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:40:41 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/02 03:12:24 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FIGURE_H
# define RT_FIGURE_H

# include "rt_struct.h"

t_figure	*parse_cylinder(char **figure_attr);
t_figure	*parse_plane(char **figure_attr);
t_figure	*parse_sphere(char **figure_attr);

void		draw_cylinder(t_figure *figure);
double		hit_plane(t_figure *figure, t_ray *ray);
double		hit_sphere(t_figure *figure, t_ray *ray);

t_color		color_plane(t_ray *cam, t_light *light, t_figure *fig, double hit);
t_color		color_sphere(t_ray *cam, t_light *light, t_figure *fig, double hit);

/* rt_figure_utils */
void		append_fig_list(t_fig_list *list, t_figure *figure);
t_coord		parse_to_coord(char *str);
t_color		parse_to_color(char *str);
int			to_rgb_color(t_color color);

/* rt_figure */
t_figure	*make_figure(char **figure_attr);
double		hit_figure(t_figure *figure, t_ray *ray);
t_color		color_figure(t_ray *cam, t_light *light, t_figure *fig, double hit);

#endif
