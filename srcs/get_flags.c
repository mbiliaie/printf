/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 22:16:13 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/21 22:16:17 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long long		calc_prc_ln(struct s_gen *a, size_t j, const char *frm)
{
	long long int			saver;
	char					tmp[22];
	size_t					shift;

	shift = 0;
	a->shift = 0;
	while (ft_isdigit(frm[j]))
	{
		tmp[shift] = frm[j];
		shift++;
		frm++;
	}
	tmp[shift] = '\0';
	saver = atoi_extd(tmp);
	a->shift += shift;
	return (saver);
}

static unsigned short	is_flag_zero(const char *s, size_t j, struct s_gen *a)
{
	unsigned short int		shift;
	short					x0;
	short					x1;

	shift = 0;
	x0 = !ft_isdigit(s[j - 1]);
	x1 = (s[j] == '0');
	if (x0 && x1)
		a->m.f_zr = 1;
	while (s[j] == '0')
	{
		j++;
		shift++;
	}
	return (shift);
}

static unsigned long	get_prc_ln(struct s_gen *a, size_t j, const char *frm)
{
	unsigned long int		x;

	x = is_flag_zero(frm, j, a);
	if (x != 0)
		return (x);
	else if (frm[j] == '.')
	{
		a->m.dot = 1;
		if (ft_isdigit(frm[j + 1]))
			j++;
		else
		{
			a->m.f_prc = 0;
			return (1);
		}
		a->m.f_prc = (unsigned int)calc_prc_ln(a, j, frm);
		a->shift++;
		return (a->shift);
	}
	else if (ft_isdigit(frm[j]))
	{
		a->m.f_ln = (unsigned int)calc_prc_ln(a, j, frm);
		return (a->shift);
	}
	return (1);
}

static unsigned long	check_flags(struct s_gen *a_start, const char *format)
{
	char					x;
	unsigned long int		result;

	x = format[DN];
	if (x == ' ')
		a_start->m.f_spc = 1;
	else if (x == '+')
		a_start->m.f_pls = 1;
	else if (x == '-')
		a_start->m.f_mns = 1;
	else if (x == '#')
		a_start->m.f_hsh = 1;
	else if (x == 'j')
		a_start->m.j = 1;
	else if (x == 'z')
		a_start->m.z = 1;
	else
	{
		result = get_prc_ln(a_start, DN, format);
		return (result);
	}
	result = 1;
	return (result);
}

unsigned long			load_s_mods(struct s_gen *a_start, const char *format)
{
	char					x;
	unsigned long int		result;

	x = format[DN];
	result = 1;
	if (x == 'l')
	{
		if (format[DN + 1] == 'l')
			a_start->m.l2 = 1;
		else
			a_start->m.l = 1;
	}
	else if (x == 'h')
	{
		if (format[DN + 1] == 'h')
			a_start->m.h2 = 1;
		else
			a_start->m.h = 1;
	}
	else
	{
		result = check_flags(a_start, format);
		return (result);
	}
	return (result);
}
