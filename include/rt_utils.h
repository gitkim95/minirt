/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:35:02 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/03 20:40:16 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_UTILS_H
# define RT_UTILS_H

# include <stdbool.h>
# include "rt_struct.h"

/* rt_utils_digit */
void	rt_swap(double *a, double *b);
bool	rt_issign(char c);
bool	rt_isupper(char c);

/* rt_utils_mem */
void	rt_free_figure(t_fig_list *list);
void	rt_free_split(char **split);

/* rt_utils_str */
int		rt_strcmp(char *s1, char *s2);
char	*rt_strcat(char *dest, char const *src);
bool	rt_str_equals(char *s1, char *s2);
double	rt_atof(char *str);

#endif