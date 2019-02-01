/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_double_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:54:56 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/31 10:52:00 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*add_comma(char **mantissa)
{
	int		len;
	char	*ret;
	int		i;
	int		j;

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

static char	*add_mantissa(long double arg, char **ret, int sign)
{
	char	*temp_s;
	long	temp;
	char	*join;

	if (sign != 0)
		*ret = ft_strdup("-0X");
	else
		*ret = ft_strdup("0X");
	temp = get_long_mantissa(arg);
	temp_s = get_unsigned_long_long_hex(&temp);
	temp_s = add_comma(&temp_s);
	join = ft_strjoin(*ret, temp_s);
	ft_strdel(ret);
	ft_strdel(&temp_s);
	*ret = join;
	*ret = string_cut(ret);
	return (*ret);
}

static char	*add_exponent(long double arg, char **ret)
{
	char	*temp_s;
	long	temp;
	char	*join;

	temp = get_long_exponent(arg) - 16386;
	if (temp < 0)
		join = ft_strjoin(*ret, "P");
	else
		join = ft_strjoin(*ret, "P+");
	ft_strdel(ret);
	*ret = join;
	temp_s = ft_lltoa(temp);
	join = ft_strjoin(*ret, temp_s);
	ft_strdel(ret);
	ft_strdel(&temp_s);
	*ret = join;
	return (*ret);
}

char		*get_long_double_hex_upper(long double arg)
{
	char	*ret;
	int		sign;

	if ((ret = get_const_double_upper(arg)) != NULL)
		return (ret);
	sign = sign_double(arg);
	if (arg == 0.0)
	{
		if (sign != 0)
			return (ft_strdup("-0X0P+0"));
		else
			return (ft_strdup("0X0P+0"));
	}
	ret = add_mantissa(arg, &ret, sign);
	ret = add_exponent(arg, &ret);
	return (ret);
}
