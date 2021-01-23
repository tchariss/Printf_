/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:45:08 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/23 17:03:42 by tchariss         ###   ########.fr       */
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
	// s_i = ft_itoa(i);
	if ((str_spec->minus || str_spec->width < 0) && !str_spec->tochnost)
	{
		if (str_spec->width < 0) // делаю положительной ширину
			str_spec->width = str_spec->width * -1;
		if (str_spec->width < len)
		{
			if (!str_spec->minus)
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - len);
				str_spec->num += ft_putnbr(i, str_spec);
			}
			else
				str_spec->num += ft_putnbr(i, str_spec);
		}
		else // (str_spec->width > len)
		{
			str_spec->num += ft_putnbr(i, str_spec);
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
		}
	}
	else if (str_spec->tochnost)
	{
		// if (str_spec->width < 0)
		// 	str_spec->width = str_spec->width * -1;
	
		if (str_spec->tochnost < len && str_spec->width < len)
		{
			str_spec->num += ft_putnbr(i, str_spec);
			if (str_spec->width * (-1) > len )
				str_spec->num += ft_putchar_len(' ', str_spec->width - len);
		}
		else if (str_spec->tochnost > 0)
		{
			str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
			str_spec->num += ft_putnbr(i, str_spec);
			if ( str_spec->width < 0)
				str_spec->num += ft_putchar_len(' ', str_spec->width * (-1) - str_spec->tochnost);
		}
		else if (str_spec->width > len && str_spec->tochnost > 0)
			str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
		else if (str_spec->width < 0 && str_spec->tochnost < 0 )
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
		else if (str_spec->width > len && str_spec->tochnost < 0 )
		{
			str_spec->num += ft_putnbr(i, str_spec);
			str_spec->num += ft_putchar_len(' ', str_spec->width - len);
		}
	}
    //     if (str_spec->tochnost > len && str_spec->width > str_spec->tochnost)
    //     {
	// 		str_spec->num += ft_putchar_len(' ', str_spec->tochnost - len);
	// 		str_spec->num += ft_putnbr(i, str_spec);
    //         str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
    //     }
	// }
    // else if (str_spec->tochnost > 0) // точность есть 
    // {
    //     if (str_spec->tochnost > len && str_spec->tochnost < str_spec->width)
	// 	{
	// 		str_spec->num += ft_putchar_len(' ', str_spec->width - str_spec->tochnost);
	// 		str_spec->num += ft_putnbr(i, str_spec);
	// 	}
    // }
    // else if (str_spec->zero) // если есть флаг 0
    // {
    //     if (i == 0)
	// 	{
	// 		str_spec->num += ft_putchar_len(' ', str_spec->width);
	// 	}
	// 	else if ( i >=0 )
	// 	{
	// 		str_spec->num += ft_putchar_len('0', str_spec->width);
	// 		str_spec->num += ft_putnbr(i, str_spec);
	// 	}
	// 	else 
	// 	{
	// 		str_spec->num += ft_putchar_len('-', str_spec->width);
	// 		str_spec->num += ft_putchar_len('0', str_spec->width - len);
			
	// 	}
    // }
	else if (str_spec->width > len)
	{
		str_spec->num += ft_putchar_len(' ', str_spec->width - len);
		str_spec->num += ft_putnbr(i, str_spec);
	}
    else // только ширина 
    {
       str_spec->num += ft_putnbr(i, str_spec);
    }
}