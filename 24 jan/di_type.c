/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:30:13 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/24 12:56:51 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		type_di(t_flags *str_spec, va_list v1)
{
	int		i;
	int		len;
	// char	*s_i;
	
	i = va_arg(v1, int);
	len = ft_digit_strlen(i);
    if (i == 0 && str_spec->tochnost == 0)
    { 
        str_spec->num += ft_putchar_len(' ', str_spec->width);
    }
    if (!str_spec->minus)
	{
		if (i >= 0)
		{
			str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
			str_spec->num += ft_putnbr(i, str_spec);
			if (str_spec->tochnost > len)
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost - len - len);
			}
			else // (str_spec->tochnost < len)
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - len);
			}
		}
		else
		{
			str_spec->num += ft_putnbr('-', str_spec);
			str_spec->num += ft_putchar_len('0', str_spec->tochnost - len + 1);
			str_spec->num += ft_putnbr(i * (-1), str_spec);
			if (str_spec->tochnost > len - 1)
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - (str_spec->tochnost - len + 1) - len);
			}
			else // (str_spec->tochnost < len - 1)
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - len);
			}
		}	
	}
	else 
	{
		if (!str_spec->tochnost)
    	{
    		if (i < 0)
    		{
				if (str_spec->zero)
				{
					str_spec->num += ft_putnbr('-', str_spec);
					str_spec->num += ft_putchar_len('0', str_spec->width - len);
					str_spec->num += ft_putnbr(i * (-1), str_spec);
				}
				str_spec->num += ft_putchar_len(' ', str_spec->width - len);
				str_spec->num += ft_putnbr(i, str_spec);
			}
			else // число > 0
			{
				if (str_spec->zero)
				{
					str_spec->num += ft_putchar_len('0', str_spec->width - len);
					str_spec->num += ft_putnbr(i, str_spec);
				}
				else // 0 нет 
				{
					str_spec->num += ft_putchar_len(' ', str_spec->width - len);
					str_spec->num += ft_putnbr(i, str_spec);
				}
			}
		}
		else // точность есть
		{ // 2 условие 
			if (i < 0)
			{
				if (str_spec->tochnost > len - 1)
				{
					str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost - len + 1 - len);
					str_spec->num += ft_putnbr('-', str_spec);
					str_spec->num += ft_putchar_len('0', str_spec->tochnost);
					str_spec->num += ft_putnbr(i * (-1), str_spec);
				}
				else // str_spec->tochnost < len - 1 -> 0
				{
					str_spec->num += ft_putchar_len(' ', str_spec->width - len);
					str_spec->num += ft_putnbr('-', str_spec);
					str_spec->num += ft_putchar_len('0', 0); // то есть нисколько
					str_spec->num += ft_putnbr(i * (-1), str_spec);
				}
			}
			else // число > 0
			{
				if (str_spec->tochnost > len)
				{
					str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost - len - len);
					str_spec->num += ft_putchar_len('0',  str_spec->tochnost - len );
					str_spec->num += ft_putnbr(i, str_spec);
				}
				else // str_spec->tochnost < len -> 0
				{
					str_spec->num += ft_putchar_len(' ', str_spec->width - len);
					str_spec->num += ft_putchar_len('0', 0); // то есть нисколько
					str_spec->num += ft_putnbr(i, str_spec);
				}
			}
		}
	}
}	