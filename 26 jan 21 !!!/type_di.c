// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   type_di.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/01/07 18:45:08 by tchariss          #+#    #+#             */
// /*   Updated: 2021/01/25 13:15:26 by tchariss         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "ft_printf.h"

void		type_di(t_flags *str_spec, va_list v1)
{
	int		i;
	int		len;
	// char	*s_i;
	
	i = va_arg(v1, int);
	len = ft_digit_strlen(i);
	// s_i = ft_itoa(i);
	if (str_spec->minus || str_spec->width < 0)
	{
		// 1 condition
		
		if (str_spec->width < 0) // делаю положительной ширину
			str_spec->width = str_spec->width * -1;
		if (i == 0 && str_spec->mark_tochnost == 1) // печатаю просто ширину числа |  | mark = 1 -> ().s)
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width);
		}
		else if (i >= 0)
		{
			if (str_spec->tochnost > len)
				str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
			ft_putnbr(i, str_spec);
			if (str_spec->tochnost > len)
				str_spec->num += ft_putchar_len(' ', str_spec->width - (str_spec->tochnost - len) - len);
			else
				str_spec->num += ft_putchar_len(' ', str_spec->width - len);
		}
		else if (i < 0)
		{
			str_spec->num += ft_putchar_len('-', 1);
			if (str_spec->tochnost >= len)
			{
				str_spec->num += ft_putchar_len('0', str_spec->tochnost - len); // -1 (i < 0) "-234"
			}
			ft_putnbr(i * (-1), str_spec);
			if (str_spec->tochnost >= len)
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - (str_spec->tochnost - len + 1) - len);
			}
			else // (str_spec->tochnost <= len)
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - len - 1);
			}
		}
	}
	// 2 условие
	else if (str_spec->mark_tochnost != -1) //&& str_spec->mark_tochnost != -1) // .0 -> тоже существует
	{
		if (i == 0 && str_spec->mark_tochnost == 1) // печатаю просто ширину числа |  | mark = 1 -> ().s)
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width);
		}
		else if (i >= 0)
		{
			if (str_spec->tochnost > len)
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - (str_spec->tochnost - len) - len);
				str_spec->num += ft_putchar_len('0', str_spec->tochnost - len);
			}
			else
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - len);
			}
			ft_putnbr(i, str_spec);
		}
		else
		{
			// str_spec->num += ft_putchar_len('-', 1);
			if (str_spec->tochnost >= len)
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - (str_spec->tochnost - len) - len - 1);
			} // len + 1
			else
			{
				str_spec->num += ft_putchar_len(' ', str_spec->width - len - 1);
			}
			str_spec->num += ft_putchar_len('-', 1);
			if (str_spec->tochnost >= len)
			{
				str_spec->num += ft_putchar_len('0', str_spec->tochnost - len); // +1
			}
			ft_putnbr(i * (-1), str_spec);
		}
	}
	// 3 условие
	else if (str_spec->zero)
	{
		if (i == 0 && str_spec->mark_tochnost == 1) // печатаю просто ширину числа |  | mark = 1 -> ().s)
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
	// 4 условие // только ширина
	else
	{
		if (i == 0 && str_spec->mark_tochnost == 1) // печатаю просто ширину числа |  | mark = 1 -> ().s)
		{
			str_spec->num += ft_putchar_len(' ', str_spec->width);
		}
		else if (i >= 0)
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
		// if (str_spec->width < len)
		// {
		// 	if (!str_spec->minus)
		// 	{
		// 		str_spec->num += ft_putchar_len(' ', str_spec->width - len);
		// 		str_spec->num += ft_putnbr(i, str_spec);
		// 	}
		// 	else
		// 		str_spec->num += ft_putnbr(i, str_spec);
		// }
		// else // (str_spec->width > len)
		// {
		// 	if (str_spec->mark_tochnost != 1 && i != 0)
		// 	{	
		// 		//if (i != 0)
		// 		//	str_spec->num += ft_putnbr(i, str_spec);
		// 		str_spec->num += ft_putchar_len(' ', str_spec->width - len);
		// 	}
		// }
	