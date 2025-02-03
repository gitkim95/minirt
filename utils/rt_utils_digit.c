/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:34:37 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/03 02:42:37 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "rt_utils.h"

void	rt_swap(double *a, double *b)
{
	double	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

bool	rt_issign(char c)
{
	return (c == '-' || c == '+');
}

bool	rt_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}
