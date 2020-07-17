/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_wstrs_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 23:51:36 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/21 23:51:41 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

short				wstrs_output(struct s_gen *a, wchar_t *frm, size_t len, \
	t_wstr *prms)
{
	unsigned long	split;

	prms->j = 0;
	prms->bts_used_num = 0;
	if (a->m.dot && a->m.f_prc < len)
	{
		while (prms->bts_used_num <= a->m.f_prc)
		{
			prms->bts_used_num = prms->bts_used_num + \
			find_bytes_used(frm[prms->j]);
			prms->j++;
		}
		split = prms->bts_used_num - find_bytes_used(frm[prms->j - 1]);
		prms->bts_used_num = 0;
		prms->j = 0;
		while (prms->bts_used_num < split)
		{
			chars_display(a, frm[prms->j]);
			prms->bts_used_num += find_bytes_used(frm[prms->j++]);
		}
	}
	else
		while (frm[prms->j] != 0)
			chars_display(a, frm[prms->j++]);
	return (0);
}

void				get_wstr_params(struct s_gen *a, t_wstr *prms, wchar_t *f)
{
	wchar_t			*display_null;

	display_null = L"(null)";
	if (f == NULL)
	{
		prms->ln = 6;
		f = display_null;
	}
	else
		while (f[prms->j] != 0)
			prms->bts_used_num += find_bytes_used(f[prms->j++]);
	prms->ln = get_wide_string_ln(f, prms);
	if (a->m.f_zr)
		prms->fil_chr = '0';
	else
		prms->fil_chr = ' ';
	if (a->m.dot && a->m.f_prc < prms->ln)
	{
		prms->min_length = prepare_wstrs_handler(a, f, prms);
	}
	else
		prms->min_length = prms->ln;
}

short int			wstrs_display(struct s_gen *a, wchar_t *frm)
{
	t_wstr			prms;
	wchar_t			*display_null;

	display_null = L"(null)";
	ft_memset(&prms, 0, sizeof(prms));
	get_wstr_params(a, &prms, frm);
	prms.ln = get_wide_string_ln(frm, &prms);
	if (frm == NULL)
		frm = display_null;
	while (!a->m.f_mns && a->m.f_ln && a->m.f_ln > prms.min_length)
	{
		load_symbol(a, prms.fil_chr);
		a->m.f_ln--;
	}
	wstrs_output(a, frm, prms.ln, &prms);
	while (a->m.f_mns && a->m.f_ln && a->m.f_ln > prms.min_length)
	{
		load_symbol(a, ' ');
		a->m.f_ln--;
	}
	return (0);
}
