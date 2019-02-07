/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double_g_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:36:44 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/05 15:26:10 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*get_double_g_upper(double arg, unsigned int precision)
{
	char *ret;

	if ((ret = get_const_double_upper(arg)) != NULL)
		return (ret);
	if (is_exp(arg, precision))
		ret = handle_exp_upper(arg, precision);
	else
		ret = handle_float(arg, precision);
	return (ret);
}
