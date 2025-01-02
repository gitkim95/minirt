/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:40:41 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/02 19:55:09 by hwilkim          ###   ########.fr       */
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

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}	t_coord;

typedef struct s_figure
{
	t_fig_type	identifier;
	t_coord		center;
	t_coord		vector;
	double		diameter;
	double		height;
	int			color;
}	t_figure;

t_figure	*parse_cylinder(char **figure_attr);
t_figure	*parse_plane(char **figure_attr);
t_figure	*parse_sphere(char **figure_attr);

/* rt_figure */
t_figure	*make_figure(char **figure_attr);

#endif
