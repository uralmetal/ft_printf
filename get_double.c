/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:06:26 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/18 12:42:03 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


static char *get_const_double(double value)
{
	const double p_inf = 1.0/0.0;
	const double n_inf = -1.0/0.0;
	const double nan = 0.0/0.0;
	if (value == p_inf)
		return ft_strdup("inf");
	if (value == n_inf)
		return ft_strdup("-inf");
	if (value == nan)
		return ft_strdup("nan");
	return (NULL);
}

char	*get_double(const void *arg, unsigned int precision)
{
	const double *a = arg;
	long int_part = (long)*a;
	long temp;
	int i;
	double frac_part = *a - int_part;
	printf("my\n%li.", int_part);
	i = 0;
	while (i < precision)
	{
		frac_part *= 10;
		temp = (long)(frac_part);
		printf("%li", temp);
		frac_part -= temp;
		i++;
	}
	return NULL;
}
