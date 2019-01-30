/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_double_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:54:56 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/26 20:31:40 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static unsigned long get_mantissa(long double val)
{
	return (*(unsigned long *)&val);
}

static short get_exponent(long double val)
{
	short ret;
	long sign;
	unsigned long *p = (unsigned long *)&val;

	sign = 1;
	sign <<= 15;
	ret = (short)*(p + 1);
	ret &= ~sign;
	return (ret);
}

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

static char *string_cut(char **val)
{
	char *ret;
	int len;
	int i;

	len = ft_strlen(*val);
	i = len - 1;
	if ((*val)[len -1] != '.' && (*val)[len - 1] != '0')
		return (*val);
	while (i >= 0 && ((*val)[i] == '0' || (*val)[i] == '.'))
		i--;
	ret = ft_strsub(*val, 0, i + 1);
	return (ret);
}

static char *add_comma(char **mantissa)
{
	int len;
	char *ret;
	int i;
	int j;

	len = ft_strlen(*mantissa);
	ret = ft_strnew(len + 1);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (j == 1)
		{
			ret[j] = '.';
			j++;
			continue ;
		}
		ret[j] = (*mantissa)[i];
		j++;
		i++;
	}
	ft_strdel(mantissa);
	return (ret);
}

char	*get_long_double_hex_upper(long double arg)
{
	char *ret;
	int sign;
	char *temp_s;
	long temp;
	char *join;

	if ((ret = get_const_double(arg)) != NULL)
		return (ret);
	sign = sign_double(arg);
	if (arg == 0.0)
	{
		if (sign != 0)
			return (ft_strdup("-0X0P+0"));
		else
			return (ft_strdup("0X0P+0"));
	}
	if (sign != 0)
		ret = ft_strdup("-0X");
	else
		ret = ft_strdup("0X");
	temp = get_mantissa(arg);
	temp_s = get_unsigned_long_long_hex_upper(&temp);
	temp_s = add_comma(&temp_s);
	join = ft_strjoin(ret, temp_s);
	ft_strdel(&ret);
	ft_strdel(&temp_s);
	ret = join;
	ret = string_cut(&ret);
	temp = get_exponent(arg) - 16386;
	if (temp < 0)
		join = ft_strjoin(ret, "P");
	else
		join = ft_strjoin(ret, "P+");
	ft_strdel(&ret);
	ret = join;
	temp_s = ft_lltoa(temp);
	join = ft_strjoin(ret, temp_s);
	ft_strdel(&ret);
	ft_strdel(&temp_s);
	ret = join;
	return (ret);
}
