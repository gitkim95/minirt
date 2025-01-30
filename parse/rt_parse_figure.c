/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_figure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:11:53 by gitkim            #+#    #+#             */
/*   Updated: 2025/01/30 21:24:08 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_parse.h"
#include "rt_struct.h"

void	set_sphere(t_fig_list *fig_list, char **data)
{

}

void	set_plane(t_fig_list *fig_list, char **data)
{

}

void	set_cylinder(t_fig_list *fig_list, char **data)
{

}

void	set_figure_struct(t_fig_list *fig_list, char **data, t_fig_type type)
{
	if (type == RT_SP)
		set_sphere(fig_list, data);
	else if (type == RT_PL)
		set_plane(fig_list, data);
	else
		set_cylinder(fig_list, data);
}
