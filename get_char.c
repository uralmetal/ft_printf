/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:42:25 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/18 16:59:48 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_char(const void *arg)
{
	char *ret;
	const unsigned char *val = arg;

	ret = ft_strnew(1);
	ret[0] = *val;
	return (ret);
}
