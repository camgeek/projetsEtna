/*
** start.c for c in /home/camille/Downloads/Partie 1
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Dec  8 10:54:25 2016 VRIGNAUD camille
** Last update Fri Dec  9 08:48:23 2016 VRIGNAUD camille
*/

#include "BFM.h"

t_player	*add_player(char **argv)
{
  t_player	*player;
  if ((player = malloc(sizeof(t_player))) == NULL)
    return (NULL);
  player->name = my_strdup(argv[2]);
  if (!player->name)
    return (NULL);
  player->magicbox = 5;
  player->champi = 0;
  player->rupees = 420;
  return (player);
}

void		Start(char **argv)
{
  t_player	*player;

  player = add_player(argv);
  if (player != NULL)
    {
      if (add_team_to_player(player) != 0)
	{
	  my_putstr("Bienvenue ");
	  my_putstr(player->name);
	  beginning(player);
	  free(player);
	  free(player->team);
	}
    }
  else
    {
      my_putstr("erreur");
    }
}

void	affiche_team(t_player *player)
{
  if (player->team->nb_elem != 0)
    {
      t_content *bolos;
      int n = 0;
      bolos = player->team->first;
      my_putstr("\n-------------------");
      my_putstr("\n Votre team :\n");
      while (n < player->team->nb_elem)
	{
	  my_putstr(bolos->item->name);
	  my_putstr(" vie :");
	  my_put_nbr(bolos->item->pv);
	  my_putstr("\n");
	  bolos = bolos->next;
	  n = n + 1;
	}
      my_putstr("--------------------\n");
    }
}

void	aff_begin(t_player *player)
{
  my_putstr("\nQue faire, ");
  my_putstr(player->name);
  my_putstr("  ?! ~");
}
