/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_iniz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 02:52:01 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/16 13:53:00 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parser(const char *str) //, va_list v1)
{
	int		read_print = 0;
	char	*s;
	// s = (char *)str;
	t_flags struct_pars;
	
	struct_pars.pers = -1;
	struct_pars.zero = -1;
	struct_pars.minus = -1;
	struct_pars.width = -1; 
	struct_pars.dot = -1;
	struct_pars.precis = -1;
	struct_pars.type = -1;

	read_print = search_persent(&struct_pars, s);
	read_print += search_flag(&struct_pars, &s[read_print]);
	read_print += search_width(&struct_pars, &s[read_print]);
	read_print += search_dot(&struct_pars, &s[read_print]);
	read_print += search_precis(&struct_pars, &s[read_print]);
	read_print += search_type(&struct_pars, &s[read_print]);
	
	// printf("----------------------------------\n");
	// printf("zero -> %d\n",struct_pars.pers);
    // printf("zero -> %d\n",struct_pars.zero);
    // printf("minus -> %d\n",struct_pars.minus);
    // printf("width -> %d\n",struct_pars.width);
	// printf("dot -> %d\n",struct_pars.dot);
	// printf("prec -> %d\n",struct_pars.precis);
    // printf("type -> %d\n",struct_pars.type);
    // printf("----------------------------------\n");
	// return(1);
}
