/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:45:33 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/25 23:39:47 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		type_s(t_flags *str_spec, va_list v1)
{
	char	*s;
	int		len;
	//int		abs;
	
	s = va_arg(v1, char*);
	if (s == NULL || s == 0)
		s = "(null)";
	len = ft_strlen(s);
	if (str_spec->tochnost < 0)
		str_spec->mark_tochnost = -1;
	// 1 условие
	if (str_spec->minus || str_spec->width < 0) // !str_spec->tochnost -> точности нет 
	{
		if (str_spec->width < 0) // делаю положительной ширину
		 	str_spec->width = str_spec->width * -1;
		if (str_spec->mark_tochnost == -1) // нет вообще точности и не ноль , так как .0
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
				str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost); //- str_spec->tochnost);
			}
			else // точность > len
			{
				str_spec->num += write(1, s, len);
				str_spec->num += ft_putchar_len(' ', str_spec->width - len);
				// if (str_spec->width < len)
				// 	str_spec->num += str_spec->width;
			}
		}
		else 
		{ 
			if (str_spec->tochnost < len)
				str_spec->num += write(1, s, str_spec->tochnost);
			else //(str_spec->tochnost > len)
				str_spec->num += write(1, s, len);
		}
	}
	// заканчиваете 1 условие 
	// 2 условие
	else if (str_spec->mark_tochnost != -1) // существует точность
	{
		if (str_spec->width) 
		{
			if (str_spec->tochnost < len)
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
				str_spec->num += write(1, s, str_spec->tochnost);
			}
			else // точность > len
			{
				if (str_spec->width > len)
					str_spec->num += ft_putchar_len(' ', str_spec->width - len);
				str_spec->num += write(1, s, len);
			}
		}
		else // width нет 
		{
			// if (str_spec->tochnost < 0 &&  str_spec->tochnost < len)
			// {
			// 	str_spec->num += write(1, s, len);
			// }
			if (str_spec->tochnost < len)
			{
				str_spec->num += write(1, s, str_spec->tochnost);
			}
			else // точность > len
			{
				str_spec->num += write(1, s, len);
			}
		}
	}
	// 3 условие , только ширина есть 
	else // (str_spec->width)
	{
		if (str_spec->width > len)
			str_spec->num += ft_putchar_len(' ', str_spec->width - len); 
		str_spec->num += write(1, s, len);
		// if (str_spec->width < len)
		// 			str_spec->num += str_spec->width;
	}
}
	