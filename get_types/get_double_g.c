/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_g.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:08:14 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/29 18:39:50 by gleonett         ###   ########.fr       */
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

static int is_exp(double val, unsigned int precision)
{
	double min;
	double max;
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

char	*get_double_g(double arg, unsigned int precision)
{
	char *temp;
	char *ret;
	char *temp2;
	int i;
	int exp;
	double val;

	if ((ret = get_const_double(arg)) != NULL)
		return (ret);
	if (is_exp(arg, precision))
	{
		temp = get_double_exp(arg, precision - 1);
		i = ft_strlen(temp) - 1;
		while (temp[i] != 'e')
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
		temp = get_double(arg, precision);
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
			temp = get_double(arg, precision + i - ((val > 0) ? (2) : (3)));
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