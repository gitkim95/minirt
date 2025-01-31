/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:25:08 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/31 23:42:35 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSE_H
# define RT_PARSE_H

# include "rt_struct.h"

/* rt_parse.c */
void	parse_data(t_mlx *mlx, char *file_path);

/* rt_parse_figure.c */
void	set_figure_struct(t_fig_list *list, char **data, t_fig_type type);

/* rt_parse_scene.c */
void	set_scene_struct(t_scene *scene, char **data, t_scene_type type);

#endif