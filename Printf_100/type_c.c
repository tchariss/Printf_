/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:46:53 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 16:56:19 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		no_minus_c(t_flags *str_spec, char c)
{
	if (str_spec->width < 0)
	{
		str_spec->width = str_spec->width * -1;
		str_spec->num += write(1, &c, 1);
		str_spec->num += ft_putchar_len(' ', str_spec->width - 1);
	}
	else
	{
		str_spec->num += ft_putchar_len(' ', str_spec->width - 1);
		str_spec->num += write(1, &c, 1);
	}
}

void		type_c(t_flags *str_spec, va_list v1)
{
	char	c;

	c = va_arg(v1, int);
	if (str_spec->width)
	{
		if (str_spec->minus)
		{
			str_spec->num += write(1, &c, 1);
			if (str_spec->width < 0)
				str_spec->width = str_spec->width * -1;
			str_spec->num += ft_putchar_len(' ', str_spec->width - 1);
		}
		else
			no_minus_c(str_spec, c);
	}
	else
		str_spec->num += write(1, &c, 1);
}
