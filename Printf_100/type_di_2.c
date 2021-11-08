/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:43:46 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/28 15:08:11 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		i_less_zero(int i, int len, t_flags *str_spec)
{
	str_spec->num += ft_putchar_len('-', 1);
	if (str_spec->tochnost >= len)
		str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
	ft_putnbr(i * (-1), str_spec);
	if (str_spec->tochnost >= len)
		str_spec->num += ft_putchar_len(' ', str_spec->width -
								(str_spec->tochnost - len + 1) - len);
	else
		str_spec->num += ft_putchar_len(' ', str_spec->width - len - 1);
}

void		minus_or_width_neg_di(int i, int len, t_flags *str_spec)
{
	if (str_spec->width < 0)
		str_spec->width = str_spec->width * -1;
	if (i == 0 && str_spec->mark_tochnost == 1)
		str_spec->num += ft_putchar_len(' ', str_spec->width);
	else if (i >= 0)
	{
		if (str_spec->tochnost > len)
			str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
		ft_putnbr(i, str_spec);
		if (str_spec->tochnost > len)
			str_spec->num += ft_putchar_len(' ', str_spec->width -
										(str_spec->tochnost - len) - len);
		else
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
	}
	else if (i < 0)
	{
		i_less_zero(i, len, str_spec);
	}
}
