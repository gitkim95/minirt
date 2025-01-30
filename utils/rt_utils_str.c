/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:34:37 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/30 22:14:30 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "rt_utils.h"

int	rt_strcmp(char *s1, char *s2)
{
	unsigned char	c1;
	unsigned char	c2;
	unsigned int	idx;

	idx = 0;
	while (s1[idx] != '\0' && s2[idx] != '\0')
	{
		c1 = s1[idx];
		c2 = s2[idx];
		if (c1 != c2)
			return (c1 - c2);
		++idx;
	}
	c1 = s1[idx];
	c2 = s2[idx];
	return (c1 - c2);
}

int	rt_all_isdigit(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}

double	rt_atof(char *str)
{
	double	int_part;
	double	fract_part;
	char	*dot;

	dot = ft_strchr(str, '.');
	*dot = '\0';
	if (rt_all_isdigit(str))
		int_part = ft_atoi(str);
	if (rt_all_isdigit(dot + 1))
		fract_part = ft_atoi(dot + 1);
	while (fract_part >= 1)
		fract_part /= 10.0;
	if (ft_strchr(str, '-'))
		fract_part *= -1;
	return (int_part + fract_part);
}
