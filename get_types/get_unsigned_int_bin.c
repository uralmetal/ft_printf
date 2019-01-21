/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_int_bin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:12:57 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/21 16:13:40 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*get_unsigned_int_bin(const void *arg)
{
	const unsigned int *value = arg;

	return (ulltobin(*value));
}