/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_strs_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 23:13:57 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/21 23:14:01 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char				*get_str_params(struct s_gen *a, char *frm, t_str *prms)
{
	if (frm != NULL)
	{
		prms->s = frm;
		prms->ln = ft_strlen(frm);
	}
	else
	{
		prms->display_null = "(null)";
		prms->s = prms->display_null;
		prms->ln = ft_strlen(prms->s);
	}
	if (a->m.dot && a->m.f_prc <= prms->ln)
		prms->min_length = a->m.f_prc;
	else
		prms->min_length = prms->ln;
	if (a->m.f_zr == 1)
		prms->fil_chr = '0';
	else
		prms->fil_chr = ' ';
	return (prms->s);
}

static short			output_flags_str(struct s_gen *a_start, char *frm)
{
	t_str				prms;
	size_t				given_m_ln;

	frm = get_str_params(a_start, frm, &prms);
	given_m_ln = a_start->m.f_ln;
	while (!a_start->m.f_mns && given_m_ln && given_m_ln > prms.min_length)
	{
		load_symbol(a_start, prms.fil_chr);
		given_m_ln--;
	}
	strs_output(a_start, frm, prms.ln);
	while (a_start->m.f_mns && given_m_ln && given_m_ln > prms.min_length)
	{
		load_symbol(a_start, ' ');
		given_m_ln--;
	}
	return (0);
}

void					prepare_str_handler(struct s_gen *a_start)
{
	wchar_t				*wstr;
	char				*str;
	short				check_l_flags;

	if (!a_start->m.l && !a_start->m.l2)
		check_l_flags = 0;
	else
		check_l_flags = 1;
	if (check_l_flags == 0)
	{
		str = va_arg(a_start->ap, char*);
		output_flags_str(a_start, str);
	}
	else
	{
		wstr = va_arg(a_start->ap, wchar_t*);
		wstrs_display(a_start, wstr);
	}
}
