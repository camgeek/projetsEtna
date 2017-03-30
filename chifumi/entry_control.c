/*
** entry_control.c for c in /home/camille/chifumi
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Fri Oct 28 12:26:37 2016 VRIGNAUD camille
** Last update Sat Oct 29 10:33:16 2016 VRIGNAUD camille
*/

#include "my_struct.h"

int	entry_control(char *str)
{
  if (my_strcmp(str, "pierre") == 0)
    return (1);
  if (my_strcmp(str, "feuille") == 0)
    return (2);
  if (my_strcmp(str, "ciseaux") == 0)
    return (3);
  if (my_strcmp(str, "spocke") == 0)
    return (4);
  if (my_strcmp(str, "lezard") == 0)
    return (5);
  if (my_strcmp(str, "q") == 0)
    return (66);
  return (99);
}
