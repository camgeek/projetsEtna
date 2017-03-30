/*
** my_put_nbr.c for c in /home/camille/Jour05C
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Sat Oct 22 13:10:44 2016 VRIGNAUD camille
** Last update Sat Oct 29 10:42:29 2016 VRIGNAUD camille
*/

#include "my_struct.h"

void	my_put_nbr(int n)
{
  long	nlong;
  int	temp;

  nlong = n,
  temp = 1;
  if (n < 0)
    {
      my_putchar('-');
      nlong = nlong * -1;
    }
  while ((nlong / temp ) >= 10 )
    {
      temp = temp * 10;
    }
  while (temp > 0)
    {
      my_putchar((nlong / temp)%10 + 48);
      temp = temp / 10;
    }
}
