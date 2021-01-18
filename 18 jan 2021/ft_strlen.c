/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:35:01 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/15 20:41:08 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t		ft_strlen(const char *str)
{
    size_t	a;

	a = 0;
	while (str[a] != '\0')
		a++;
    return(a);
}

// int main()
// {
//    char s[] = "Hello";

//     printf("%zu\n", ft_strlen(s));
//  return (0);
// }

// int			main()
// {
// 	char	str;

// 	printf("%s", "Введите строку : ");
// 	scanf("%s", str);
// 	printf("%zu\n", ft_strlen(str));
// }