/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 20:39:49 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/21 15:57:59 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	search_flag(t_flags *str_spec)
{
	if (*str_spec->str == ' ')
	{
		str_spec->num = str_spec->num + write (1, " ", 1);
		str_spec->str++;
	}
	while (*str_spec->str == ' ')
		str_spec->str++; // обработка пробелов // должен выводить 1 пробел 
	if (*str_spec->str == '-')
		str_spec->minus = 1;
	if (*str_spec->str == '0')
		str_spec->zero = 1;
	while (*str_spec->str == '-' || *str_spec->str == '0')
		str_spec->str++;
}

void	search_width(t_flags *str_spec, va_list v1)
{
	if (*str_spec->str == '*')
	{
		str_spec->width = va_arg(v1, int);
		str_spec->str++;
	}
	while (*str_spec->str >= '0' && *str_spec->str <= '9')
		str_spec->width = 10 * str_spec->width + ((*str_spec->str++) - '0');
}
// изначально все спецификаторы = 0 (спасибо калок), точность = -1
// if точность = 1 , значит найдена
void		search_tochnost(t_flags *str_spec, va_list v1)
{
	
	if (*str_spec->str && *str_spec->str == '.')
	{
		str_spec->str++;
		if (ft_strchr(SPECIF, *str_spec->str))
		{
			str_spec->mark_tochnost = 1; // если . и спецификатор -> печатаем ничего
		}
		if (*str_spec->str == '*')
		{
			str_spec->tochnost = va_arg(v1, int);
			str_spec->str++;
		}
		while (*str_spec->str >= '0' && *str_spec->str <= '9')
		{
			str_spec->tochnost = 10 * str_spec->tochnost + (*str_spec->str - '0');
			if (*str_spec->str == '0')
			{
				str_spec->mark_tochnost = 2; // если .0 -> печатаем ничего
			}
			str_spec->str++;
		}
		// if (str_spec->tochnost == 0 && *str_spec->str-- == '0')
		// {
		// 	str_spec->mark_tochnost = 2; // если .0 -> печатаем ничего
		// }
	}
	// else
	// {
	// 	str_spec->mark_tochnost = -1; // не существует
	// } // то есть точность как была - так и осталась ( не найдена )
}

void		search_type(t_flags *str_spec)
{
	if (ft_strchr(SPECIF, *str_spec->str))
	{
		str_spec->type = *str_spec->str;
		str_spec->str++;
	}
}

// int	main()
// {
// 	ft_printf("-5.2%s", "viktorina");
// 	//-----------------------------
// 	printf("-5.2%s", "viktorina");
// }