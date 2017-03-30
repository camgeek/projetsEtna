/*
** control_game_n.c for c in /home/camille/chifumi
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Fri Oct 28 12:52:02 2016 VRIGNAUD camille
** Last update Sat Oct 29 10:33:00 2016 VRIGNAUD camille
*/

#include "my_struct.h"

int	control_game_n(int human, int bot)
{
  if (human == bot)
    return (0);
  else if (human == 1 && bot == 2)
    return (2);
  else if (human == 1 && bot == 3)
    return (1);
  else if (human == 2 && bot == 1)
    return (2);
  else if (human == 2 && bot == 3)
    return (1);
  else if (human == 3 && bot == 1)
    return (2);
  else if (human == 3 && bot == 2)
    return (1);
  else if (human == 5 && bot == 1)
    return (1);
  else if (human == 5 && bot == 2)
    return (2);
  else if (human == 5 && bot == 3)
    return (1);
  else if (human == 5 && bot == 4)
    return (2);
  return (99);
}

void	aff_res(int res)
{
  if (res == 0)
    {
      my_putstr("\n----------------------------\n");
      my_putstr("Egaliter !\n");
      my_putstr("----------------------------\n");
    }
  else if (res == 1)
    {
      my_putstr("\n----------------------------\n");
      my_putstr("Vous gagnez \n");
      my_putstr("----------------------------\n");
    }
  else if (res == 2)
    {
      my_putstr("\n----------------------------\n");
      my_putstr("L'ordinateur gagne\n");
      my_putstr("----------------------------\n");
    }
}

int	control_game_e(int human, int bot)
{
  if (human == 1 && bot == 4)
    return (1);
  else if (human == 1 && bot == 5)
    return (2);
  else if (human == 2 && bot == 4)
    return (2);
  else if (human == 2 && bot == 5)
    return (1);
  else if (human == 3 && bot == 4)
    return (1);
  else if (human == 3 && bot == 5)
    return (2);
  else if (human == 4 && bot == 1)
    return (2);
  else if (human == 4 && bot == 2)
    return (1);
  else if (human == 4 && bot == 3)
    return (2);
  else if (human == 4 && bot == 5)
    return (1);
   return (99);
}
