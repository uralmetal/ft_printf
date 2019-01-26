/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_full.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:05:12 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/21 15:41:41 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_full(const char *str)
{
	size_t len;

	if (str == NULL)
		return ;
	len = ft_strlen(str);
	g_output_symbols += len;
	write(1, str, len);
}