/*
** my_strdup.c for c in /home/camille/Jour07C/ex2
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Mon Oct 24 13:43:27 2016 VRIGNAUD camille
** Last update Mon Oct 24 14:32:54 2016 VRIGNAUD camille
*/

#include <stdlib.h>

int	my_strlen(char *str);
char	*my_strcpy(char *dest, char *src);

char	*my_strdup(char *str)
{
  char	*tab;

  tab = malloc(my_strlen(str) * sizeof(*str));
  my_strcpy(tab, str);
  return (tab);
}
