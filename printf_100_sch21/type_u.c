/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:46:49 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 13:32:55 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				minus_or_width_neg_u(unsigned i, int len, t_flags *str_spec)
{
	if (str_spec->width < 0)
		str_spec->width = str_spec->width * -1;
	if (i == 0 && str_spec->mark_tochnost == 1)
	{
		str_spec->num += ft_putchar_len(' ', str_spec->width);
	}
	else if (i >= 0)
	{
		if (str_spec->tochnost > len)
			str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
		ft_putnbr(i, str_spec);
		if (str_spec->tochnost > len)
			str_spec->num += ft_putchar_len(' ', str_spec->width -
												str_spec->tochnost);
		else
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
	}
}

void				be_tochnost_u(unsigned i, int len, t_flags *str_spec)
{
	if (i == 0 && str_spec->mark_tochnost == 1)
	{
		str_spec->num += ft_putchar_len(' ', str_spec->width);
	}
	else if (i >= 0)
	{
		if (str_spec->tochnost > len)
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width -
										(str_spec->tochnost - len) - len);
			str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
		}
		else if (str_spec->tochnost < 0 && str_spec->zero)
		{
			str_spec->num += ft_putchar_len('0', str_spec->width - len);
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

void				be_zero_u(unsigned i, int len, t_flags *str_spec)
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
}

void				type_u(t_flags *str_spec, va_list v1)
{
	unsigned int	i;
	int				len;

	i = va_arg(v1, unsigned int);
	len = ft_digit_unsigned_strlen(i);
	if (str_spec->minus || str_spec->width < 0)
		minus_or_width_neg_u(i, len, str_spec);
	else if (str_spec->mark_tochnost != -1)
		be_tochnost_u(i, len, str_spec);
	else if (str_spec->zero)
		be_zero_u(i, len, str_spec);
	else
	{
		if (i == 0 && str_spec->mark_tochnost == 1)
			str_spec->num += ft_putchar_len(' ', str_spec->width);
		else if (i >= 0 && i != 4294967295)
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
			ft_putnbr_unsigned(i, str_spec);
		}
		else if (i == 4294967295)
			str_spec->num += ft_putstr(ft_itoa(i), len);
	}
}
