/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:25:18 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/26 22:32:55 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
    size_t	a;

	a = 0;
	while (str[a] != '\0')
		a++;
    return(a);
}

void		init_struct(t_flags *str_spec)
{
	//str_spec->num = 0;
	str_spec->minus = 0; // char flag
	str_spec->zero = 0;
	str_spec->width = 0;
	str_spec->tochnost = 0; // (+ int dot)
	str_spec->mark_tochnost = 0;
	str_spec->type = 0;	
}

int			ft_printf(const char *str, ...)
{
	t_flags	*str_spec;
	va_list	v1;
	//char 	*s;
	int		num; // количество выведенных символов
	
	num = 0;
	str_spec = (t_flags *)ft_calloc(sizeof(t_flags), 1); // зануляю элементы структуры
	if (str_spec == NULL)
		return (-1); //ошибка
	str_spec->str = (char *)str;
    va_start(v1, str);
	//str_spec->tochnost = -1;
	while (*str_spec->str)
	{
		init_struct(str_spec);
		if (*str_spec->str == '%')
		{
			str_spec->str++;
			parser(str_spec, v1);
		}
		else
		{
			write(1, str_spec->str, 1);
			str_spec->str++;
			str_spec->num++;
		}
	}
	free(str_spec);
	va_end(v1);
	return (str_spec->num);
}
