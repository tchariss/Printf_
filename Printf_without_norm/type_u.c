/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:46:49 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 01:20:05 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		type_u(t_flags *str_spec, va_list v1)
{
	unsigned int	i;
	int				len;

	i = va_arg(v1, unsigned int);
	len = ft_digit_unsigned_strlen(i);
	if (str_spec->minus || str_spec->width < 0)
	{
		// 1 condition
		if (str_spec->width < 0) // делаю положительной ширину
			str_spec->width = str_spec->width * -1;
		if (i == 0 && str_spec->mark_tochnost == 1) // печатаю просто ширину числа |  | mark = 1 -> ().s)
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width);
		}
		else if (i >= 0)
		{
			if (str_spec->tochnost > len)
				str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
			ft_putnbr(i, str_spec);
			if (str_spec->tochnost < len)
				str_spec->num += ft_putchar_len(' ', str_spec->width - len);
			if (str_spec->tochnost > len)
				str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
		}
	}
	// 2 условие
	else if (str_spec->mark_tochnost != -1) //&& str_spec->mark_tochnost != -1) // .0 -> тоже существует
	{
		if (i == 0 && str_spec->mark_tochnost == 1) // печатаю просто ширину числа |  | mark = 1 -> ().s)
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width);
		}
		else if (i >= 0)
		{
			if (str_spec->tochnost > len)
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - (str_spec->tochnost - len) - len);
				str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
			}
			else
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - len);
			}
			ft_putnbr(i, str_spec);
			if (str_spec->zero && str_spec->minus)
				str_spec->num += ft_putchar_len(' ', str_spec->width - len);
		}
	}
	// 3 условие
	else if (str_spec->zero)
	{
		if (i == 0 && str_spec->mark_tochnost == 1) // печатаю просто ширину числа |  | mark = 1 -> ().s)
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width);
		}
		else if (i >= 0)
		{
			str_spec->num += ft_putchar_len('0', str_spec->width - len);
			ft_putnbr(i, str_spec);
		}
	}
	// 4 условие // только ширина
	else
	{
		if (i == 0 && str_spec->mark_tochnost == 1) // печатаю просто ширину числа |  | mark = 1 -> ().s)
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width);
		}
		else if (i >= 0 && i != 4294967295)
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
			ft_putnbr_unsigned(i, str_spec);
		}
		else if (i == 4294967295)
		{
			str_spec->num += ft_putstr(ft_itoa(i), len);
		}
	}
}
