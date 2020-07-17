/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_ints_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 23:12:59 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/21 23:13:04 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static short int		ints_display(struct s_gen *a, t_int *d)
{
	if (a->cfl == 'o' && a->m.f_hsh && d->u_arg_val == 0)
		*d->sv = '0';
	else if (a->m.dot && a->m.f_prc == 0 && d->u_arg_val == 0)
		*d->sv = '\0';
	d->ln_arg = ft_strlen(d->sv);
	if (a->cfl == 'o' && *d->sv != '0' && a->m.f_hsh && d->ln_arg >= a->m.f_prc)
		d->ct_fl = 1;
	else if (a->cfl == 'd' || a->cfl == 'i')
	{
		if ((!a->m.bzr && a->m.f_pls) || (a->m.bzr) \
			|| (a->m.f_spc))
			d->ct_fl = 1;
	}
	else if (a->cfl == 'p' || (a->cfl == 'x' && a->m.f_hsh && *(d->sv) != '0'))
		d->ct_fl = 2;
	if (d->ln_arg >= a->m.f_prc)
		d->ln_m = d->ln_arg + d->ct_fl;
	else
		d->ln_m = a->m.f_prc + d->ct_fl;
	if (a->m.f_zr && !a->m.dot)
		d->fil_chr = '0';
	else
		d->fil_chr = ' ';
	ints_flag_combiner(a, d);
	return (0);
}

static void				find_arg_call_conv(struct s_gen *a_start, t_int *d)
{
	if (CFL == 'd' || CFL == 'i' || CFL == 'u')
	{
		convert_uabs(a_start, DEC, d);
	}
	else if (CFL == 'o')
	{
		convert_uabs(a_start, OCT, d);
	}
	else if (CFL == 'p' || CFL == 'x')
	{
		convert_uabs(a_start, HEX, d);
	}
}

void					prepare_int_handler(struct s_gen *a_start)
{
	ssize_t		s_arg_val;
	t_int		d;
	static char	sv[22];

	ft_memset(&sv, 0, 22 * sizeof(char));
	ft_memset(&d, 0, sizeof(d));
	d.sv = sv;
	if (CFL == 'i' || CFL == 'd')
	{
		s_arg_val = get_s_arg_val(a_start);
		if (s_arg_val >= 0)
			d.u_arg_val = s_arg_val;
		else
		{
			a_start->m.bzr = 1;
			d.u_arg_val = -s_arg_val;
		}
	}
	else if (CFL == 'u' || CFL == 'x' || CFL == 'o')
		d.u_arg_val = get_u_arg_val(a_start);
	else
		d.u_arg_val = va_arg(a_start->ap, size_t);
	find_arg_call_conv(a_start, &d);
	ints_display(a_start, &d);
}
