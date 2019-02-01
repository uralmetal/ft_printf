/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:01:34 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/31 18:31:09 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int flags_width(t_print *mod, char *new_output, char **output, int i)
{
	int f;
	size_t len;

	f = 0;
	if ((len = ft_strlen(*output)) >= (size_t )mod->width)
		return (0);
	while (mod->flag[++i])
		if (mod->flag[i] == '-')
		{
			ft_memset(new_output, ' ', (size_t)mod->width);
			if (mod->type == 0 || mod->type == 54)
				len = 1;
			ft_memcpy(new_output, *output, len);
			f++;
		}
		else if (mod->flag[i] == '0')
		{
			if (mod->precision == -1 &&
			(mod->type == 3 || mod->type == 0 || mod->type != 54 ||
			(mod->type >= 4 && mod->type <= 9) ||
			(mod->type >= 12 && mod->type <= 23) ||
			(mod->type >= 25 && mod->type <= 36)))
			{
				ft_memset(new_output, '0', (size_t) mod->width);
				ft_memcpy(&(new_output[mod->width - len]), *output, len);
				f++;
			}
		}
	if (f == 0)
	{
		ft_memset(new_output, ' ', (size_t)mod->width);
		if (mod->type == 0 || mod->type == 54)
			len = 1;
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
		if (mod->flag[i] == ' ' || mod->flag[i] == '+' || ft_strchr(output,
				'-') != NULL)
		{
			if (*output != ' ' && *output != '0' && *output != '-' &&
					len < (size_t) mod->width)
			{
				ft_memmove(output + 1, output, len);
				mod->flag[i] == '+' ? (output[0] = '+') : (output[0] = ' ');
			}
			if ((len > (size_t)mod->width && *output != '-') &&
			(mod->type != 7 && mod->type != 15 && mod->type != 21
			&& mod->type != 28 && mod->type != 34))
				mod->flag[i] == ' ' ? ft_putstr_full(" ") : ft_putstr_full("+");
			if (len < (size_t) mod->width)
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
			}
				else if ((mod->type == 3 || mod->type == 0 || mod->type != 54 ||
						(mod->type >= 4 && mod->type <= 9) ||
						(mod->type >= 12 && mod->type <= 23) ||
						(mod->type >= 25 && mod->type <= 36)) &&
						(mod->type != 7 && mod->type != 15 && mod->type != 21
						&& mod->type != 28 && mod->type != 34))
				{
					if (*output == '0' && ft_strnchr(output, ' ') > 0)
					{
						ft_memmove(output + 1, output,
								   ft_strlen(output) - ft_strnchr(output, ' '));
						mod->flag[i] == '+' ? (*output = '+') : (*output = ' ');
					}
					else
						if (*output == '0' && ft_strnchr(output, '0') != 1)
							mod->flag[i] == '+' ?
							(*output = '+') : (*output = ' ');
						else if (*output == ' ')
						{
							j = 0;
							while (output[j] == ' ')
								j++;
							mod->flag[i] == '+' ? (output[j - 1] = '+') :
									(*(output) = ' ');
						}
				}

			break ;
		}
// 7, 15, 21, 28, 34,
}

static int make_width(char **output, t_print *mod)
{
	int i;
	char *new_output;

	if (ft_strlen(*output) >= (size_t)mod->width)
		return (0);
	if ((new_output = ft_strnew((size_t )mod->width)) == NULL)
		return (0);
	i = -1;
	flags_width(mod, new_output, output, i);
	if (mod->type >= 3 && mod->type != 4 && mod->type != 6 && mod->type != 8 &&
			mod->type != 9 && mod->type != 14 && mod->type != 16 && mod->type != 17 &&
			mod->type != 20 && mod->type != 22 && mod->type != 23 && mod->type != 27 &&
			mod->type != 29 && mod->type != 30 && mod->type != 33 && mod->type != 35 &&
			mod->type != 36 && mod->type <= 52)
		flags_space_plus(new_output, mod, ft_strlen(*output));
	ft_strdel(output);
	*output = new_output;
	return (1);
}

