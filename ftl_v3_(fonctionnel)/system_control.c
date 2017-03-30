/*
** system_control.c for c in /home/camille/ftl
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Tue Nov  8 11:04:28 2016 VRIGNAUD camille
** Last update Fri Nov 11 09:51:10 2016 VRIGNAUD camille
*/

#include "ftl.h"

void	ftl_drive_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du reacteur en cours...");
  if (my_strcmp(ship->drive->system_state, "online") == 0)
    my_putstr_color("green", "reacteur OK!\n");
  else
    my_putstr_color("red", " reacteur hors service!\n");
}

void	navigation_tools_system_check(t_ship *ship)
{
  my_putstr_color("yellow","verification du system de navigation en cours...");
  if (my_strcmp(ship->navigation->system_state, "online") == 0)
    my_putstr_color("green"," systeme de navigation OK!\n");
  else
    my_putstr_color("red"," systeme de navigation hors service!\n");
}

void	weapon_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du systeme d'armement  en cours...");
  if (my_strcmp(ship->weapon->system_state, "online") == 0)
    my_putstr_color("green"," systeme d'armement OK!\n");
  else
    my_putstr_color("red", " systeme d'armement hors service!\n");
}

void	system_control(t_ship *ship)
{
  ftl_drive_system_check(ship);
  weapon_system_check(ship);
  navigation_tools_system_check(ship);
}
