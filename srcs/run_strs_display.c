/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_strs_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 23:39:20 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/08/21 23:39:24 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

short int	strs_output(struct s_gen *a_start, char *frm, size_t len)
{
	size_t	x_precision;
	size_t	j;
	short	check;

	j = 0;
	check = a_start->m.dot;
	x_precision = a_start->m.f_prc;
	if (!check || x_precision > len)
	{
		while (frm[j] != '\0')
		{
			load_symbol(a_start, frm[j]);
			j = j + 1;
		}
	}
	else
	{
		while (j < x_precision)
		{
			load_symbol(a_start, frm[j]);
			j = j + 1;
		}
	}
	return (0);
}
