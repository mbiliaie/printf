/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_wstrs_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 23:20:36 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/21 23:20:40 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned long	get_wide_string_ln(wchar_t *frm, t_wstr *prms)
{
	unsigned long int result;

	if (frm != NULL)
	{
		prms->j = 0;
		prms->bts_used_num = 0;
		while (frm[prms->j] != 0)
		{
			prms->bts_used_num += find_bytes_used(frm[prms->j]);
			prms->j++;
		}
		result = prms->bts_used_num;
	}
	else
		result = 6;
	return (result);
}

unsigned long	prepare_wstrs_handler(struct s_gen *a, wchar_t *f, t_wstr *prms)
{
	unsigned long int result;

	prms->j = 0;
	prms->bts_used_num = 0;
	while (a->m.f_prc >= prms->bts_used_num)
	{
		prms->bts_used_num = prms->bts_used_num + find_bytes_used(f[prms->j]);
		prms->j = prms->j + 1;
	}
	prms->bts_used_num = prms->bts_used_num - find_bytes_used(f[prms->j - 1]);
	result = prms->bts_used_num;
	return (result);
}
