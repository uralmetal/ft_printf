/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:38:16 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/30 09:31:33 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char *get_long_char(const void *arg)
{
	const int *wstr = arg;

	return (wchar_to_str(*wstr));
}
