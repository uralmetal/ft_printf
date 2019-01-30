/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_double_g.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 10:30:55 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/30 09:31:33 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char *get_const_long_double(long double value)
{
	char *res;
	const long double p_inf = 1.0/0.0;
	const long double n_inf = -1.0/0.0;

	res = NULL;
	if (value == p_inf)
		CH_NULL(res = ft_strdup("INF"));
	if (value == n_inf)
		CH_NULL(res = ft_strdup("-INF"));
	if (value != value)
		CH_NULL(res = ft_strdup("NAN"));
	return (res);
}

static int is_exp(long double val, unsigned int precision)
{
	val = (val >= 0) ? val : (val * -1);
	if (precision == 0)
	{
		if ((val > 1e-4 && val < 10) || val == 0.0)
			return (0);
		return (1);
	}
	if ((val + 0.5 >= 1e6 || val < 1e-4) && val != 0.0)
		return (1);
	return (0);
}

static long double 	get_fraction(long double value)
{
	long double ret = 0.0;
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
		while (ret > (long double)a)
			ret = ret / 10;
		a = (unsigned long)ret;
		ret = ret - a;
	}
	return (ret);
}

char	*get_long_double_g_upper(long double arg, unsigned int precision)
{
	char *temp;
	char *ret;
	char *temp2;
	int i;
	int exp;
	long double val;

	if ((ret = get_const_long_double(arg)) != NULL)
		return (ret);
	if (is_exp(arg, precision))
	{
		temp = get_long_double_exp_upper(arg, (precision == 0) ? (0) :
		(precision - 1));
		i = ft_strlen(temp) - 1;
		while (temp[i] != 'E')
			i--;
		exp = i--;
		while (temp[i] == '0')
			i--;
		if (temp[i] == '.')
			i--;
		ret = ft_strsub(temp, 0, i + 1);
		temp2 = ft_strsub(temp, exp, ft_strlen(temp) - exp);
		ft_strdel(&temp);
		temp = ft_strjoin(ret, temp2);
		ft_strdel(&ret);
		ft_strdel(&temp2);
		ret = temp;
	}
	else
	{
		if (((arg < 0) ? (arg * -1) : (arg)) < 1.0)
		{
			val = ((arg < 0) ? (arg * -1) : (arg));
			while (val < 1.0)
			{
				val *= 10;
				precision++;
			}
			temp = get_long_double(arg, precision);
		}
		else
		{
			val = arg - get_fraction(arg);
			val = (val < 0) ? (val * -1.0) : (val);
			while (val >= 1.0 && precision > 0)
			{
				val /= 10.0;
				precision--;
			}
			temp = get_long_double(arg, precision);
		}
		i = ft_strlen(temp) - 1;
		if (precision != 0)
		{
			while (temp[i] == '0')
				i--;
			if (temp[i] == '.')
				i--;
		}
		ret = ft_strsub(temp, 0,  i + 1);
		ft_strdel(&temp);
	}
	return (ret);
}