static int make_precision(char **output, t_print *mod)
{
	char *new_output;
	size_t len;
	char *minus;

	if (mod->precision < 0)
		return (0);
	if (mod->type == 0 || mod->type == 54)
	{
		mod->precision = -1;
		return (0);
	}
	if (mod->type == 1 || mod->type == 52)
	{
		if ((new_output = ft_strnew((size_t)mod->precision)) == 0)
			return (0);
		ft_strncpy(new_output, *output, (size_t)mod->precision);
	}
	else
	{
		len = ft_strlen(*output);
		if (**output == '0' && mod->precision == 0)
			if (ft_strnchr(*output, '0') == 1)
			{
				if (mod->width <= 0)
					ft_strchr(*output, '0')[0] = '\0';
				else
					ft_strchr(*output, '0')[0] = ' ';
			}
		if  ((size_t)mod->precision < len)
			return (0);
		if (ft_strchr(*output, '-') != NULL)
			mod->precision += 1;
		if ((new_output = ft_strnew((size_t)mod->precision)) == 0)
			return (0);
		ft_memset(new_output, '0', (size_t)mod->precision);
		ft_strcpy(new_output + (mod->precision - len), *output);
		if ((minus = ft_strchr(new_output, '-')) != NULL)
		{
			*minus = '0';
			new_output[0] = '-';
		}
	}
	ft_strdel(output);
	*output = new_output;
	return (1);
}

static int	make_octotorp(char **output, t_print *mod)
{
	char *new_output;
	int type;
	int k;
	size_t  len;

	type = mod->type;
	k = 0;
	len = 0;
	if (type == 6 || type == 14 || type == 20 || type == 27 || type == 33)
	{
		new_output = *output;
		while ((*new_output == ' ' || *new_output == '0') && *new_output)
			new_output++;
		while (*new_output != ' ' && *new_output)
		{
			new_output++;
			len++;
		}
		if (len < ft_strlen(*output))
		{
			if (**output == ' ')
				*(new_output - len - 1) = '0';
			else
			{
				ft_memmove(*output + 1, *(output), len);
				**output = '0';
			}
			new_output = *output;
		}
		else
			new_output = ft_strcat(ft_strcpy(ft_strnew(
				ft_strlen(*output) + 1), "0"), *output);
	}
	else if (type == 8 || type == 9 || type == 16 || type == 17 || type == 22
			|| type == 23 || type == 29 || type == 30 || type == 36 ||
			type == 35 || (type >= 56 && type <= 58) ||
			(type >= 59 && type <= 61))
	{
		new_output = *output;
		while ((*new_output == ' ' || *new_output == '0') && *new_output)
		{
			if (*new_output == '0')
				k++;
			new_output++;
		}
		len = ft_strlen(new_output);
		if (*new_output != '\0' && k < 2)
		{
			if (len + 1 == (size_t)mod->width)
			{
				if (type == 9 || type == 17 || type == 23 || type == 30 ||
						type == 36 || (type >= 59 && type <= 61))
					new_output = ft_strcat(ft_strcpy(ft_strnew(
							ft_strlen(*output) + 2), "0X"), *output);
				else
					new_output = ft_strcat(ft_strcpy(ft_strnew(
							ft_strlen(*output) + 2), "0x"), *output);

				new_output = ft_strcat(ft_strcpy(ft_strnew(len + 2), "0x"),
									   new_output);
			}
			else if (len > (size_t)mod->width)
			{
				if (type == 9 || type == 17 || type == 23 || type == 30 ||
				type == 36 || (type >= 59 && type <= 61))
					new_output = ft_strcat(ft_strcpy(ft_strnew(
							ft_strlen(*output) + 2), "0X"), *output);
				else
					new_output = ft_strcat(ft_strcpy(ft_strnew(
							ft_strlen(*output) + 2), "0x"), *output);
			}
			else if (new_output == *output && len == (size_t)mod->width)
			{
				if (new_output[len - 1] == ' ' && new_output[len - 2] == ' ')
				{
					ft_memmove(*output + 2, *output, len - 2);
					new_output[0] = '0';
					if (type == 9 || type == 17 || type == 23 || type == 30 || type == 36
							|| (type >= 59 && type <= 61))
						new_output[1] = 'X';
					else
						new_output[1] = 'x';
				}
			}
			else
			{
				*(new_output - 2) = '0';
				if (type == 9 || type == 17 || type == 23 || type == 30 ||
						type == 36 || (type >= 59 && type <= 61))
					*(new_output - 1) = 'X';
				else
					*(new_output - 1) = 'x';
				new_output = *output;
			}
		}
		else if (k > 2 && *new_output != '\0')
		{
			new_output = ft_strchr(*output, '0');
			*(new_output + 1) = 'x';
			new_output = *output;
		}
		else
			new_output = *output;
	}
//	else if (type == 9 || type == 17 || type == 23 || type == 30 || type == 36
//	|| (type >= 59 && type <= 61))
//	{
//		new_output = ft_strcat(ft_strcpy(ft_strnew(ft_strlen(*output) + 2),
//					"0X"), *output);
//	}
	else if (mod->precision == 0 && (type == 10 || type == 11 || type == 24 ||
	type == 37 || type == 38 || type == 39 || type == 40 || type == 41 ||
	type == 42 || type == 43 || type == 45 || type == 46 || type == 48 ||
	type == 49 || type == 51))
	{
		CH_NULL(new_output = ft_strcpy(ft_strnew(ft_strlen(*output) + 1),
				*output));
		new_output[ft_strlen(*output)] = '.';
	}
	else
		return (1);
	if (*output != new_output)
		ft_strdel(output);
	if ((*output = new_output) == NULL)
		return (0);
	return (1);
}

