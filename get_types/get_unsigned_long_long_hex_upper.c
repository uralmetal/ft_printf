/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_long_long_hex_upper.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:23:47 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/21 16:23:47 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*get_unsigned_long_long_hex_upper(const void *arg)
{
	const unsigned long long *value = arg;

	return (ulltohex_upper(*value));
}