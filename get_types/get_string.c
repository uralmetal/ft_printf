/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:35:08 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/26 14:03:05 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*get_string(const void *arg)
{
	const char **s = (const char **)arg;
	return (ft_strdup(*s));
}