static int add_flags(char **output, t_print *mod)
{
//	char flgs[][3] = {"-", "+", "-+", "- ", "+0", " ", " 0", "0", "+#",
//				   " #", "#", "0#", "'", " '", "-'", "+'", "-+'", "- '",
//				   "0'", " 0'", "+0'", "+#'", " #'", "#'", ""};
//	int i;
//
//	i = -1;
//	while (++i < (sizeof(flgs) / sizeof(flgs[0])))
//		if (ft_strcmp(mod->flag, flgs[i]) == 0)
//			break ;
//	if (i == (sizeof(flgs) / sizeof(flgs[0])))
//		return (0);
	if (mod->type != 2 && mod->type != 4 && mod->type != 10 &&
		mod->type != 11 && mod->type != 24 &&
		!(mod->type >= 37 && mod->type <= 42) &&
		!(mod->type >= 55 && mod->type <= 61))
		make_precision(output, mod);
//	if (mod->width != 0)
		make_width(output, mod);
	if (ft_strchr(mod->flag, '#') != NULL)
		make_octotorp(output, mod);
	else if (mod->type != 4)
		flags_space_plus(*output, mod, ft_strlen(*output));
	return (1);
}

void	put_thousands_sep(char *output)
{
	int i;
	int j;
	int k;

	i = -1;
	while ((output[++i] == ' ' || output[i] == '0' || output[i] == '+' ||
	output[i] == '-') && output[i] != '\0')
		ft_putnstr_full(output + i, 1);
	j = i;
	while (output[i] != '\0' && output[i] != '.' && output[i] != ' ')
		i++;
	k = ((i - j - 1) % 3) + 1;
		while (output[j] && j != i)
		{
			ft_putnstr_full(output + j, 1);
			if (j++ + 1 == i)
				break ;
			if (--k <= 0)
			{
				ft_putstr_full(",");
				k = 3;
			}
		}
	ft_putstr_full(output + j);
}

int print(t_print *mod, const void *arg, double var_d, long double var_dd)
{
	get_output function_get;
	char *output;


	if ((function_get = get_function(mod)) == NULL)
	{
		printf("\nПока нет такой функции, напиши ее, заебал <3\n");
		return (0);
	}
	if (mod->type == 10 || mod->type == 11 ||mod->type == 24 || mod->type == 37
	|| mod->type == 38 || mod->type == 39 || mod->type == 40 || mod->type == 41
	|| mod->type == 42 || mod->type == 43 || mod->type == 45 || mod->type == 46
	|| mod->type == 48 || mod->type == 49 || mod->type == 51)
		if (mod->precision == -1)
			if (var_d != 0)
				output = function_get(var_d, 6);
			else
				output = function_get(var_dd, 6);
		else
			if (var_d != 0)
				output = function_get(var_d, mod->precision);
			else
				output = function_get(var_dd, mod->precision);
	else
		output = function_get(arg);
	if (add_flags(&output, mod) == 0)
	{
		ft_strdel(&output);
		return (0);
	}
	if (ft_strchr(mod->flag, 39) != NULL && (mod->type == 3 || mod->type == 7 ||
	mod->type == 10 || mod->type == 11 || mod->type == 12 || mod->type == 15 ||
	mod->type == 18 || mod->type == 21 || mod->type == 24 || mod->type == 25 ||
	mod->type == 28 || mod->type == 31 || mod->type == 34 || mod->type == 38 ||
	mod->type == 40 || (mod->type >= 42 && mod->type <= 48)))
		put_thousands_sep(output);
	else if ((mod->type == 0 || mod->type == 54) /*&& (ft_strlen(output) == 0 ||
	ft_strlen(output) == 1)*/)
	{
		if (mod->width == 0 || mod->width == -1)
			mod->width = 1;
		ft_putnstr_full(output, (size_t)mod->width);
//		g_output_symbols++;
	}
	else
		ft_putstr_full(output);
	ft_strdel(&output);
	return (1);
}
