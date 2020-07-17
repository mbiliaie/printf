/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utab_atoi_extd_convert.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 23:41:10 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/21 23:41:17 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

short int				convert_uabs(struct s_gen *a, short num_sys, t_int *d)
{
	unsigned long int	v_tmp;
	short int			k;
	char				x_a;

	v_tmp = d->u_arg_val;
	k = 1;
	if (!v_tmp)
		*d->sv = '0';
	if (a->m.xb_conv == 0)
		x_a = 97;
	else
		x_a = 65;
	while (v_tmp /= num_sys)
		k += 1;
	v_tmp = d->u_arg_val;
	while (v_tmp > 0)
	{
		k -= 1;
		if (v_tmp % num_sys < 10)
			d->sv[k] = v_tmp % num_sys + '0';
		else
			d->sv[k] = v_tmp % num_sys - 10 + x_a;
		v_tmp = v_tmp / num_sys;
	}
	return (0);
}

static short int		ft_lim_mm(unsigned long long num, char c, int m)
{
	if (m < 0 && num >= 922337203685477580 && c >= 56)
		return (0);
	if (m == 0 && num >= 1844674407370955161 && c >= 53)
		return (-1);
	else
		return (1);
}

long long int			atoi_extd(const char *frm)
{
	int					i;
	unsigned long long	num;
	int					m;

	i = 0;
	num = 0;
	m = 0;
	while (ft_isspace(frm[i]) && frm[i] != '\0')
		i++;
	if (frm[i] == '-' || frm[i] == '+')
	{
		if (frm[i] == '-')
			m--;
		i++;
	}
	while (ft_isdigit(frm[i]) && frm[i])
	{
		if (ft_lim_mm(num, frm[i], m) == 0 || ft_lim_mm(num, frm[i], m) == -1)
			return (ft_lim_mm(num, frm[i], m));
		num = num * 10 + frm[i] - '0';
		i++;
	}
	if (m < 0)
		return (-num);
	return (num);
}
