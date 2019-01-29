/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:39:49 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/29 20:20:05 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	symtohex(unsigned long long c, char *hex, unsigned int size)
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

char		*ulltohex(unsigned long long value)
{
	char		*ret;
	char		*temp;
	const int	size = 32;
	int			i;

	CH_NULL(temp = ft_strnew(size));
	symtohex(value, temp, size);
	i = 0;
	while (temp[i] == '0' && i < size - 1)
		i++;
	ret = ft_strdup(temp + i);
	ft_strdel(&temp);
	return (ret);
}
