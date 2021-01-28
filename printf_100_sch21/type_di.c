/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:45:08 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 16:44:03 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		be_tochnost_and_i_less(int i, int len, t_flags *str_spec)
{
	if (str_spec->tochnost >= len)
		str_spec->num += ft_putchar_len(' ', str_spec->width -
									(str_spec->tochnost - len) - len - 1);
	else if (str_spec->tochnost < len && str_spec->tochnost < 0
													&& str_spec->zero)
		str_spec->num += ft_putchar_len(' ', str_spec->width - len - 1 - 1);
	else
		str_spec->num += ft_putchar_len(' ', str_spec->width - len - 1);
	str_spec->num += ft_putchar_len('-', 1);
	if (str_spec->tochnost < 0 && str_spec->zero)
	{
		str_spec->num += ft_putchar_len('0', str_spec->width - len - 1);
	}
	if (str_spec->tochnost >= len)
		str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
	ft_putnbr(i * (-1), str_spec);
}

void		be_tochnost_di(int i, int len, t_flags *str_spec)
{
	if (i == 0 && str_spec->mark_tochnost == 1)
		str_spec->num += ft_putchar_len(' ', str_spec->width);
	else if (i >= 0)
	{
		if (str_spec->tochnost > len)
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width -
										(str_spec->tochnost - len) - len);
			str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
		}
		else if (str_spec->tochnost < 0 && str_spec->zero)
			str_spec->num += ft_putchar_len('0', str_spec->width - len);
		else
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
		ft_putnbr(i, str_spec);
	}
	else
		be_tochnost_and_i_less(i, len, str_spec);
}

void		be_zero_di(int i, int len, t_flags *str_spec)
{
	if (i == 0 && str_spec->mark_tochnost == 1)
	{
		str_spec->num += ft_putchar_len(' ', str_spec->width);
	}
	else if (i >= 0)
	{
		str_spec->num += ft_putchar_len('0', str_spec->width - len);
		ft_putnbr(i, str_spec);
	}
	else
	{
		str_spec->num += ft_putchar_len('-', 1);
		str_spec->num += ft_putchar_len('0', str_spec->width - len - 1);
		ft_putnbr(i * (-1), str_spec);
	}
}

void		type_di(t_flags *str_spec, va_list v1)
{
	long	i;
	int		len;

	i = va_arg(v1, int);
	len = ft_digit_strlen(i);
	if (str_spec->minus || str_spec->width < 0)
		minus_or_width_neg_di(i, len, str_spec);
	else if (str_spec->mark_tochnost != -1)
		be_tochnost_di(i, len, str_spec);
	else if (str_spec->zero)
		be_zero_di(i, len, str_spec);
	else
	{
		if (i >= 0)
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
			ft_putnbr(i, str_spec);
		}
		else
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width - len - 1);
			str_spec->num += ft_putchar_len('-', 1);
			ft_putnbr(i * (-1), str_spec);
		}
	}
}
