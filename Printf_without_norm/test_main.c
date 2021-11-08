/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:39:56 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/20 06:50:02 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     main()
{
    // int len;
	// int b;arg

	// b = 12345678;
	// char a;
    // a = 'p';

	printf("|%s|\n", "vikos"); // |vikos|
	ft_printf("|%s|\n", "vikos"); // |vikos|
	printf("|%8.s|\n", "vikos"); // |vikos|
	ft_printf("|%4s|\n", "vikos"); // |vikos|
	
	printf("\n|%-s|\n", "vikos"); // |vikos|
	ft_printf("|%-s|\n", "vikos"); // |vikos|
	printf("|%-2s|\n", "vikos"); // |vikos|
	ft_printf("|%-2s|\n", "vikos");
	
	printf("\n|%2s|\n", "vikos"); // |vikos|
	ft_printf("|%2s|\n", "vikos"); // |vikos|
	printf("|%2.2s|\n", "vikos"); // |vi|
	ft_printf("|%2.2s|\n", "vikos"); // |vi|
	printf("|%4.2s|\n", "vikos"); // |- - vi|
	ft_printf("|%4.2s|\n", "vikos"); // |- - vi|
	printf("|%8.2s|\n", "vikos"); // |- - - - - - vi
	ft_printf("|%8.2s|\n", "vikos"); // |- - - - - - vi||
	// // //------------type_s-----------//
	// //ширина и флаг
	printf("|%4s|\n", "vikos"); // |vikos|
	ft_printf("|%4s|\n", "vikos"); // |vikos|
	printf("|%s|\n", "vikos"); // |vikos|
	ft_printf("|%s|\n", "vikos"); // |vikos|
	printf("|%-s|\n", "vikos"); // |vikos|
	ft_printf("|%-s|\n", "vikos"); // |vikos|
	printf("|%2s|\n", "vikos"); // |vikos|
	ft_printf("|%2s|\n", "vikos"); // |vikos|
	printf("|%-2s|\n", "vikos"); // |vikos|
	ft_printf("|%-2s|\n", "vikos"); // |vikos|
	//printf("|%-02s|\n", "vikos"); // |vikos| // неопределенное поведение , преимущество у '-'
	//printf("|%02s|\n", "vikos"); // |vikos| // неопределенное поведение
	printf("|%8s|\n", "vikos"); // |- - - vikos|
	ft_printf("|%8s|\n", "vikos"); // |- - - vikos|
	printf("|%-8s|\n", "vikos"); // |vikos - - -|
	ft_printf("|%-8s|\n", "vikos"); // |vikos - - -|
	// //printf("|%-08s|\n", "vikos"); // |vikos - - -| // неопределенное поведение , преимущество у '-'
	// //printf("|%08s|\n", "vikos");  // |0 0 0 vikos| // неопределенное поведение
	// printf("\n***|---------------------------|***\n\n");
	// // точность
	// //printf("|%.2s|\n", "vikos"); // |vi|
	// //printf("|%.8s|\n", "vikos"); // |vikos|
	// printf("\n***|---------------------------|***\n\n");
	// // флаг ширина точность
	// printf("\n***|---------------------------|***\n\n");
	printf("|%2.2s|\n", "vikos"); // |vi|
	ft_printf("|%2.2s|\n", "vikos"); // |vi|
	printf("|%4.2s|\n", "vikos"); // |- - vi|
	ft_printf("|%4.2s|\n", "vikos"); // |- - vi|
	printf("|%8.2s|\n", "vikos"); // |- - - - - - vi
	ft_printf("|%8.2s|\n", "vikos"); // |- - - - - - vi||
	// printf("\n***|---------------------------|***\n\n");
	printf("|%2.8s|\n", "vikos"); // |vikos|
	ft_printf("|%2.8s|\n", "vikos"); // |vikos|
	printf("|%4.8s|\n", "vikos"); // |vikos|
	ft_printf("|%4.8s|\n", "vikos"); // |vikos|
	printf("|%10.8s|\n", "vikos");// |- - - - - vikos|
	ft_printf("|%10.8s|\n", "vikos");// |- - - - - vikos|
	printf("|%10.6s|\n", "vikos");// |- - - - - vikos|
	ft_printf("|%10.6s|\n", "vikos");// |- - - - - vikos|
	
	printf("hello, %s.\n", "gavin");
	ft_printf("hello, %s.\n", "gavin");
	printf("\n%-*.13s\n", 13, "vikaaa"); 
	ft_printf("\n%-*.13s\n", 13, "vikaaa"); // vikaaa       vikaaa - 7 ghj,tkjd
	// printf("%-*.13d\n", 13, 17);
	
	// ft_printf("hello, %s.", "gavin");
    // ft_printf("%-*.13s\n", 13, "vikaaa");
	// ft_printf("%-*.13d\n", 13, 17);
	
	//------------type_c-----------//
	// char a1; 
	// a1 = 'b';
	// printf ("g\n");
	// ft_printf ("g");
	// printf ("|%c|\n", a1); // c
	// printf ("|%5c|\n", a1); // - - - - c
	// printf ("|%-5c|\n", a1); // c - - - -
	// printf ("|%05c|\n", a1); // 0 0 0 0 c // неопределенное поведение
	// ft_printf ("|%c|\n", a1); // c
	// ft_printf ("|%5c|\n", a1); // - - - - c
	// ft_printf ("|%-5c|\n", a1); // c - - - -
	// ft_printf ("|%05c|\n", a); // 0 0 0 0 c // неопределенное поведение

	// printf("\n***|---------------------------|***\n\n");

	ft_printf("%-*.13d\n", 13, 17);
    printf("\n%-*.13s\n", 13, "vikaaa");
    // ft_printf("%-*.13s\n", 13, "vikaaa");
	// printf("hello, %s.", "gavin");
	// ft_printf("me:%*.4d|\n", -5, -9477);
	// printf("pf:%*.4d|\n\n", -5, -9477);
	// ft_printf("me:%*.2d|\n", 4, -9477);
	// printf("pf:%*.2d|\n\n", 4, -9477);
	// ft_printf("me:%*.4d|\n", -4, 9477);
	// printf("pf:%*.4d|\n\n", -4, 9477);
	// ft_printf("me:%*.4d|\n", 4, 9477);
	// printf("pf:%*.4d|\n\n", 4, 9477);
	// ft_printf("me:%*.3d|\n", 8, -9477);
	// printf("pf:%*.3d|\n\n", 8, -9477);
	// ft_printf("me:%*.4d|\n", -8, -9477);
	// printf("pf:%*.4d|\n\n", -8, -9477);
	// ft_printf("me:%*.5d|\n", 8, -9477);
	// printf("pf:%*.5d|\n\n", 8, -9477);
	// ft_printf("me:%*.4d|\n", 8, 9477);
	// printf("pf:%*.4d|\n\n", 8, 9477);
	// ft_printf("me:%*.4d|\n", -8, 9477);
	// printf("pf:%*.4d|\n\n", -8, 9477);
	// ft_printf("me:%*.2d|\n", 8, 9477);
	// printf("pf:%*.2d|\n\n", 8, 9477);
    //ft_printf("\n***|---------------------------|***\n");
	// printf("\n***|---------------------------|***\n");
	// ft_printf("me:%*.*d|\n", 4, 10, 1332);
	// printf("pf:%*.*d|\n\n", 4, 10, 1332);
	// ft_printf("me:%*.*d|\n", -6, 10, -31332);
	// printf("pf:%*.*d|\n\n", -6, 10, -31332);
	// ft_printf("me:%*.*d|\n", -5, 10, 31332);
	// printf("pf:%*.*d|\n\n", -5, 10, 31332);
	// ft_printf("me:%*.*d|\n", -5, 10, -31332);
	// printf("pf:%*.*d|\n\n", -5, 10, -31332);
	// ft_printf("me:%*.*d|\n", -4, -10, -31332);
	// printf("pf:%*.*d|\n\n", -4, -10, -31332);
	// ft_printf("me:%*.*d|\n", -6, 7, -31332);
	// printf("pf:%*.*d|\n\n", -6, 7, -31332);
	// ft_printf("me:%*.*d|\n", -6, -7, -31332);
	// printf("pf:%*.*d|\n\n", -6, -7, -31332);
	// ft_printf("me:%*.*d|\n", 5, 10, 31332);
	// printf("pf:%*.*d|\n\n", 5, 10, 31332);

	// printf("\n***|---------------------------|***\n\n");
	// ft_printf("me:%*.*d|\n", 8, 5, 1122);
	// printf("pf:%*.*d|\n\n", 8, 5, 1122);         ///
	// ft_printf("me:%*.*d|\n", 6, 8, -1122222);
	// printf("pf:%*.*d|\n\n", 6, 8, -1122222);		///
	// ft_printf("me:%*.*d|\n", 7, 7, -1122);
	// printf("pf:%*.*d|\n\n", 7, 7, -1122);
	// ft_printf("me:%*.*d|\n", 10, 15, -1122);
	// printf("pf:%*.*d|\n\n", 10,  15, -1122);
	// ft_printf("me:%*.*d|\n", 7, 9, -1122666);
	// printf("pf:%*.*d|\n\n", 7, 9, -1122666);
	// ft_printf("me:%*.*d|\n", 15, 9, -1122666);
	// printf("pf:%*.*d|\n\n", 15, 9, -1122666);
// 	ft_printf("me:%8.5d|\n", 34);
// 	printf("pf:%8.5d|\n\n", 34);
// ​

	// ft_printf("me:%*.*d|\n", -20, 11, 1111226);
	// printf("pf:%*.*d|\n\n", -20, 11, 1111226);
	// ft_printf("me:%0*d|\n", 10, 10);
	// printf("me:%0*d|\n", 10, 10);

	//ft_printf("%-8.5d|\n", 34);
	//printf("%-8.5d|\n", 34);
	//ft_printf("%-10.2d\n", 33333);
	//printf("%-10.2d\n", 33333);
	//ft_printf("%-3.7d\n", -33333);
	// ft_printf("|%    -d|\n", 3333);
	// printf("\n|%   3d|\n", 3333);
	//ft_printf("%-10.5d\n", 33);
	//printf("%-10.5d\n", 33);
	//ft_printf("%-8.3d\n", -8473);
	//printf("%-8.3d\n", -8473);
	//ft_printf("%-3.3d\n", 6983);
	//printf("%-3.3d\n", 6983);
	//ft_printf("%-*.*d\n", -10, 5, 6983);
	//printf("%-*.*d\n", -10, 5, 6983);
	//ft_printf("%-*.*d\n", -10, 2, 33333);
	//printf("%-*.*d\n", -10, 2, 33333);
	//ft_printf("%-*.*d\n", -10, 6, -33333); //
	//printf("%-*.*d\n", -10, 6, -33333);
	//ft_printf("%-*.*d\n", 10, -7, -33333); //
	//printf("%-*.*d\n", 10, -7, -33333);
	//ft_printf("%-*.*d\n", -7, 10, -3333);
	//printf("%-*.*d\n", -7, 10, -3333);  //
	//ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	//printf("%% *.5i 42 == |%     *.5i|", 4, 42);

	//printf("this %x number", 17);
	//int a;
	//int b;s
	//char c;

	//b = 0;
	//a = 5636 % 16;

	//printf("%d", a);
	//printf("%d\n", len);
	//len = printf("Hello\n");
	//printf("%d\n", len);

	//printf("%d", a);
	return (0);
}
