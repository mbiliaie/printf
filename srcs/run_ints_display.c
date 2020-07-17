/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ints_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 23:27:18 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/21 23:27:22 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static short int	enable_mods(struct s_gen *a_start, t_int *d)
{
	if (CFL == 'o' && a_start->m.f_hsh && *d->sv && *d->sv != '0' \
		&& a_start->m.f_prc <= d->ln_arg)
	{
		load_symbol(a_start, '0');
	}
	else if (CFL == 'i' || CFL == 'd')
	{
		if (a_start->m.bzr)
			load_symbol(a_start, '-');
		else if (a_start->m.f_pls && !a_start->m.bzr)
			load_symbol(a_start, '+');
		else if (a_start->m.f_spc)
			load_symbol(a_start, ' ');
	}
	else if (CFL == 'p' || (CFL == 'x' && a_start->m.f_hsh && *d->sv \
		&& *d->sv != '0'))
	{
		load_symbol(a_start, '0');
		if (a_start->m.xb_conv == 0)
			load_symbol(a_start, 'x');
		else
			load_symbol(a_start, 'X');
	}
	return (0);
}

ssize_t				get_s_arg_val(struct s_gen *a_start)
{
	ssize_t		s_arg_val;

	if (a_start->m.j)
		s_arg_val = va_arg(a_start->ap, intmax_t);
	else if (a_start->m.z)
		s_arg_val = va_arg(a_start->ap, ssize_t);
	else if (a_start->m.l || a_start->m.l2)
	{
		if (a_start->m.l)
			s_arg_val = va_arg(a_start->ap, long int);
		else
			s_arg_val = va_arg(a_start->ap, long long int);
	}
	else if (a_start->m.h2)
		s_arg_val = (char)va_arg(a_start->ap, int);
	else if (a_start->m.h)
		s_arg_val = (short int)va_arg(a_start->ap, int);
	else
		s_arg_val = va_arg(a_start->ap, int);
	return (s_arg_val);
}

unsigned long int	get_u_arg_val(struct s_gen *a_start)
{
	size_t u_arg_val;

	if (a_start->m.z)
		u_arg_val = va_arg(a_start->ap, size_t);
	else if (a_start->m.l2 || a_start->m.l)
	{
		if (a_start->m.l)
			return (va_arg(a_start->ap, unsigned long int));
		else
			return (va_arg(a_start->ap, unsigned long long int));
	}
	else if (a_start->m.h || a_start->m.h2)
	{
		if (a_start->m.h2)
			return ((unsigned char)va_arg(a_start->ap, unsigned int));
		else
			return ((unsigned short)va_arg(a_start->ap, unsigned int));
	}
	else if (a_start->m.j)
		u_arg_val = va_arg(a_start->ap, uintmax_t);
	else
		u_arg_val = va_arg(a_start->ap, unsigned int);
	return (u_arg_val);
}

short int			ints_flag_combiner(struct s_gen *a_start, t_int *d)
{
	if (a_start->m.f_ln > d->ln_m && a_start->m.f_zr)
	{
		enable_mods(a_start, d);
		d->fl_presence = 0;
	}
	else
		d->fl_presence = 1;
	while (!a_start->m.f_mns && a_start->m.f_ln-- > d->ln_m)
		load_symbol(a_start, d->fil_chr);
	if (d->fl_presence)
		enable_mods(a_start, d);
	while (a_start->m.f_prc && a_start->m.f_prc > d->ln_arg)
	{
		a_start->m.f_prc = a_start->m.f_prc - 1;
		load_symbol(a_start, '0');
	}
	while (d->sv[d->i])
		load_symbol(a_start, d->sv[d->i++]);
	while (a_start->m.f_mns && a_start->m.f_ln > d->ln_m)
	{
		a_start->m.f_ln = a_start->m.f_ln - 1;
		load_symbol(a_start, ' ');
	}
	return (0);
}
