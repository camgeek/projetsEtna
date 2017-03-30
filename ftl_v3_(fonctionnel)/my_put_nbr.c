/*
** my_put_nbr.c for c in /home/camille/Jour05C
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Sat Oct 22 13:10:44 2016 VRIGNAUD camille
** Last update Fri Nov 11 09:26:21 2016 VRIGNAUD camille
*/

#include "ftl.h"

void	my_put_nbr(int n)
{
  int temp;

  temp = 1;
  if (n < 0)
    {
      my_putchar('-');
      n = n * -1;
    }
  while ((n / temp ) >= 10 )
    {
      temp = temp * 10;
    }
  while (temp > 0)
    {
      my_putchar((n / temp)%10 + 48);
      temp = temp / 10;
    }
}
