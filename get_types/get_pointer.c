/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:38:51 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/18 16:59:48 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

char		*get_pointer(const void *arg)
{
	char		*hex;
	char 		*ret;
	int			i;
	const int	size = 32;

	hex = ft_strnew(size);
	symtohex((unsigned long)arg, hex, size);
	i = 0;
	while (hex[i] == '0')
		i++;
	ret = ft_strnew(2 + size - i);
	ft_strcat(ret, "0x");
	ft_strcat(ret, hex + i);
	ft_strdel(&hex);
	return (ret);
}
