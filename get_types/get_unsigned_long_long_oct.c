/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_long_long_oct.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:04:11 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/21 16:04:11 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*get_unsigned_long_long_oct(const void *arg)
{
	const unsigned long long *value = arg;

	return (ulltooct(*value));
}