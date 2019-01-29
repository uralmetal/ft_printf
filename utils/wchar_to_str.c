/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 09:20:52 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/29 09:22:18 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char*	wchar_to_str(int sym)
{
	int mask;
	char *ret;
	int size;

	size = 1;
	if (sym < 0xFF)
		mask = sym;
	else if (sym < 0xFFF)
	{
		mask = 0xC080;
		mask |= sym & 0x3F;
		mask |= (sym & 0x7C0) << 2;
		size = 2;
	}
	else if (sym < 0xFFFF)
	{
		mask = 0xE08080;
		mask |= sym & 0x3F;
		mask |= (sym & 0xFC0) << 2;
		mask |= (sym & 0xF000) << 4;
		size = 3;
	}
	else if (sym < 0xFFFFF)
	{
		mask = 0xF0808080;
		mask |= sym & 0x3F;
		mask |= (sym & 0xFC0) << 2;
		mask |= (sym & 0x1F000) << 4;
		mask |= (sym & 0x3C0000) << 6;
		size = 4;
	}
	ret = ft_strnew(size--);
	while (size >= 0)
	{
		ret[size--] = (char) mask;
		mask >>= 8;
	}
	return (ret);
}
