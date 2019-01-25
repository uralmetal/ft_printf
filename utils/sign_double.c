/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:58:20 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/25 13:44:25 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	sign_double(double val)
{
	long sign;

	sign = (*((long*)&val));
	sign >>= 63;
	return (sign);
}