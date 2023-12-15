/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:44:50 by azbk              #+#    #+#             */
/*   Updated: 2023/11/13 11:55:14 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#include "ft_printf.h"

// int main()
// {
//     int a = 0;
//     int add = 0;
//     int a1 = 0;
//     int a2 = 0;
//     printf("\nBASE\n\n");
//     a1 = ft_printf("%%d/i/d : les %d et %i petits chats et %d chiens\n", -3, -2147483647, 20000);
//     a2 = printf("%%d/i/d : les %d et %i petits chats et %d chiens\n", -3, -2147483647, 20000);
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
//     a1 = ft_printf("%%/c : les %% de chiens sont plus grands que les %c quarts\n", '3');
//     a2 = printf("%%/c : les %% de chiens sont plus grands que les %c quarts\n", '3');
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
//     a1 = ft_printf("%%s : les %s \n", "trois petits chats");
//     a2 = printf("%%s : les %s \n", "trois petits chats");
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
//     a1 = ft_printf("%%p : sont ici : %p\n", &add);
//     a2 = printf("%%p : sont ici : %p\n", &add);
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
//     a1 = ft_printf("%%u : les %u gros chiens\n", -3042);
//     a2 = printf("%%u : les %u gros chiens\n", -3042);
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
//     a1 = ft_printf("%%X : les %X gros chiens\n", -3042);
//     a2 = printf("%%X : les %X gros chiens\n", -3042);
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);  
//     printf("\nTOUT A 0\n\n");
//     a1 = ft_printf("les %d et %i petits chats et %d chiens\n", 0, 0, 0);
//     a2 = printf("les %d et %i petits chats et %d chiens\n", 0, 0, 0);
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
//     a1 = ft_printf("les %% de chiens sont plus grands que les %c quarts\n", 0);
//     a2 = printf("les %% de chiens sont plus grands que les %c quarts\n", 0);
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
//     a1 = ft_printf("les %s sont ici : %p\n", "\0", NULL);
//     a2 = printf("les %s sont ici : %p\n", "\0", NULL);
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
//     a1 = ft_printf("les %u gros chiens sont %X fois plus gros\n", 0, 0);
//     a2 = printf("les %u gros chiens sont %X fois plus gros\n", 0, 0);
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
//     printf("\nTOUT AU MAXIMUM\n\n");
//     a1 = ft_printf("les %d et %i petits chats et %d chiens\n", INT_MAX, INT_MAX, INT_MIN);
//     a2 = printf("les %d et %i petits chats et %d chiens\n", INT_MAX, INT_MAX, INT_MIN);
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
//     a1 = ft_printf("les %% de chiens sont plus grands que les %c quarts\n", 131);
//     a2 = printf("les %% de chiens sont plus grands que les %c quarts\n", 131);
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
//     a1 = ft_printf("les %u gros chiens sont %X fois plus gros\n", UINT_MAX, -INT_MAX);
//     a2 = printf("les %u gros chiens sont %X fois plus gros\n", UINT_MAX, -INT_MAX);
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
//     printf("\nESSAI CRASH POINTEURS\n\n");
//     char    *str = NULL;
//     a1 = ft_printf("%s", str);    //OK : renvoit bien (null)
//     a2 = printf("%s", str);
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2); 
//     a1 = ft_printf("%p", str);   //OK : renvoit bien (nil)
//     a2 = printf("%p", str);  
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
//     a1 = ft_printf("%p\n", str);     //OK : renvoit bien (nil)
//     a2 = printf("%p\n", str);
//     if (a1 == a2)
//         printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
//     else
//         printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
// }
 

int main(void)
{
    int d = -1;
    int count = 0;
    
    ft_printf(" %p\n", -1);
    printf(" %p\n", -1);
    
    
}


// int main(int ac, char ** av)
// {
// 	signal(SIGSEGV, sigsegv);
// 	cout << FG_LYELLOW << "category: p" << RESET_ALL;
	
// 	testName = av[0];
// 	if (ac != 1)
// 		printTestNumber(av[1], TEST_LIMIT);
// 	cout << endl;
// 	TEST(1, print(" %p ", -1));
// 	TEST(2, print(" %p ", 1));
// 	TEST(3, print(" %p ", 15));
// 	TEST(4, print(" %p ", 16));
// 	TEST(5, print(" %p ", 17));
// 	TEST(6, print(" %p %p ", LONG_MIN, LONG_MAX));
// 	TEST(7, print(" %p %p ", INT_MIN, INT_MAX));
// 	TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));
// 	TEST(9, print(" %p %p ", 0, 0));
// 	cout << ENDL;
// 	return (0);
// }
