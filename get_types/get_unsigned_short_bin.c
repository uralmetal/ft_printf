/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_short_bin.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:34:06 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/21 17:34:06 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*get_unsigned_short_bin(const void *arg)
{
	const unsigned short *value = arg;

	return (ulltobin(*value));
}