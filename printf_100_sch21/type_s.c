/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:45:33 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 15:54:17 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		no_width(char *s, int len, t_flags *str_spec)
{
	if (str_spec->tochnost < len)
		str_spec->num += write(1, s, str_spec->tochnost);
	else
		str_spec->num += write(1, s, len);
}

void		minus_or_width_s(char *s, int len, t_flags *str_spec)
{
	if (str_spec->width < 0)
		str_spec->width = str_spec->width * -1;
	if (str_spec->mark_tochnost == -1)
	{
		str_spec->num += write(1, s, len);
		if (str_spec->width > len)
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
	}
	else if (str_spec->width)
	{
		if (str_spec->tochnost < len)
		{
			str_spec->num += write(1, s, str_spec->tochnost);
			str_spec->num += ft_putchar_len(' ', str_spec->width -
													str_spec->tochnost);
		}
		else
		{
			str_spec->num += write(1, s, len);
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
		}
	}
	else
		no_width(s, len, str_spec);
}

void		be_tochnost_s(char *s, int len, t_flags *str_spec)
{
	if (str_spec->width)
	{
		if (str_spec->tochnost < len)
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width -
												str_spec->tochnost);
			str_spec->num += write(1, s, str_spec->tochnost);
		}
		else
		{
			if (str_spec->width > len)
				str_spec->num += ft_putchar_len(' ', str_spec->width - len);
			str_spec->num += write(1, s, len);
		}
	}
	else
	{
		if (str_spec->tochnost < len)
			str_spec->num += write(1, s, str_spec->tochnost);
		else
			str_spec->num += write(1, s, len);
	}
}

void		other_else_s(char *s, int len, t_flags *str_spec)
{
	if (str_spec->width > len)
		str_spec->num += ft_putchar_len(' ', str_spec->width - len);
	str_spec->num += write(1, s, len);
}

void		type_s(t_flags *str_spec, va_list v1)
{
	char	*s;
	int		len;

	s = va_arg(v1, char*);
	if (s == NULL || s == 0)
		s = "(null)";
	len = ft_strlen(s);
	if (str_spec->tochnost < 0)
		str_spec->mark_tochnost = -1;
	if (str_spec->minus || str_spec->width < 0)
		minus_or_width_s(s, len, str_spec);
	else if (str_spec->mark_tochnost != -1)
		be_tochnost_s(s, len, str_spec);
	else
		other_else_s(s, len, str_spec);
}
