/*
** my_putchar.c for c in /home/camille
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Sat Oct 15 19:11:23 2016 VRIGNAUD camille
** Last update Sat Oct 15 20:00:36 2016 VRIGNAUD camille
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
