/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 02:52:01 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/26 23:47:23 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parser(t_flags *str_spec, va_list v1)
{
	search_flag(str_spec);
	search_width(str_spec, v1);
	search_tochnost(str_spec, v1);
	search_type(str_spec);
	if (str_spec->type == 'c')
		type_c(str_spec, v1);
	else if (str_spec->type == 's')
		type_s(str_spec, v1);
	else if (str_spec->type == 'p')
	 	type_p(str_spec, v1);
	else if (str_spec->type == 'd' || str_spec->type == 'i')
		type_di(str_spec, v1);
	else if (str_spec->type == 'u')
		type_u(str_spec, v1);
	else if (str_spec->type == 'x' || str_spec->type == 'X')
	 	type_xX(str_spec, v1);
	else if (str_spec->type == '%')
		type_persent(str_spec);
	else
		return (-1);
	return (0);
}
