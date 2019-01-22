/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_date.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:25:06 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/22 13:25:19 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static const int g_mon_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char	*get_year(time_t *sec, int *year)
{
	*year = 1970;
	if (*sec > 0)
	{
		while (*sec >= DAY_TO_SEC(366))
		{
			if (LEAP_YEAR(*year))
				*sec -= DAY_TO_SEC(366);
			else
				*sec -= DAY_TO_SEC(365);
			*year = *year + 1;
		}
		if (*sec >= DAY_TO_SEC(365))
		{
			*sec -= DAY_TO_SEC(365);
			*year = *year + 1;
		}
	}
	return (ft_lltoa(*year));
}

static char *get_month(time_t *sec, int *year)
{
	int month;
	char *ret;
	char *temp;

	month = 0;
	while (*sec >= DAY_TO_SEC(31))
	{
		if ((month == 1) && (LEAP_YEAR(*year)))
			*sec -= DAY_TO_SEC(g_mon_day[month++] + 1);
		else
			*sec -= DAY_TO_SEC(g_mon_day[month++]);
	}
	if (*sec >= DAY_TO_SEC(g_mon_day[month]))
		*sec -= DAY_TO_SEC(g_mon_day[month++]);
	month++;
	ret = ft_lltoa(month);
	if (ft_strlen(ret) == 1)
	{
		temp = ft_strjoin("0", ret);
		ft_strdel(&ret);
		ret = temp;
	}
	return (ret);
}

static char *get_day(time_t *sec)
{
	long days;
	char *ret;
	char *temp;

	days = (*sec / (60 * 60 * 24)) + 1;
	ret = ft_lltoa(days);
	if (ft_strlen(ret) == 1)
	{
		temp = ft_strjoin("0", ret);
		ft_strdel(&ret);
		ret = temp;
	}
	return (ret);
}

char	*get_date(const void *arg)
{
	time_t sec = *((time_t*)arg);
	int year;
	char *ret;
	char *join;
	char *temp;

	temp = get_year(&sec, &year);
	ret = ft_strdup("");
	join = ft_strjoin(ret, temp);
	ft_strdel(&ret);
	ft_strdel(&temp);
	ret = join;
	temp = get_month(&sec, &year);
	join = ft_strjoin(ret, temp);
	ft_strdel(&ret);
	ft_strdel(&temp);
	ret = join;
	temp = get_day(&sec);
	join = ft_strjoin(ret, temp);
	ft_strdel(&ret);
	ft_strdel(&temp);
	return (join);
}