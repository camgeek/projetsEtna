/*
** my_strlen.c for c in /home/camille/projet/libxtend/vrigna_c/libexent/liblist
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Feb  2 22:12:28 2017 VRIGNAUD camille
** Last update Sat Feb 11 12:47:54 2017 VRIGNAUD camille
*/

#include "LIBLIST.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (*str != '\0')
    {
      str++;
      i++;
    }
  return (i);
}
