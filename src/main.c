/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevelyne <mevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:42:44 by swarner           #+#    #+#             */
/*   Updated: 2019/07/19 20:12:33 by mevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
#include <float.h>
#define TEST "%23.u|%-23.u|%023.u\n", UINT_MAX, UINT_MAX, UINT_MAX

int	main(void) {
//    void    *p = NULL;

//	printf("1\n");
//	ft_printf("2\n");
//
//	printf("%%\n");
//	ft_printf("%%\n");
//
//	printf("%s\n",  "Hello World");
//	ft_printf("%s\n", "Hello World");
//
//	printf("%c\n", 'Y');
//	ft_printf("%c\n", 'Y');
//
//	printf("%i\n", 42);
//    ft_printf("%i\n", 42);
//
//    printf("%d\n", -4242);
//    ft_printf("%d\n", -4242);
//
//    printf("%u\n", -42);
//    ft_printf("%u\n", -42);
//
//    printf("%o\n", -4242);
//    ft_printf("%o\n", -4242);
//
////    printf("%b\n", 4242);
////    ft_printf("%b\n", 4242);
//
//    printf("%x\n", 42424242);
//    ft_printf("%x\n", 42424242);
//
//    printf("%X\n", -42424242);
//    ft_printf("%X\n", -42424242);
//
//    printf("%p\n", p);
//    ft_printf("%p\n", p);
//
//    printf("%x\n", -42424242);
//    ft_printf("%x\n", -42424242);
//
//    // printf("{%s}\n", 0);
//    // ft_printf("{%s}\n", 0);
//
//    printf("%s\n", "abc");
//    ft_printf("%s\n", "abc");
//    printf("%o\n", 42);
//    printf("%#o\n", 42);
//
//    printf("%x\n", 42);
//    printf("%#x\n", 42);
//
//    printf("%X\n", 42);
//    printf("%#X\n", 42);
//
//    printf("%u\n", 42);
//    printf("%#u\n", 42);
//    ft_printf("aa%%bb");


	// ft_printf("%04i\n", 12);
	// printf("%04i\n\n", 12);

	// ft_printf("%-4i|\n", 1);
	// printf("%-4i|\n\n", 1);

	// ft_printf("%+i\n", 1);
	// printf("%+i\n\n", 1);

	// ft_printf("%#x\n", 1);
	// printf("%#x\n\n", 1);

	// ft_printf("% 4i\n", 12);
	// printf("% 4i\n", 12);

//	ft_printf("%-10x|\n\n", 42);
	// printf("%2%\n");
	// ft_printf("%2%\n");

//
//	printf("%hhi\n", -42);
//	ft_printf("%hhi\n\n", -42);
//
//	printf("%hi\n", -42);
//	ft_printf("%hi\n\n", -42);
//
//	printf("%i\n", -42);
//	ft_printf("%i\n\n", -42);
//
//    printf("%lli\n", -42);
//    ft_printf("%lli\n\n", -42);
//
//    ft_printf("%5i\n", -42);
//    ft_printf("%5%\n");
//
	//printf("%   %", "test");
	//ft_printf("%   %", "test");
//    ft_printf("%c\n", '\0');
//    ft_printf("%s", "abc");
//    ft_printf("@moulitest: %s", NULL);

//    ft_printf("\n");
//    ft_printf("%%\n");
//    ft_printf("%d\n", 42);
//    ft_printf("%d%d\n", 42, 41);
//    ft_printf("%d%d%d\n", 42, 43, 44);
//    ft_printf("%ld\n", 2147483647);
//    ft_printf("%lld\n", 9223372036854775807);
//    ft_printf("%x\n", 505);
//    ft_printf("%X\n", 505);
//    ft_printf("%p\n", &ft_printf);
//    ft_printf("%20.15d\n", 54321);
//    ft_printf("%-10d\n", 3);
//    ft_printf("% d\n", 3);
//    ft_printf("%+d\n", 3);
//    ft_printf("%010d\n", 1);
//    ft_printf("%hhd\n", 0);
//    ft_printf("%jd\n", 9223372036854775807);
//    ft_printf("%zd\n", 4294967295);
//    ft_printf("%\n");
//    ft_printf("%U\n", 4294967295);
//    ft_printf("%u\n", 4294967295);
//    ft_printf("%o\n", 40);
//    ft_printf("%%#08x\n", 42);
//    ft_printf("%x\n", 1000);
//    ft_printf("%#X\n", 1000);
//    ft_printf("%s\n", NULL);
//    ft_printf("%S\n", L"ݗݜशব");
//    ft_printf("%s%s\n", "test", "test");
//    ft_printf("%s%s%s\n", "test", "test", "test");
//    ft_printf("%C\n", 15000);

//    printf("%c\n", 0);
//    ft_printf("%c", 0);
//    ft_printf("null %c and text", 0);
//    printf("\nnull %c and text", 0);

//    ft_printf("%#8x\n", 42);
//    printf("%#8x\n\n", 42);
//    ft_printf("%#8x\n", 0);
//    printf("%#8x\n\n", 0);
//    ft_printf("%X\n", 42);
//    printf("%X", 42);

//    ft_printf("%#-08x\n", 42);
//    printf("%#-08x\n\n", 42);
//    printf("%#+08i\n\n", 42);
//
//    ft_printf("%-10x\n", 42);
//    printf("%-10x", 42);
// <<<<<<< HEAD



//    ft_printf("null %c and text\n", 0);
//    printf("null %c and text\n\n", 0);

//    ft_printf("{%3c}\n", 0);
//	printf("{%3c}\n", 0);
//    ft_printf("@moulitest: %c\n", 0);
//    printf("@moulitest: %c\n", 0);


//    ft_printf("%05d\n", -42);
//    printf("%05d\n\n", -42);
//
//    ft_printf("%0+5d\n", -42);
//    printf("%0+5d", -42);

//
//	char * string = "String";
//	printf("%20.2s\n","test");
//	ft_printf("%20.2s\n","test");
//
//	//ft_printf("%-5s\n"," ");
//	//printf("%-5s"," ");
//	//ft_printf("%s %s\n", NULL, string);
//
//
//    printf("%0+5d\n", -42);
//
//	ft_printf("%0+5d\n", 42);

//	ft_printf("@moulitest: %.10o\n", 42);
//	printf("@moulitest: %.10o\n\n", 42);
//
//	ft_printf("%5.2x\n", 5427);
//	printf("%5.2x\n\n", 5427);
//
//	ft_printf("%-10.5d\n", 4242);
//	printf("%-10.5d\n\n", 4242);
//
//	ft_printf("%.2d\n", 4242);
//	printf("%.2d\n\n", 4242);


//	printf("{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
//	ft_printf("{%f}{%lf}{%Lf}\n\n", 1.42, 1.42, 1.42l);
//
//	printf("{%f}{%lf}{%Lf}\n", -1.42, -1.42, -1.42l);
//	ft_printf("{%f}{%lf}{%Lf}\n\n", -1.42, -1.42, -1.42l);
//
//	printf("{%f}{%lf}{%Lf}\n", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
//	ft_printf("{%f}{%lf}{%Lf}\n\n", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
//
//	printf("{%f}{%lf}{%Lf}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);
//	ft_printf("{%f}{%lf}{%Lf}\n\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);

//	double a = 1656.445645645648651445686786546465841518646186;
//	printf("%f\n", a);
//	ft_printf("%f\n\n", a);

//	printf("%#o\n", 42);
//	ft_printf("%#o\n\n", 42);
//	printf("%#o\n", INT_MAX);
//	ft_printf("%#o\n\n", INT_MAX);

//	printf("%#o\n", 0);
//	ft_printf("%#o\n\n", 0);

//	printf("{% 03d}\n", 0);
//	ft_printf("{% 03d}\n\n", 0);

//	printf("%.4d\n", 42);
//	ft_printf("%.4d\n\n", 42);

//	printf("%.4d\n", -424242);
//	ft_printf("%.4d\n\n", -424242);

//	printf("%15.4d\n", -42);
//	ft_printf("%15.4d\n\n", -42);

//	printf("%.10d\n", -42);
//	ft_printf("%.10d", -42);

//	printf("%.d, %.0d\n", 0, 0);
//	ft_printf("%.d, %.0d\n", 0, 0);

//	printf("@moulitest: %5.x %5.0x\n", 0, 0);
//	ft_printf("@moulitest: %5.x %5.0x", 0, 0);

//	ft_printf("%.2s is a string\n", "");
//	printf("%.2s is a string", "");

//	ft_printf("%.2x\n", 5427);
//	printf("%.2x", 5427);

//	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
//	printf("@moulitest: %#.x %#.0x\n\n", 0, 0);
//
//	ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
//	printf("@moulitest: %#.o %#.0o\n\n", 0, 0);
//
//	ft_printf("@moulitest: %.o %.0o\n", 0, 0);
//	printf("@moulitest: %.o %.0o", 0, 0);

//	ft_printf("%03.2d\n", -1);
//	printf("%03.2d\n\n", -1);

//	ft_printf("%03.2d\n", 0);
//	printf("%03.2d\n\n", 0);

//	ft_printf("%03.2d\n", 1);
//	printf("%03.2d\n\n", 1);
//
//	ft_printf("@moulitest: %.10d\n", -42);
//	printf("@moulitest: %.10d\n", -42);

//	ft_printf("%03.2d\n", -1);
//	printf("%03.2d\n\n", -1);
//
//	ft_printf("% 10.5d\n", 4242);
//	printf("% 10.5d\n\n", 4242);
//
//	ft_printf("%+10.5d\n", 4242);
//	printf("%+10.5d\n\n", 4242);
//
//	ft_printf("%-+10.5d\n", 4242);
//	printf("%-+10.5d\n\n", 4242);



// _________________moulitest_________________________________________


//	ft_printf("%.4d\n", 424242);
//	printf("%.4d\n\n", 424242);
//
//	ft_printf("%.4d\n", -424242);
//	printf("%.4d\n\n", -424242);
//
//	ft_printf("%15.4d\n", 42);
//	printf("%15.4d\n\n", 42);

//	ft_printf("%15.4d\n", 424242);
//	printf("%15.4d\n\n", 424242);
//
//	ft_printf("%8.4d\n", 424242424);
//	printf("%8.4d\n\n", 424242424);

//	ft_printf("%15.4d\n", -42);
//	printf("%15.4d\n\n", -42);

//	ft_printf("%15.4d\n", -424242);
//	printf("%15.4d\n\n", -424242);
//
//	ft_printf("%8.4d\n", -424242424);
//	printf("%8.4d\n\n", -424242424);

//	ft_printf("%4.15d\n", 42);
//	printf("%4.15d\n\n", 42);
//
//	ft_printf("%4.15d\n", 424242);
//	printf("%4.15d\n\n", 424242);
//
//	ft_printf("%4.8d\n", 424242424);
//	printf("%4.8d\n\n", 424242424);

//	ft_printf("%4.15d\n", -42);
//	printf("%4.15d\n\n", -42);
//
//	ft_printf("%4.15d\n", -424242);
//	printf("%4.15d\n\n", -424242);
//
//	ft_printf("%4.8d\n", -424242424);
//	printf("%4.8d\n\n", -424242424);
//
//	ft_printf("%.d, %.0d\n", 0, 0);
//	printf("%.d, %.0d\n\n", 0, 0);
//
//	ft_printf("%.10d\n", -42);
//	printf("%.10d\n\n", -42);
//
//	ft_printf("%.4i\n", 42);
//	printf("%.4i\n\n", 42);
//
//	ft_printf("%15.4i\n", 42);
//	printf("%15.4i\n\n", 42);
//
//	ft_printf("%4.15i\n", 42);
//	printf("%4.15i\n\n", 42);
//
//	ft_printf("%.i, %.0i\n", 0, 0);
//	printf("%.i, %.0i\n\n", 0, 0);
//
//	ft_printf("%.4u\n", 42);
//	printf("%.4u\n\n", 42);
//
//	ft_printf("%.4u\n", 424242);
//	printf("%.4u\n\n", 424242);
//
//	ft_printf("%15.4u\n", 42);
//	printf("%15.4u\n\n", 42);
//
//	ft_printf("%15.4u\n", 424242);
//	printf("%15.4u\n\n", 424242);
//
//	ft_printf("%8.4u\n", 424242424);
//	printf("%8.4u\n\n", 424242424);
//
//	ft_printf("%4.15u\n", 42);
//	printf("%4.15u\n\n", 42);
//
//	ft_printf("%4.15u\n", 424242);
//	printf("%4.15u\n\n", 424242);
//
//	ft_printf("%4.8u\n", 424242424);
//	printf("%4.8u\n\n", 424242424);
//
//	ft_printf("%.u, %.0u\n", 0, 0);
//	printf("%.u, %.0u\n\n", 0, 0);

//    ft_printf("%.0p, %.p\n", 0, 0);
//    printf("%.0p, %.p\n\n", 0, 0);
//
//    ft_printf("{%5p}\n", 0);
//    printf("{%5p}\n\n", 0);

//    ft_printf("%2.9p\n", 1234);
//    printf("%2.9p", 1234);

//    ft_printf("%.5p\n", 0);
//    printf("%.5p", 0);

//    ft_printf("{%#.5x}\n", 1);
//    printf("{%#.5x}\n\n", 1);
//
//    ft_printf("%#.4o\n", 1);
//    printf("%#.4o\n\n", 1);



// ******************* FINAL 5 BUGS ******************

//    ft_printf("%s %d %p %% %x\n", "bonjour ", 42, &free, 42);
//    printf("%s %d %p %% %x\n\n", "bonjour ", 42, &free, 42);
//
//    int *c = malloc(1);
//    ft_printf("%s%d%p %%%i%o%u%x%X %c\n","bonjour", 42, &c, 42, 42, 42, 42, 42, 'c');
//    printf("%s%d%p %%%i%o%u%x%X %c\n\n","bonjour", 42, &c, 42, 42, 42, 42, 42, 'c');
//
//    ft_printf("%%%%%%%%%%\n");
//    printf("%%%%%%%%%%\n\n");
//
//    ft_printf("aa%%bb\n");
//    printf("aa%%bb\n\n");
//
//    ft_printf("a%ib%ic%id\n", 1, -2, 3);
//    printf("a%ib%ic%id", 1, -2, 3);


// ****************** CASES WITH \0 *****************

//    ft_printf("{%3c}\n", 0);
//    printf("{%3c}\n\n", 0);
//
//    ft_printf("%2c\n", 0);
//    printf("%2c\n\n", 0);
//
//    ft_printf("null %c and text\n", 0);
//    printf("null %c and text\n\n", 0);
//
//    ft_printf("@moulitest: %c\n", 0);
//    printf("@moulitest: %c\n", 0);

//	ft_printf("%.2x", 5427);
//	printf("%.2x", 5427);
//	int *test;
//	ft_printf("%hhd\n", 500);
//	printf("%hhd\n", 500);

	printf("%015.8f\n", 0., 0., 0., 0., 0., 0.);
	ft_printf("%015.8f\n\n", 0., 0., 0., 0., 0., 0.);

	printf("%f|%-f|%+f|% f|%#f|%0f\n", 0., 0., 0., 0., 0., 0.);
	ft_printf("%f|%-f|%+f|% f|%#f|%0f\n\n", 0., 0., 0., 0., 0., 0.);

	printf("%#.5x\n", 0U);
	ft_printf("%#.5x\n\n", 0U);

	printf("%#023x\n", 0U);
	ft_printf("%#023x\n\n", 0U);

	printf("% 1.5d\n", INT_MIN);
	ft_printf("% 1.5d\n\n", INT_MIN);

	printf("% 1i\n", INT_MIN);
	ft_printf("% 1i\n\n", INT_MIN);

    printf("%+ 1.5d\n", 0);
    ft_printf("%+ 1.5d\n\n", 0);

	printf("%1d|%-1d|%+1d|% 1d|%01d\n", 0, 0, 0, 0, 0);
	ft_printf("%1d|%-1d|%+1d|% 1d|%01d\n\n", 0, 0, 0, 0, 0);


	printf("%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\n", 0, 0, 0, 0, 0, 0);
	ft_printf("%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\n\n", 0, 0, 0, 0, 0, 0);

	printf("% 1.5d|%01.5d\n", 0, 0);
	ft_printf("% 1.5d|%01.5d\n\n", 0, 0);

	printf("% 1d|%-+ 01d\n", INT_MIN, INT_MIN);
	ft_printf("% 1d|%-+ 01d\n\n", INT_MIN, INT_MIN);

	printf("% 5f|%#5f|%05f\n", 0., 0., 0.);
	ft_printf("% 5f|%#5f|%05f\n\n", 0., 0., 0.);

	printf("%+ 23d\n", 0);
	ft_printf("%+ 23d\n\n", 0);


	printf("|%+ 1d|%+01d|% 01d|%-+ 01d\n", 0, 0, 0, 0);
	ft_printf("|%+ 1d|%+01d|% 01d|%-+ 01d\n\n", 0, 0, 0, 0);

	printf("% 1d\n", INT_MIN);
	ft_printf("% 1d\n\n", INT_MIN);

	printf("%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\n", 0, 0, 0, 0, 0, 0, 0);
	ft_printf("%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\n\n", 0, 0, 0, 0, 0, 0, 0);

//    ft_printf("%f");
//    printf();


// ***************

//    ft_printf("% d\n", 42);
//    printf("% d\n\n", 42);
//
//    ft_printf("%4.15d\n", 42);
//    printf("%4.15d\n\n", 42);
//
//    ft_printf("% 5.7d\n", 42);
//    printf("% 5.7d\n\n", 42);
//
//	ft_printf("%0+5d\n", -42);
//	printf("%0+5d\n\n", -42);
//
//    ft_printf("%010.7d\n", 4242);
//    printf("%010.7d\n\n", 4242);
//
//    ft_printf("%0+5d\n", 42);
//    printf("%0+5d\n\n", 42);
//
//	ft_printf("%+10.5d\n", 4242);
//	printf("%+10.5d\n\n", 4242);
//
//	ft_printf("{% 04d}\n", 0);
//	printf("{% 04d}\n\n", 0);
//
//    ft_printf("%02.2d\n", -1);
//    printf("%02.2d\n\n", -1);
//
//	ft_printf("%#08x\n", 42);
//	printf("%#08x\n\n", 42);
//
//	ft_printf("%010x\n", 542);
//	printf("%010x\n\n", 542);
}