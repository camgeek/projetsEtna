/*
** my_putstr.c for my_putstr.c in /Users/macbook/Battle For Midgard
** 
** Made by JONDOT Barbara
** Login   <jondot_b@etna-alternance.net>
** 
** Started on  Mon Dec  5 16:19:35 2016 JONDOT Barbara
** Last update Mon Dec  5 16:19:42 2016 JONDOT Barbara
*/

#include "BFM.h"

void	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str++;
    }
}
