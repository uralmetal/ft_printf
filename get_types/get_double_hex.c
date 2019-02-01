/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:55:03 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/31 10:52:00 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*add_mantissa(double arg, char **ret, int sign)
{
	char	*temp_s;
	long	temp;
	char	*join;

	if (sign != 0)
		*ret = ft_strdup("-0x1.");
	else
		*ret = ft_strdup("0x1.");
	temp = get_mantissa(arg);
	temp_s = ft_strnew(13);
	symtohex(temp, temp_s, 13);
	join = ft_strjoin(*ret, temp_s);
	ft_strdel(ret);
	ft_strdel(&temp_s);
	*ret = join;
	*ret = string_cut(ret);
	return (*ret);
}

static char	*add_exponent(double arg, char **ret)
{
	char	*temp_s;
	long	temp;
	char	*join;

	temp = get_exponent(arg) - 1023;
	if (temp < 0)
		join = ft_strjoin(*ret, "p");
	else
		join = ft_strjoin(*ret, "p+");
	ft_strdel(ret);
	*ret = join;
	temp_s = ft_lltoa(temp);
	join = ft_strjoin(*ret, temp_s);
	ft_strdel(ret);
	ft_strdel(&temp_s);
	*ret = join;
	return (*ret);
}

char		*get_double_hex(double arg, int precision)
{
	char	*ret;
	int		sign;

	if ((ret = get_const_double(arg)) != NULL)
		return (ret);
	sign = sign_double(arg);
	precision = precision + 1;
	if (arg == 0.0)
	{
		if (sign != 0)
			return (ft_strdup("-0x0p+0"));
		else
			return (ft_strdup("0x0p+0"));
	}
	ret = add_mantissa(arg, &ret, sign);
	ret = add_exponent(arg, &ret);
	return (ret);
}
