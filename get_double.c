/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:06:26 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/17 16:26:40 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int 	get_sign(long value)
{
	long a;

	a = 1;
	a <<= 31;
	if (value & a)
		return (1);
	else
		return (0);
}

static int 	get_order(long value)
{
	long temp;

	temp = 1;
	temp <<= 31;
	value &= (~temp);
	value >>= 23;
	return ((int)value);
}

char	*get_double(const void *arg)
{
	const long long *p = arg;
	const float *val = arg;
	float a = *val;

	printf("%lf %lli\n", *val, *p);
	printf("%i\n", get_sign(*p));
	printf("%i\n", get_order(*p) - 127);

	return NULL;
}
