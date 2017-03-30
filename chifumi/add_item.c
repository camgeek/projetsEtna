/*
** add_item.c for c in /home/camille/chifumi
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Oct 27 18:55:06 2016 VRIGNAUD camille
** Last update Sat Oct 29 12:47:52 2016 VRIGNAUD camille
*/

#include "my_struct.h"
#include <stdlib.h>

t_joueur	*add_item(t_joueur *joueur, int score, char *stroke)
{
  t_joueur	*node;

  node = malloc(sizeof(*node));
  if (node == NULL)
    return (NULL);
  node->next = joueur;
  node->score = score;
  node->stroke = stroke;
  return (node);
}
