/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_parcer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 22:12:42 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/21 22:12:47 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void				ft_buff_print_renew(struct s_gen *a_start)
{
	a_start->prtd_chr_num = (int)(a_start->prtd_chr_num + IN);
	write(1, a_start->total_str, IN);
	IN = 0;
}

static	short int		check_flags_list(char c)
{
	if (c == ' ' || c == '#' || c == '+' || c == '-' \
	|| ft_isdigit(c) || c == '.' || c == 'l' || c == 'h' \
	|| c == 'j' || c == 'z')
		return (1);
	if (c == 'D' || c == 'O' || c == 'U' || c == 'S' || c == 'C' || c == 'X')
		return (2);
	return (0);
}

static unsigned long	start_fl_handler(struct s_gen *a_start, const char *frm)
{
	short int				j;
	unsigned long int		shift;
	char					x;

	while (frm[DN] != '\0' && (j = check_flags_list(frm[DN])) == 1)
	{
		shift = parce_in(a_start, frm);
		DN += shift;
	}
	if (frm[DN] == '\0')
		return (DN);
	x = frm[DN];
	if (j == 2 && x != 'X')
		a_start->m.l = 1;
	else if (x == 'X')
		a_start->m.xb_conv = 1;
	else if (x == 'p')
		a_start->m.f_hsh = 1;
	if (j == 2)
		CFL = x + 32;
	else
		CFL = x;
	DN += extract_arg_value(a_start, frm[DN]);
	ft_memset(&a_start->m, 0, sizeof(a_start->m));
	return (DN);
}

short int				load_symbol(struct s_gen *a_start, int x)
{
	if (IN == MEMS - 1)
	{
		ft_buff_print_renew(a_start);
	}
	a_start->total_str[IN] = (char)x;
	IN++;
	return (0);
}

void					general_parcer(struct s_gen *a_start, const char *frm)
{
	while (frm[DN])
	{
		if (frm[DN] != '%')
		{
			load_symbol(a_start, frm[DN]);
			DN++;
		}
		else
		{
			DN++;
			DN = start_fl_handler(a_start, frm);
		}
	}
}
