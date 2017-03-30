/*
** my_strcat.c for c in /home/camille/Jour04C/ex6
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Fri Oct 21 16:09:00 2016 VRIGNAUD camille
** Last update Sat Feb 11 12:46:47 2017 VRIGNAUD camille
*/

#include "LIBLIST.h"

char	*my_strcat(char *dest, char *src)
{
  int lenght_tab;
  int i;
  int j;

  lenght_tab = my_strlen(src);
  i = 0;
  j = my_strlen(dest);

  while (i < lenght_tab)
    {
      dest[j] = src[i];
      j = j + 1;
      i = i + 1;
    }
  dest[my_strlen(dest)] = '\0';
  return (dest);
}
