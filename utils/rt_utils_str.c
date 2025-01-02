/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:34:37 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/02 20:02:51 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
