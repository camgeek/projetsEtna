/*
** container.c for c in /home/camille
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Mon Nov  7 14:46:43 2016 VRIGNAUD camille
** Last update Thu Dec  8 10:54:06 2016 VRIGNAUD camille
*/

#include "BFM.h"
#include <stdio.h>

int		add_team_to_player(t_player *player)
{
  t_container	*container;

  container = malloc(sizeof(*container));
  if (container == NULL)
    {
      my_putstr("problème add_container_to_player");
      return (0);
    }
  else
    {
      container->first = NULL;
      container->last = NULL;
      container->nb_elem = 0;
      player->team = container;
      my_putstr("Ajout du container fait \n");
      return (1);
    }
}

t_content   *add_content(t_creature *creature)
{
  t_content *content;

  content = malloc(sizeof(t_content));
  if (content == NULL)
    {
      my_putstr("problème add_content");
      return (0);
    }
  else
    {
      content->item = creature;
      my_putstr("Création du content OK\n");
      return (content);
    }
}


void	add_content_to_team(t_player *player, t_content *content)
{
  if (player->team->first == NULL && player->team->last == NULL)
    {
      content->prev = NULL;
      player->team->nb_elem = 0;
      player->team->first = content;
      player->team->last = content;
      player->team->nb_elem = player->team->nb_elem + 1;
    }
  else
    {
      content->prev = player->team->last;
      content->next = NULL;
      player->team->last->next = content;
      player->team->last = content;
      player->team->nb_elem = player->team->nb_elem + 1;
    }
}

void  del_content_from_container(t_player *player, t_content *content)
{
  player->team->nb_elem = player->team->nb_elem - 1;
  if (content->prev == NULL && content->next == NULL)
    {
      player->team->first = NULL;
      player->team->last = NULL;
    }
  else if (player->team->first == content)
    {
      content->next->prev = NULL;
      player->team->first = content->next;
    }
  else if (player->team->last == content)
    {
      content->prev->next = NULL;
      player->team->last = content->prev;
    }
 else
   {
     content->prev->next = content->next;
     content->next->prev = content->prev;
   }
}
