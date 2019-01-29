/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:55:03 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/26 16:44:58 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long get_mantissa(double val)
{
	long ret;
	long mask = 0xFFF;

	mask <<= 52;
	mask = ~mask;
	ret = *(long*)&val;
	return (ret & mask);
}

static long get_exponent(double val)
{
	long ret;
	long sign;

	sign = 1;
	sign <<= 63;
	ret = *(long*)&val;
	ret &= ~sign;
	ret >>= 52;
	return (ret);
}

static void	symtohex(unsigned long long c, char *hex, unsigned int size)
{
	int value;
	int count;

	count = size - 1;
	while (count >= 0)
		hex[count--] = '0';
	count = size - 1;
	while (c > 0)
	{
		value = c;
		c = c / 16;
		value = value - c * 16;
		if (value >= 10)
			hex[count--] = 'a' + value - 10;
		else
			hex[count--] = '0' + value;
	}
}

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

char	*get_double_hex(double arg)
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
			return (ft_strdup("-0x0p+0"));
		else
			return (ft_strdup("0x0p+0"));
	}
	if (sign != 0)
		ret = ft_strdup("-0x1.");
	else
		ret = ft_strdup("0x1.");
	temp = get_mantissa(arg);
	temp_s = ft_strnew(13);
	symtohex(temp, temp_s, 13);
	join = ft_strjoin(ret, temp_s);
	ft_strdel(&ret);
	ft_strdel(&temp_s);
	ret = join;
	ret = string_cut(&ret);
	temp = get_exponent(arg) - 1023;
	if (temp < 0)
		join = ft_strjoin(ret, "p");
	else
		join = ft_strjoin(ret, "p+");
	ft_strdel(&ret);
	ret = join;
	temp_s = ft_lltoa(temp);
	join = ft_strjoin(ret, temp_s);
	ft_strdel(&ret);
	ft_strdel(&temp_s);
	ret = join;
	return (ret);
}
