/*
** container.c for c in /home/camille/ftl
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Mon Nov  7 14:46:43 2016 VRIGNAUD camille
** Last update Fri Nov 11 09:24:07 2016 VRIGNAUD camille
*/

#include "ftl.h"
#include <stdio.h>

int		add_container_to_ship(t_ship *ship)
{
  t_container	*container;

  my_putstr_color("yellow", "ajout du container en cours...\n");
  container = malloc(sizeof(*container));
  if (container == NULL)
    {
      my_putstr_color("red", " votre vaisseau a explose lorsque vous avez ");
      my_putstr_color("red", " poser le container\n");
      return (0);
    }
  else
    {
      container->first = NULL;
      container->last = NULL;
      container->nb_elem = 0;
      ship->container = container;
      my_putstr_color("green", "le container a ete ajoute avec succes!\n");
      return (1);
    }
}

void	add_freight_to_container(t_ship *ship, t_freight *freight)
{
  if (ship->container->first == NULL && ship->container->last == NULL)
    {
      freight->prev = NULL;
      ship->container->nb_elem = 0;
      ship->container->first = freight;
      ship->container->last = freight;
      ship->container->nb_elem = ship->container->nb_elem + 1;
    }
  else
    {
      freight->prev = ship->container->last;
      freight->next = NULL;
      ship->container->last->next = freight;
      ship->container->last = freight;
      ship->container->nb_elem = ship->container->nb_elem + 1;
    }
}

void	del_freight_from_container(t_ship *ship, t_freight *freight)
{
  ship->container->nb_elem = ship->container->nb_elem - 1;
  if (freight->prev == NULL && freight->next == NULL)
    {
      ship->container->first = NULL;
      ship->container->last = NULL;
    }
  else if (ship->container->first == freight)
    {
      freight->next->prev = NULL;
      ship->container->first = freight->next;
    }
  else if (ship->container->last == freight)
    {
      freight->prev->next = NULL;
      ship->container->last = freight->prev;
    }
 else
   {
     freight->prev->next = freight->next;
     freight->next->prev = freight->prev;
   }
}

void	get_bonus_loop(t_ship *ship, t_freight *freight)
{
  while (freight != NULL)
    {
      if (my_strcmp(freight->item, "attackbonus") == 0)
	{
	  ship->weapon->damage += 5;
	  my_putstr_color("green", "Vous avez gagner un bonus d'attaque !\n");
	}
      if (my_strcmp(freight->item, "evadebonus") == 0)
	{
	  ship->navigation->evade += 3;
	  my_putstr_color("green", "Vous avez gagner un bonus d'évasion !\n");
	}
      if (my_strcmp(freight->item,"energy") == 0)
	{
	  ship->drive->energy += 1;
	  my_putstr_color("green", "Vous avez une energie !\n");
	}
      del_freight_from_container(ship, freight);
      freight = freight->next;
    }
}

void		get_bonus(t_ship *ship)
{
  t_freight	*freight;

  freight = malloc(sizeof(*freight));
  if (freight != NULL)
    {
      freight = ship->container->first;
      get_bonus_loop(ship, freight);
      free (freight);
    }
  else
    my_putstr_color("red", "Une erreur c'est produit");
}
