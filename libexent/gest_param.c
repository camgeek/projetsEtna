/*
** gest_param.c for c in /home/camille/projet/libxtend/vrigna_c/libexent/liblist
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Feb  2 22:08:52 2017 VRIGNAUD camille
** Last update Sat Feb 11 12:42:15 2017 VRIGNAUD camille
*/

#include "LIBLIST.h"

t_container	*list_arg(int argc, char **argv)
{
  t_container	*container;
  int		i;

  container = add_liste();
  i = 1;
  while (i < argc)
    {
      add_content(container, argv[i]);
      i = i + 1;
    }
  return (container);
}
