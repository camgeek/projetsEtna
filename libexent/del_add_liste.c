/*
** del_add_liste.c for  in /home/camille/projet/libxtend/vrigna_c/libexent/liblist
**
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
**
** Started on  Thu Feb  2 22:07:15 2017 VRIGNAUD camille
** Last update Sat Feb 11 12:37:45 2017 VRIGNAUD camille
*/

#include "LIBLIST.h"

t_container	*add_liste()
{
  t_container	*container;

  container = malloc(sizeof(*container));
  if (container == NULL)
    {
      my_putstr("erreur");
      return (NULL);
    }
  else
    {
      container->first = NULL;
      container->last = NULL;
      container->nb_elem = 0;
      my_putstr("ajout");
      return (container);
    }
}

void		del_liste(t_container *container)
{
  t_content	*conte1;
  int		i;

  i = 1;
  conte1 = container->first;
  while (i <= container->nb_elem)
    {
      if (conte1->next != NULL)
	{
	  conte1 = conte1->next;
	  free(conte1->prev);
	}
      else
	free(conte1);
      i = i + 1;
    }
  free(container->first);
  free(container->last);
  free(container);
}

void		add_content(t_container *container, void * item)
{
  t_content	*content;

  content = malloc(sizeof(*content));
  content->item = item;
  add_content_to_container(container, content);
}
