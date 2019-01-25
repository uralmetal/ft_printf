/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_exp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:40:44 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/25 13:44:25 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char *get_const_double(double value)
{
	char *res;
	const double p_inf = 1.0/0.0;
	const double n_inf = -1.0/0.0;

	res = NULL;
	if (value == p_inf)
		CH_NULL(res = ft_strdup("inf"));
	if (value == n_inf)
		CH_NULL(res = ft_strdup("-inf"));
	if (value != value)
		CH_NULL(res = ft_strdup("nan"));
	return (res);
}

static char *check_overflow(char *val, int *exp)
{
	int sign;
	int i;
	size_t len;

	sign = 0;
	i = 0;
	while (val[i] != '.')
	{
		if (val[i] == '-')
			sign = 1;
		i++;
	}
	if ((i - sign) >= 2)
	{
		val[i] = val[i - 1];
		val[i - 1] = '.';
		len = ft_strlen(val);
		val[len - 1] = 0;
		*exp = *exp + 1;
	}
	return (val);
}

static char *add_exp(char **val, int exp)
{
	char *exp_str;
	char *temp;
	char *ret;

	check_overflow(*val, &exp);
	temp = ft_lltoa((exp >= 0) ? (exp) : (exp * -1));
	if (ft_strlen(temp) == 1)
	{
		ret = temp;
		temp = ft_strjoin("0", ret);
		ft_strdel(&ret);
	}
	if (exp >= 0)
		exp_str = ft_strjoin("e+", temp);
	else
		exp_str = ft_strjoin("e-", temp);
	ft_strdel(&temp);
	ret = ft_strjoin(*val, exp_str);
	ft_strdel(val);
	*val = ret;
	return (ret);
}

char	*get_double_exp(double arg, unsigned int precision)
{
	int exp;
	char *ret;
	int sign;

	if ((ret = get_const_double(arg)) != NULL)
		return (ret);
	exp = 0;
	sign = (arg >= 0.0) ? (1) : (-1);
	arg *= sign;
	if (arg >= 10.0)
	{
		while (arg >= 10.0)
		{
			arg /= 10.0;
			exp++;
		}
	}
	else if (arg != 0.0)
	{
		while (arg < 1)
		{
			arg *= 10.0;
			exp--;
		}
	}
	arg *= sign;
	ret = get_double(arg, precision);
	add_exp(&ret, exp);
	return (ret);
}