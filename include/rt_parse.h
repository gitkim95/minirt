/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:25:08 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/06 03:38:50 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSE_H
# define RT_PARSE_H

# include "rt_struct.h"

typedef struct s_comp_init
{
	t_coord		center;
	t_vec		dir;
	int			fov;
	double		bright;
	t_color		color;
	t_rotate	rotate;
}	t_comp_init;

/* rt_parse_component.c */
void	parse_component(t_scene *scene, char **data);

/* rt_parse_figure.c */
void	parse_figure(t_fig_list *list, char **data);

/* rt_parse.c */
void	parse_data(t_mlx *mlx, char *file_path);

#endif