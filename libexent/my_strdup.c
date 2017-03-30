B/*
** my_strdup.c for  in /home/camille/projet/libxtend/vrigna_c/libexent/liblist
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Feb  2 22:12:15 2017 VRIGNAUD camille
** Last update Thu Feb 23 23:39:56 2017 VRIGNAUD camille
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "LIBLIST.h"

char	*my_strdup(char *str)
{
  char	*new_str;
  int	i;

  new_str = malloc((my_strlen(str) + 10) *(sizeof(char*)));
  i = 0;
  if (new_str == NULL)
    return (NULL);
  while (str[i])
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}
