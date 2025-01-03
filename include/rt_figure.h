/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:40:41 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/03 15:45:54 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_FIGURE_H
# define RT_FIGURE_H

# define RT_FIGURE	"cy\0pl\0sp"

typedef enum e_fig_type
{
	RT_CY = 0,
	RT_PL = 3,
	RT_SP = 6,
}	t_fig_type;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef t_vec	t_coord;
typedef t_vec	t_color;

typedef struct s_figure
{
	t_fig_type	identifier;
	t_coord		center;
	t_vec		vector;
	double		diameter;
	double		height;
	t_color		color;
}	t_figure;

t_figure	*parse_cylinder(char **figure_attr);
t_figure	*parse_plane(char **figure_attr);
t_figure	*parse_sphere(char **figure_attr);

void		draw_cylinder(t_figure *figure);
void		draw_plane(t_figure *figure);
void		draw_sphere(t_figure *figure);

/* rt_figure_utils */
t_coord		parse_to_coord(char *str);
t_color		parse_to_color(char *str);
int			to_rgb_color(t_color color);

/* rt_figure */
t_figure	*make_figure(char **figure_attr);
void		draw_figure(t_figure *figure);

#endif
