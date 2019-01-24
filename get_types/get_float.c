/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:12:13 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/24 19:04:31 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*get_float(double arg, unsigned int precision)
{
	double a = (const double )arg;
	return (get_double(a, precision));
}