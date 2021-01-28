/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:40:50 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 16:49:29 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					minus_or_width_neg_p(long unsigned i, int len, char *s,
															t_flags *str_spec)
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
		str_spec->num += write(1, s, ft_strlen(s));
		ft_16_putnbr(i, str_spec->type, str_spec);
		if (str_spec->tochnost < len)
			str_spec->num += ft_putchar_len(' ', str_spec->width - len - 2);
		if (str_spec->tochnost > len)
			str_spec->num += ft_putchar_len(' ', str_spec->width
													- str_spec->tochnost);
	}
}
