/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_g.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:08:14 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/30 14:42:16 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*get_double_g(double arg, unsigned int precision)
{
	char *ret;

	if ((ret = get_const_double(arg)) != NULL)
		return (ret);
	if (is_exp(arg, precision))
		ret = handle_exp(arg, precision);
	else
		ret = handle_float(arg, precision);
	return (ret);
}
