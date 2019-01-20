/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:01:34 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/20 19:06:50 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void flags_width(t_print mod, char *new_output, char **output, int i)
{
	int f;
	size_t len;

	f = 0;
	if ((len = ft_strlen(*output)) >= mod.width)
		return ;
	while (mod.flag[++i])
		if (mod.flag[i] == '-')
		{
			ft_memset(new_output, ' ', (size_t)mod.width);
			ft_memcpy(new_output, *output, len);
			f++;
		}
		else if (mod.flag[i] == '0')
		{
			ft_memset(new_output, '0', (size_t)mod.width);
			ft_memcpy(&(new_output[mod.width - len]), *output, len);
			f++;
		}
	if (f == 0)
	{
		ft_memset(new_output, ' ', (size_t)mod.width);
		ft_memcpy(&(new_output[mod.width - len]), *output, len);
	}
}

//static void flags_space_plus(char *output, t_print mod)
//{
//	int i;
//
//	if (mod.type < 3)
//		return ;
//	i = -1;
//	while (mod.flag[++i])
//		if (mod.flag[i] == ' ')
//		{
//			ft_memmove(*output);
//		}
//		else if (mod.flag[i] == '+')
//		{
//		}
//}

static int make_width(char **output, t_print mod)
{
	int i;
	char *new_output;

	if ((new_output = ft_strnew(mod.width)) == NULL)
		return (0);
	i = -1;
	flags_width(mod, new_output, output, i);
//	flags_space_plus(*output, mod);
	ft_strdel(output);
	*output = new_output;
	return (1);
}

static int add_flags(char **output, t_print modif)
{
	char flgs[][3] = {"-", "-+", "- ", "+0", " ", " 0", "0", "+#", " #", "#",
				   ""};
	int i;

	i = -1;
	while (++i < 11)
		if (ft_strcmp(modif.flag, flgs[i]) == 0)
			break ;
	if (i == 11)
		return (0);
	if (modif.width != 0)
		make_width(output, modif);

	return (1);
}

int print(t_print modif, const void *arg)
{
	get_output function_get;
	char *output;


//	printf("flag = [%s]\nwidth = [%d]\nprecision = [%d]\ntype = [%s]\n",
//		   modif.flag, modif.width, modif.precision, modif.type);
	if ((function_get = get_function(modif)) == NULL)
	{
		printf("Пока нет такой функции, напиши ее, заебал <3");
		return (0);
	}
	output = function_get(arg);
	if (add_flags(&output, modif) == 0)
	{
		ft_strdel(&output);
		return (0);
	}
	ft_putstr(output);
	ft_strdel(&output);
	return (1);
}
