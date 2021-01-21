/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01 /19 23:55:52 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/21 14:50:22 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
// если ничего нет
	printf("1|%s|\n", "vikos"); // |vikos|
	ft_printf("1|%s|\n", "vikos");
// если существует длина / ширина / флаг
	printf("2|%6s|\n", "vikos"); // |vikos|
	ft_printf("2|%6s|\n", "vikos");
	printf("3|%6.4s|\n", "vikos"); // |vikos|
	ft_printf("3|%6.4s|\n", "vikos");
	printf("4|%-6.4s|\n", "vikos"); // |vikos|
	ft_printf("4|%-6.4s|\n", "vikos");
	printf("5|%.s|\n", "vikos"); // |vikos|
	ft_printf("5|%.s|\n", "vikos");
	printf("6|%-4.s|\n", "vikos"); // |vikos|
	ft_printf("6|%-4.s|\n", "vikos");
	printf("7|%-s|\n", "vikos"); // |vikos|
	ft_printf("7|%-s|\n", "vikos");
// ширина
	printf("8|%6.4s|\n", "vikos"); // |vikos|
	ft_printf("8|%6.4s|\n", "vikos");
	printf("9|%4.3s|\n", "vikos"); // |vikos|
	ft_printf("9|%4.3s|\n", "vikos");
	printf("10|%6.8s|\n", "vikos"); // |vikos|
	ft_printf("10|%6.8s|\n", "vikos");
	printf("11|%4.8s|\n", "vikos"); // |vikos|
	ft_printf("11|%4.8s|\n", "vikos");
// точность
 	printf("12|%4.6s|\n", "vikos"); // |vikos|
	ft_printf("12|%4.6s|\n", "vikos");
	printf("13|%8.6s|\n", "vikos"); // |vikos|
	ft_printf("13|%8.6s|\n", "vikos");
	printf("14|%2.4s|\n", "vikos"); // |vikos|
	ft_printf("14|%2.4s|\n", "vikos");
	printf("15|%6.4s|\n", "vikos"); // |vikos|
	ft_printf("15|%6.4s|\n", "vikos");
	printf("16|%-*.6s|\n", -8, "vikos"); // |vikos|
	ft_printf("16|%-*.s|\n", -8, "vikos");
	printf("17|%*.6s|\n", -8, "vikos"); // |vikos|
	ft_printf("17|%*.6s|\n", -8, "vikos");
	printf("17|%*.*s|\n", -8, -6, "vikos"); // |vikos|
	ft_printf("17|%*.*s|\n", -8, -6, "vikos");
	
// 	////////----%-----%-----%----////////
// 	// printf("17|%8.6s|\n", "%vikos"); // |vikos|
// 	// ft_printf("17|%8.6s|\n", "%vikos");
// 	// printf("17|%%|\n"); // |vikos|
// 	// ft_printf("17|%%|\n");
// 	// printf("17|%c|\n", '%'); // |vikos|
// 	// ft_printf("17|%c|\n", '%');
// 	ft_printf("17|%.*s|\n", 0, "vikos");
// 	printf("17|%.*s|\n", -3, "vikos");
// 	printf("17|%.*s|\n", 3, "vikos");

////////-------------------------------////////

//// type_s
//// 1 условие 
//// if ( minus || width < 0 )
	printf("1|%s|\n", "vikos"); // |vikos|
	ft_printf("1|%s|\n", "vikos");
	printf("2|%-s|\n", "vikos"); // |vikos|
	ft_printf("2|%-s|\n", "vikos"); 
	printf("3|%*s|\n", -4, "vikos");
	ft_printf("3|%*s|\n", -4, "vikos"); // |vikos|
	printf("4|%*s|\n", -6, "vikos");
	ft_printf("4|%*s|\n", -6, "vikos"); // |vikos|
	printf("5|%-*s|\n", -4, "vikos");
	ft_printf("5|%-*s|\n", -4, "vikos"); 
	printf("6|%-*s|\n", -6, "vikos");
	ft_printf("6|%-*s|\n", -6, "vikos");
}