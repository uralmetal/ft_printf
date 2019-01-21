/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltohex_upper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:54:26 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/21 15:54:37 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	symtohex_upper(unsigned long long c, char *hex, unsigned int size)
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
			hex[count--] = 'A' + value - 10;
		else
			hex[count--] = '0' + value;
	}
}

char	*ulltohex_upper(unsigned long long value)
{
	char *ret;
	const int size = 32;
	int i;

	CH_NULL(ret = ft_strnew(size));
	symtohex_upper(value, ret, size);
	i = 0;
	while (ret[i] == '0' && i < size - 1)
		i++;
	return (ret + i);
}