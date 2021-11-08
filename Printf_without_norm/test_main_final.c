/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:44:50 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 15:17:20 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    int		a = -4;
    char	c = 'a';
    char	*n = "abcdefghijklmnop";
    char	*o = "-a";
    char	*p = "-12";
    char	*q = "0";
	char	*r = "%%";
    
    printf("|%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c|\n", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c);
    ft_printf("|%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c|\n", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c);
    printf("|%-*c,|\n", a, q[0]);
    ft_printf("|%-*c,|\n", a, q[0]);
    printf("|%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c|\n", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c);
    ft_printf("|%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c|\n", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c);
    
    printf("|%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c|\n", c, n[0], o[0], -a, q[0], -a, q[0], -a, r[0], -a, c);
    ft_printf("|%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c|\n", c, n[0], o[0], -a, q[0], -a, q[0], -a, r[0], -a, c);
    // printf("|%*c|\n", 18, 'a');
    // ft_printf("|%*c|\n", 18, 'a');
	// printf("|%*c|\n", 12, 18, '0');
    // ft_printf("|%*c|\n", 12, 18, '0');

    // printf("|%*.*d|\n", 4, 1, -12);
    // ft_printf("|%*.*d|\n", 4, 1, -12);
    
	// printf("|%*.*d|\n", 4, -1, -12);
    // ft_printf("|%*.*d|\n", 4, -1, -12);
	
	// printf("|%0*.*d|\n", 4, -1, -12);
    // ft_printf("|%0*.*d|\n", 4, -1, -12);
}
