/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:40:41 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/06 18:48:06 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FIGURE_H
# define RT_FIGURE_H

# include "rt_struct.h"

t_figure	*parse_cylinder(char **figure_attr);
t_figure	*parse_plane(char **figure_attr);
t_figure	*parse_sphere(char **figure_attr);

void		draw_cylinder(t_figure *figure);
void		draw_plane(t_figure *figure);
double		hit_sphere(t_figure *figure, t_ray *ray);

/* rt_figure_utils */
void		append_fig_list(t_fig_list *list, t_figure *figure);
t_coord		parse_to_coord(char *str);
t_color		parse_to_color(char *str);
int			to_rgb_color(t_color color);

/* rt_figure */
t_figure	*make_figure(char **figure_attr);
void		draw_figure(t_figure *figure, t_ray *ray);

#endif
