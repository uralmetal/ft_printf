/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:38:51 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/16 13:25:07 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	symtohex(unsigned long c, char *hex, unsigned int size)
{
	int value;
	int count;

	count = size - 1;
	while (count >= 0)
		hex[count--] = '0';
	count = size - 1;
	while (c > 0)
	{
		value = c;
		c = c / 16;
		value = value - c * 16;
		if (value >= 10)
			hex[count--] = 'a' + value - 10;
		else
			hex[count--] = '0' + value;
	}
}

void		print_pointer(const void *p)
{
	char		*hex;
	int			i;
	const int	size = 32;

	hex = ft_strnew(size);
	symtohex((unsigned long)p, hex, size);
	while (hex[i] == '0')
		i++;
	print_string("0x");
	print_string(hex + i);
}
