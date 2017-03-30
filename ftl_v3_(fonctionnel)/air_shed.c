/*
** air_shed.c for c in /home/camille/ftl
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:49:04 2016 VRIGNAUD camille
** Last update Fri Nov 11 09:23:30 2016 VRIGNAUD camille
*/

#include "ftl.h"

t_ship		*create_ship()
{
  t_ship	*ship;

  ship = malloc(sizeof(*ship));
  if (ship == NULL)
    {
      my_putstr_color("red", "le vaisseau n'a pas pu etre construit ");
      my_putstr_color("red", "par de manque materiaux \n");
      return (NULL);
    }
  else
    {
      ship->hull = 50;
      ship->weapon = NULL;
      ship->drive = NULL;
      ship->navigation = NULL;
      ship->container = NULL;
      my_putstr_color("yellow", "construction du vaisseau en cours ...\n");
      my_putstr_color("green", "amelioration du vaisseau termine!\n");
    }
  return (ship);
}

int		add_weapon_to_ship(t_ship *ship)
{
  t_weapon	*weapon;
  my_putstr_color("yellow","ajout des armes en cours...\n");
  weapon = malloc(sizeof(*weapon));
  if (weapon == NULL)
    {
      my_putstr_color("red","votre vaisseau a explose quand vous avez tente");
      my_putstr_color("red","d'ajouter les armes\n");
      return (0);
    }
  else
    {
      weapon->damage = 10;
      weapon->system_state = my_strdup("online");
      ship->weapon = weapon;
      my_putstr_color("green","les armes on ete ajoutes avec succes!\n");
      return (1);
    }
}

int		add_ftl_drive_to_ship(t_ship *ship)
{
  t_ftl_drive	*drive;

  my_putstr_color("yellow","ajout du reacteur en cours...\n");
  drive = malloc(sizeof(*drive));
  if (drive == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque vous avez");
      my_putstr_color("red", " pose le reacteur");
      return (0);
    }
  else
    {
      drive->energy = 10;
      drive->system_state = my_strdup("online");
      ship->drive = drive;
      my_putstr_color("green", "le reacteur a ete ajoute avec succes!\n");
      return (1);
    }
}

int			add_navigation_tools_to_ship(t_ship *ship)
{
  t_navigation_tools	*navigation;

  my_putstr_color("yellow", "ajout des outils de navigations...\n");
  navigation = malloc(sizeof(*navigation));
  if (navigation == NULL)
    {
      my_putstr_color("red", "votre vaisseau a explose lorsque vous avez");
      my_putstr_color("red", " pose les outils de navigations\n");
      return (0);
    }
  else
    {
      navigation->sector = 0;
      navigation->evade = 25;
      navigation->system_state = my_strdup("online");
      ship->navigation = navigation;
      my_putstr_color("green", "les outils de navigations ont ete ajoutes ");
      my_putstr_color("green", "avec succes! \n");
      return (1);
    }
}
