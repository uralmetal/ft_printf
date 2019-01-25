/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:33:04 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/25 16:33:43 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

static char *get_const_double(double value)
{
	char *res;
	const double p_inf = 1.0/0.0;
	const double n_inf = -1.0/0.0;

	res = NULL;
	if (value == p_inf)
		CH_NULL(res = ft_strdup("INF"));
	if (value == n_inf)
		CH_NULL(res = ft_strdup("-INF"));
	if (value != value)
		CH_NULL(res = ft_strdup("NAN"));
	return (res);
}

static double 	get_fraction(double value)
{
	double ret = 0.0;
	unsigned long a;

	ret = value;
	if (ret < 0)
		ret *= -1.0;
	a = (unsigned long)-1;
	if (ret <= a)
	{
		a = (unsigned long)ret;
		ret = ret - a;
	}
	else
	{
		while (ret > (double)a)
			ret = ret / 10;
		a = (unsigned long)ret;
		ret = ret - a;
	}
	return ((double)(ret));
}

static char *get_fraction_str(double frac_part, unsigned int precision, char
**init_part_str)
{
	long temp;
	int i;
	char *ret;
	char *frac_part_str;

	i = 0;
	CH_NULL(frac_part_str = ft_strnew(precision + 1));
	frac_part_str[i++] = '.';
	while (i < precision + 1)
	{
		frac_part *= 10;
		temp = (long)(frac_part);
		frac_part_str[i] = '0' + temp;
		frac_part -= temp;
		i++;
	}
	ret = ft_strjoin(*init_part_str, frac_part_str);
	ft_strdel(init_part_str);
	*init_part_str = ret;
	return (ret);
}

static char *get_integer_str(double int_part, long sign)
{
	int 		i;
	char 		*ret;
	double 		temp;
	int			count;

	temp = ((int_part < 0) ? (int_part * -1.0) : (int_part)) + 0.5 ;
	i = 0;
	if (int_part == 0.0)
	{
		CH_NULL(ret =  ft_strdup((sign == 0) ? "0" : "-0"));
		return (ret);
	}
	while (temp >= 1.0)
	{
		temp /= 10;
		i++;
	}
	i = (sign == 0) ? (i - 1) : (i);
	CH_NULL(ret = ft_strnew(i));
	ret[i + 1] = 0;
	ret[0] = '-';
	count = (int_part < 0) ? 1 : 0;
	while (i >= (int_part < 0) ? 1 : 0)
	{
		temp *= 10;
		sign = (int)temp;
		ret[count++] = temp + '0';
		i--;
		temp -= sign;
	}
	return (ret);
}

static void round(double *int_part, double *frac_part, unsigned int precision)
{
	int i;
	double div;

	if (precision == 0)
	{
		if (*frac_part == 0.5)
		{
			if ((long)(*int_part) % 2 == 1)
				*int_part = *int_part + 1;
		}
		if (*frac_part > 0.5)
			*int_part = *int_part + 1;
	}
	else
	{
		i = 0;
		div = 0.5;
		while (i < precision)
		{
			div /= 10;
			i++;
		}
		*frac_part = *frac_part + div;
		if (*frac_part >= 1)
		{
			*frac_part = *frac_part - 1;
			*int_part = *int_part + 1;
		}
	}
}

char	*get_double_upper(double arg, unsigned int precision)
{
	double frac_part;
	double int_part;
	char *ret;
	long sign;

	if ((ret = get_const_double(arg)) != NULL)
		return (ret);
	frac_part = get_fraction(arg);
	int_part =  (arg >= 0) ? (arg - frac_part) : (arg + frac_part);
	round(&int_part, &frac_part, precision);
	sign = sign_double(arg);
	ret = get_integer_str(int_part, sign);
	if (precision != 0)
		get_fraction_str(frac_part, precision, &ret);
	return (ret);
}