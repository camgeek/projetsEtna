/*
** my_putchar.c for my_putchar.c in /Users/macbook/Battle For Midgard
** 
** Made by JONDOT Barbara
** Login   <jondot_b@etna-alternance.net>
** 
** Started on  Mon Dec  5 16:19:16 2016 JONDOT Barbara
** Last update Mon Dec  5 16:19:18 2016 JONDOT Barbara
*/

#include <unistd.h>
#include "BFM.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}
