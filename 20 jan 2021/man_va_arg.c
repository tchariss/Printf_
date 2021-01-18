/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_va_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:59:09 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/16 16:02:34 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// EXAMPLES
// The function foo takes a string of format characters and prints out the argument 
// associated with each format character based on the type.

void foo(char *fmt, ...)
{
	va_list ap, ap2;
	int d;
	char c, *s;

	va_start(ap, fmt);
	va_copy(ap2, ap);
	while (*fmt)
		switch(*fmt++)
		{
		case 's':                       /* string */
				s = va_arg(ap, char *);
				printf("string %s\n", s);
				break;
		case 'd':                       /* int */
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
        case 'c':                       /* char */
/* Note: char is promoted to int. */
            c = va_arg(ap, int);
			printf("char %c\n", c);
			break;
		}
	va_end(ap);

/* use ap2 to iterate over the arguments again */

	va_end(ap2);
}