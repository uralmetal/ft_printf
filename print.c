/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:01:34 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/22 18:56:27 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int flags_width(t_print *mod, char *new_output, char **output, int i)
{
	int f;
	size_t len;

	f = 0;
	if ((len = ft_strlen(*output)) >= mod->width)
		return (0);
	while (mod->flag[++i])
		if (mod->flag[i] == '-')
		{
			ft_memset(new_output, ' ', (size_t)mod->width);
			ft_memcpy(new_output, *output, len);
			f++;
		}
		else if (mod->flag[i] == '0')
		{
			ft_memset(new_output, '0', (size_t)mod->width);
			ft_memcpy(&(new_output[mod->width - len]), *output, len);
			f++;
		}
	if (f == 0)
	{
		ft_memset(new_output, ' ', (size_t)mod->width);
		ft_memcpy(&(new_output[mod->width - len]), *output, len);
	}
	return (1);
}

static void flags_space_plus(char *output, t_print *mod, size_t len)
{
	int i;
	int j;

	if (mod->type < 3)
		return ;
	i = -1;
	while (mod->flag[++i])
		if (mod->flag[i] == ' ' || mod->flag[i] == '+')
		{
			if (*output != ' ' && *output != '0' && *output != '-' &&
			len < mod->width)
			{
				ft_memmove(output + 1, output, len);
				mod->flag[i] == '+' ? (output[0] = '+') : (output[0] = ' ');
			}
			if (len >= mod->width && *output != '-')
				mod->flag[i] == ' ' ? ft_putchar(' ') : ft_putchar('+');
			if (len < mod->width)
			{
				j = 0;
				while (output[j] != '\0' && (output[j] == '0' ||
				output[j] == ' '))
					j++;
				if (output[j] == '-')
				{
					if (*output == '0')
					{
						output[j] = output[j - 1];
						*output = '-';
					}
				}
				else if (*output == '0')
					mod->flag[i] == '+' ? (*output = '+') : (*output = ' ');
				else if (*output == ' ')
					mod->flag[i] == '+' ? (output[j - 1] = '+') :
					(*output =' ');
			}
			break ;
		}
}

static int make_width(char **output, t_print *mod)
{
	int i;
	char *new_output;

	if (ft_strlen(*output) >= mod->width)
		return (0);
	if ((new_output = ft_strnew(mod->width)) == NULL)
		return (0);
	i = -1;
	flags_width(mod, new_output, output, i);
	flags_space_plus(new_output, mod, ft_strlen(*output));
	ft_strdel(output);
	*output = new_output;
	return (1);
}

static int make_precision(char **output, t_print *mod)
{
	char *new_output;
	if (mod->precision < 0)
		return (0);
	if ((new_output = ft_strnew(mod->precision)) == 0)
		return (0);
	ft_strncpy(new_output, *output, mod->precision);
	ft_strdel(output);
	*output = new_output;
	return (1);
}

static int add_flags(char **output, t_print *mod)
{
	char flgs[][3] = {"-", "+", "-+", "- ", "+0", " ", " 0", "0", "+#",
				   " #", "#", ""};
	int i;

	i = -1;
	while (++i < (sizeof(flgs) / sizeof(flgs[0])))
		if (ft_strcmp(mod->flag, flgs[i]) == 0)
			break ;
	if (i == (sizeof(flgs) / sizeof(flgs[0])))
		return (0);
	if (mod->type == 1)
		make_precision(output, mod);
	if (mod->width != 0)
		make_width(output, mod);
	else
	{
		flags_space_plus(*output, mod, ft_strlen(*output));
	}
	return (1);
}

int print(t_print *mod, const void *arg)
{
	get_output function_get;
	char *output;


//	printf("flag = [%s]\nwidth = [%d]\nprecision = [%d]\ntype = [%d]\n"
//		"num_arg = [%d]\nwidth_num_arg = [%d]\nprec_num_arg = [%d]\n",
//		mod->flag, mod->width, mod->precision,
//		mod->type, mod->num_arg, mod->width_num_arg, mod->prec_num_arg);

	if ((function_get = get_function(mod)) == NULL)
	{
		printf("Пока нет такой функции, напиши ее, заебал <3");
		return (0);
	}
	output = function_get(arg);
	if (add_flags(&output, mod) == 0)
	{
		ft_strdel(&output);
		return (0);
	}
	ft_putstr_full(output);
	ft_strdel(&output);
	return (1);
}
