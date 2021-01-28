/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_persent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:47:53 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 15:43:36 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		type_persent(t_flags *str_spec)
{
	if (str_spec->width)
	{
		if (str_spec->minus == 1)
		{
			str_spec->num += write(1, "%", 1);
			str_spec->num += ft_putchar_len(' ', str_spec->width - 1);
		}
		else
		{
			if (str_spec->zero == 1)
			{
				str_spec->num += ft_putchar_len('0', str_spec->width - 1);
				str_spec->num += write(1, "%", 1);
			}
			else
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - 1);
				str_spec->num += write(1, "%", 1);
			}
		}
	}
	else
		str_spec->num += write(1, "%", 1);
	if (str_spec->width < 0)
		str_spec->num += ft_putchar_len(' ', str_spec->width * (-1) - 1);
}
