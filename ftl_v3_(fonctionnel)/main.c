/*
** main.c for cc in /home/camille/ftl
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Mon Nov  7 10:22:35 2016 VRIGNAUD camille
** Last update Fri Nov 11 10:18:09 2016 VRIGNAUD camille
*/

#include "ftl.h"

int		main()
{
  t_ship	*ship;

  my_putstr_color("clear","");
  srand (time (NULL));
  ship = create_ship();
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);
  game(ship);
  free(ship->weapon);
  free(ship->navigation);
  free(ship->drive);
  free(ship);
  return (0);
}
