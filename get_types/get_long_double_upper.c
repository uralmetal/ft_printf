/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_double_upper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:47:52 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/30 15:46:08 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

char	*get_long_double_upper(long double arg, unsigned int precision)
{
	long double	frac_part;
	long double	int_part;
	char		*ret;
	long		sign;

	if ((ret = get_const_double_upper(arg)) != NULL)
		return (ret);
	frac_part = get_fraction(arg);
	int_part = (arg >= 0) ? (arg - frac_part) : (arg + frac_part);
	ft_round(&int_part, &frac_part, precision);
	sign = sign_double((double)arg);
	ret = get_integer_str(int_part, sign);
	if (precision != 0)
		get_fraction_str(frac_part, precision, &ret);
	return (ret);
}
