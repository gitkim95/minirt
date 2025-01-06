/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:35:02 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/06 19:18:02 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_H
# define RT_UTILS_H

# include "rt_struct.h"

/* rt_utils_mem */
void	rt_free_figure(t_fig_list *list);
void	rt_free_split(char **split);

/* rt_utils_str */
int		rt_strcmp(char *s1, char *s2);
double	rt_atof(char *str);

#endif