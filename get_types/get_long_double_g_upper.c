/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_double_g.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 10:30:55 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/25 16:51:19 by rwalder-         ###   ########.fr       */
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
	long double min;
	long double max;
	unsigned int i;

	min = 99;
	max = 1;
	i = 0;
	val = (val >= 0) ? val : (val * -1);
	while (i < precision)
	{
		min /= 10;
		max *= 10;
		i++;
	}
	if ((val >= max || val <= min) && val != 0.0)
		return (1);
	return (0);
}

char	*get_long_double_g_upper(long double arg, unsigned int precision)
{
	char *temp;
	char *ret;
	char *temp2;
	int i;
	int exp;
	long double val;

	val = arg;
	if ((ret = get_const_long_double(arg)) != NULL)
		return (ret);
	if (is_exp(arg, precision))
	{
		temp = get_long_double_exp_upper(arg, precision - 1);
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
		temp = get_long_double_upper(arg, precision);
		exp = 0;
		i = 0;
		if (temp[i] == '-')
			i++;
		if (temp[i] == '0')
			i++;
		if (temp[i] == '.')
			i++;
		while (temp[i] == '0')
			i++;
		if (i > (val > 0) ? (2) : (3))
			temp = get_long_double_upper(arg, precision + i - ((val > 0) ? (2) :
			(3)));
		while (exp < precision && temp[i] != '\0')
		{
			if (temp[i] != '.')
				exp++;
			i++;
		}
		i--;
		while (temp[i] == '0')
			i--;
		if (temp[i] == '.')
			i--;
		ret = ft_strsub(temp, 0,  i + 1);
		ft_strdel(&temp);
	}
	return (ret);
}