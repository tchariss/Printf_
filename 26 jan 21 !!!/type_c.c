/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:46:53 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/22 08:31:45 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		type_c(t_flags *str_spec, va_list v1)
{
	char	c;

	c = va_arg(v1, int);
	if (str_spec->width)
	{
		if (str_spec->minus)// по левому краю равняю
		{ //печатаю символ и пробелы
			str_spec->num += write(1, &c, 1);
			str_spec->num += ft_putchar_len(' ', str_spec->width - 1);
		} // и записываю в num количество символов, чтобы printf вернул их
		else 
		{ // печатаю пробелы и символ
			str_spec->num += ft_putchar_len(' ', str_spec->width - 1);
			str_spec->num += write(1, &c, 1);
		}
	}
	else
	{ // просто символ вывожу
		str_spec->num += write(1, &c, 1);
	}
}

// int			main()
// {
// 	char a;
// 	a = 'c';
// 	printf ("|%c|\n", a); // c
// 	printf ("|%5c|\n", a); // - - - - c
// 	printf ("|%-5c|\n", a); // c - - - -
// 	// printf ("|%05c|\n", a); // 0 0 0 0 c // неопределенное поведение
// 	ft_printf ("|%c|\n", a); // c
// 	ft_printf ("|%5c|\n", a); // - - - - c
// 	ft_printf ("|%-5c|\n", a); // c - - - -
// 	//ft_printf ("|%05c|\n", a); // 0 0 0 0 c // неопределенное поведение
// }