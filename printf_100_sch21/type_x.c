/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:46:37 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 16:41:57 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				minus_or_width_neg_x(unsigned i, int len, t_flags *str_spec)
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
		ft_16_putnbr(i, str_spec->type, str_spec);
		if (str_spec->tochnost < len)
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
		else
			str_spec->num += ft_putchar_len(' ', str_spec->width -
													str_spec->tochnost);
	}
}

void				be_tochnost_x(unsigned i, int len, t_flags *str_spec)
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
		ft_16_putnbr(i, str_spec->type, str_spec);
		if (str_spec->zero && str_spec->minus)
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
	}
}

void				be_zero_x(unsigned i, int len, t_flags *str_spec)
{
	if (i == 0 && str_spec->mark_tochnost == 1)
	{
		str_spec->num += ft_putchar_len(' ', str_spec->width);
	}
	else if (i >= 0)
	{
		str_spec->num += ft_putchar_len('0', str_spec->width - len);
		ft_16_putnbr(i, str_spec->type, str_spec);
	}
}

void				type_x(t_flags *str_spec, va_list v1)
{
	unsigned int	i;
	int				len;

	i = va_arg(v1, unsigned int);
	len = ft_strlen_16(i);
	if (str_spec->minus || str_spec->width < 0)
		minus_or_width_neg_x(i, len, str_spec);
	else if (str_spec->mark_tochnost != -1)
		be_tochnost_x(i, len, str_spec);
	else if (str_spec->zero)
		be_zero_x(i, len, str_spec);
	else
	{
		if (i == 0 && str_spec->mark_tochnost == 1)
			str_spec->num += ft_putchar_len(' ', str_spec->width);
		else if (i >= 0)
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
			ft_16_putnbr(i, str_spec->type, str_spec);
		}
	}
}
