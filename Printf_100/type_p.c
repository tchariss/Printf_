/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:46:49 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 16:47:09 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					be_tochnost_p(long unsigned i, int len, char *s,
														t_flags *str_spec)
{
	if (i == 0 && str_spec->mark_tochnost == 1)
	{
		str_spec->num += ft_putchar_len(' ', str_spec->width - ft_strlen(s));
		str_spec->num += write(1, s, ft_strlen(s));
	}
	else if (i >= 0)
	{
		if (str_spec->tochnost > len)
		{
			if (i == 0)
				str_spec->num += ft_putchar_len(' ', str_spec->width
											- (str_spec->tochnost - len) - len);
			str_spec->num += write(1, s, ft_strlen(s));
			str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
		}
		else
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width
													- str_spec->tochnost - len);
		}
		if (i != 0 && !str_spec->tochnost)
			str_spec->num += write(1, s, ft_strlen(s));
		ft_16_putnbr(i, str_spec->type, str_spec);
	}
}

void					be_zero_p(long unsigned i, int len, char *s,
														t_flags *str_spec)
{
	if (i == 0 && str_spec->mark_tochnost == 1)
	{
		str_spec->num += ft_putchar_len(' ', str_spec->width);
	}
	else if (i >= 0)
	{
		str_spec->num += ft_putchar_len('0', str_spec->width - len);
		str_spec->num += write(1, s, ft_strlen(s));
		ft_16_putnbr(i, str_spec->type, str_spec);
	}
}

void					other_else_p(long unsigned i, int len, char *s,
														t_flags *str_spec)
{
	if (i == 0 && str_spec->mark_tochnost == 1)
	{
		str_spec->num += ft_putchar_len(' ', str_spec->width);
	}
	else if (i > 0)
	{
		str_spec->num += ft_putchar_len(' ', str_spec->width - len - 2);
		str_spec->num += write(1, s, ft_strlen(s));
		ft_16_putnbr(i, str_spec->type, str_spec);
	}
	else
	{
		str_spec->num += ft_putchar_len(' ', str_spec->width
													- ft_strlen(s) - 1);
		str_spec->num += write(1, s, ft_strlen(s));
		ft_16_putnbr(i, str_spec->type, str_spec);
	}
}

void					type_p(t_flags *str_spec, va_list v1)
{
	long unsigned		i;
	int					len;
	char				*s;

	s = ft_strdup("0x");
	i = va_arg(v1, long long unsigned);
	len = ft_strlen_16(i);
	if (str_spec->minus || str_spec->width < 0)
		minus_or_width_neg_p(i, len, s, str_spec);
	else if (str_spec->mark_tochnost != -1)
		be_tochnost_p(i, len, s, str_spec);
	else if (str_spec->zero)
		be_zero_p(i, len, s, str_spec);
	else
		other_else_p(i, len, s, str_spec);
	free(s);
}
