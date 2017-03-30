/*
** random.c for c in /home/camille/ftl
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Wed Nov  9 14:48:11 2016 VRIGNAUD camille
** Last update Fri Nov 11 09:30:29 2016 VRIGNAUD camille
*/

#include "ftl.h"

int	my_random(int nb1, int nb2)
{
  int random;
  random = (rand()% nb1) + nb2;
  return(random);
}
