/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:34:37 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/02 05:42:09 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "rt_utils.h"

static bool	rt_all_isdigit(char *str);

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

bool	rt_str_equals(char *s1, char *s2)
{
	return (rt_strcmp(s1, s2) == 0);
}

double	rt_atof(char *str)
{
	double	int_part;
	double	fract_part;
	char	**sep_number;
	int		idx;

	sep_number = ft_split(str, '.');
	idx = 0;
	while (sep_number[idx])
		idx++;
	if (idx == 1)
		fract_part = 0.0;
	if (rt_all_isdigit(sep_number[0]))
		int_part = ft_atoi(sep_number[0]);
	if (idx == 2 && rt_all_isdigit(sep_number[1]))
		fract_part = ft_atoi(sep_number[1]);
	while (fract_part >= 1)
		fract_part /= 10.0;
	if (str[0] == '-')
		fract_part *= -1;
	rt_free_split(sep_number);
	return (int_part + fract_part);
}

static bool	rt_all_isdigit(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (idx == 0 && rt_issign(str[idx]))
			idx++;
		if (!ft_isdigit(str[idx]))
			return (false);
		idx++;
	}
	return (true);
}
