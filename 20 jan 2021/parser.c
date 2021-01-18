/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 02:52:01 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/18 14:06:24 by tchariss         ###   ########.fr       */
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

void		ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int		parser(char *s, t_flags *str_spec, va_list v1)
{
	write(1, s, 1);
	s++;
	write(1, s, 1);	
	//search_percent(str_spec, s);
	//search_flag(str_spec, s);
	// search_width();
	// search_precis();
	// search_type();
	
	// int		read_print = 0;
	// char	*s;
	// t_flags struct_pars;
	
	// s = (char *)str;
	
	// struct_pars.pers = -1;
	// struct_pars.zero = -1;
	// struct_pars.minus = -1;
	// struct_pars.width = -1; 
	// struct_pars.dot = -1;
	// struct_pars.precis = -1;
	// struct_pars.type = -1;

	// read_print = search_persent(&struct_pars, s);
	// read_print += search_flag(&struct_pars, &s[read_print]);
	// read_print += search_width(&struct_pars, &s[read_print]);
	// read_print += search_dot(&struct_pars, &s[read_print]);
	// read_print += search_precis(&struct_pars, &s[read_print]);
	// read_print += search_type(&struct_pars, &s[read_print]);
	
	// printf("----------------------------------\n");
	// printf("zero -> %d\n",struct_pars.pers);
    // printf("zero -> %d\n",struct_pars.zero);
    // printf("minus -> %d\n",struct_pars.minus);
    // printf("width -> %d\n",struct_pars.width);
	// printf("dot -> %d\n",struct_pars.dot);
	// printf("prec -> %d\n",struct_pars.precis);
    // printf("type -> %d\n",struct_pars.type);
    // printf("----------------------------------\n");
	return(1);
}
