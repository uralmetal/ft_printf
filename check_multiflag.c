/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_multiflag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:01:22 by rwalder-          #+#    #+#             */
/*   Updated: 2019/02/03 13:07:46 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char g_int_flags[][3] = {
	"hh",
	"h",
	"z",
	"j",
	"l",
	"ll",
};

static char g_char_flags[][3] = {
	"l",
};

static char g_float_flags[][3] = {
	"l",
	"L"
};

static int compare(char sym1_1, char sym1_2, char sym2_1, char sym2_2)
{
	if (sym1_2 && sym2_2)
	{
		if (sym1_1 == sym2_1 && sym1_2 == sym2_2)
			return (1);
		else
			return (0);
	}
	else if (sym1_1 == sym2_1 && sym1_2 == 0)
		return (1);
	return (0);
}

static char	*check_multiflag_int(char *flag, int size, char mass[][3], int len)
{
	char		*ret;
	int			i;
	int			j;
	int 		index;

	ret = ft_strdup("");
	i = 0;
	index = -1;
	while (i < size)
	{
		j = 0;
		while (j < len)
		{
			if (compare(mass[j][0], mass[j][1], flag[i], ((i + 1)
			<size) ? (flag[i + 1]) : (0)) == 1)
			{
				if (j > index)
				{
					index = j;
					if (j == 0 || j == 5)
					{
						i++;
						break;
					}
				}
			}
			j++;
		}
		i++;
	}
	if (index != -1)
	{
		ft_strdel(&ret);
		ret = ft_strdup(mass[index]);
	}
	return (ret);
}
//"cspi%douxXfegGFSCaAnDOUbkr"
static const char *g_type_int = "idouxXDOUb";
static const char *g_type_char = "csSCp";
static const char *g_type_float = "egfaEGFA";

char	*check_multiflag(char *flag, int size, char type)
{
	char *ret;
	int len;

	ret = ft_strdup("");
	if (ft_strchr(g_type_int, type) != NULL)
	{
		ft_strdel(&ret);
		len = sizeof(g_int_flags) / sizeof(g_int_flags[0]);
		ret = check_multiflag_int(flag, size, g_int_flags, len);
	}
	else if (ft_strchr(g_type_char, type) != NULL)
	{
		ft_strdel(&ret);
		len = sizeof(g_char_flags) / sizeof(g_char_flags[0]);
		ret = check_multiflag_int(flag, size, g_char_flags, len);
	}

	else if (ft_strchr(g_type_float, type) != NULL)
	{
		ft_strdel(&ret);
		len = sizeof(g_float_flags) / sizeof(g_float_flags[0]);
		ret = check_multiflag_int(flag, size, g_float_flags, len);
	}
	return (ret);
}
