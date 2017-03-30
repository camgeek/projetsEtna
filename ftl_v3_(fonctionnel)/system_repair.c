/*
** system_repair.c for c in /home/camille/ftl
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Tue Nov  8 14:14:03 2016 VRIGNAUD camille
** Last update Fri Nov 11 09:31:48 2016 VRIGNAUD camille
*/

#include "ftl.h"

int	ftl_drive_system_repair(t_ship *ship)
{
  my_putstr("reparation du reacteur en cours...\n");
  free(ship->drive->system_state);
  ship->drive->system_state = my_strdup("online");
  if (ship->drive->system_state != NULL)
    {
      my_putstr("reparation termine! systeme reacteur OK!\n");
      return (1);
    }
  else
    {
      my_putstr("les reparation du reacteur ont echoue");
      return (0);
    }
}

int	navigation_tools_system_repair(t_ship *ship)
{
  my_putstr("reparation du systeme de navigation en cours...\n");
  free(ship->navigation->system_state);
  ship->navigation->system_state = my_strdup("online");
  if (ship->navigation->system_state != NULL)
    {
      my_putstr("reparation termine! systeme de navigation OK!\n");
      return (1);
    }
  else
    {
      my_putstr("les reparations des outils de navigations on echoue");
      return (0);
    }
}

int	weapon_system_repair(t_ship *ship)
{
  my_putstr("reparation du system d'armement en cours...\n");
  free(ship->weapon->system_state);
  ship->weapon->system_state = my_strdup("online");
  if (ship->weapon->system_state != NULL)
    {
      my_putstr("reparation termine! systeme d'armement OK!\n");
      return (1);
    }
  else
    {
      my_putstr("les reparation du systeme d'armement ont echoue");
      return (0);
    }
}

static const t_repair_command g_repair_command[] =
  {
    {"ftl_drive",&ftl_drive_system_repair},
    {"navigation_tools",&navigation_tools_system_repair},
    {"weapon",&weapon_system_repair},
    {NULL, NULL}
  };

void	system_repair_loop(t_ship *ship, char *str, int *i, int *test)
{
  while (g_repair_command[*i].repar != NULL)
    {
      if(my_strcmp(g_repair_command[*i].repar, str) == 0)
	{
	  g_repair_command[*i].fonction(ship);
	  *test = 1;
	}
      *i = *i + 1;
    }
}

int	system_repair(t_ship *ship)
{
  char	*str;
  int	i;
  int	test;

  test = 0;
  i = 0;
  my_putstr("repair_system~>");
  str = readLine();
  if (str == NULL)
    {
      my_putstr("[SYSTEM FAILURE]: le lecteur de commande est bloque");
      return (0);
    }
  else
    {
      system_repair_loop(ship, str, &i, &test);
      if (test != 1)
	{
	  my_putstr("[SYSTEM FAILURE]: commande inconnue\n");
	  return (0);
	}
      else
	return (1);
    }
}
