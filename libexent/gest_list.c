/*
** gest_list.c for c in /home/camille/projet/libxtend/vrigna_c/libexent/liblist
**
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
**
** Started on  Thu Feb  2 22:08:35 2017 VRIGNAUD camille
** Last update Sat Feb 11 12:39:12 2017 VRIGNAUD camille
*/

#include "LIBLIST.h"

void	add_content_to_container(t_container *container, t_content *content)
{
  if (container->first == NULL && container->last == NULL)
    {
      content->index = container->nb_elem + 1;
      content->prev = NULL;
      container->nb_elem = 0;
      container->first = content;
      container->last = content;
      container->nb_elem = container->nb_elem + 1;
    }
  else
    {
      content->index = container->nb_elem + 1;
      content->prev = container->last;
      content->next = NULL;
      container->last->next = content;
      container->last = content;
      container->nb_elem = container->nb_elem + 1;
    }
}

void	del_content_from_container(t_container *container, t_content *content)
{
  container->nb_elem = container->nb_elem - 1;
  if (content->prev == NULL && content->next == NULL)
    {
      container->first = NULL;
      container->last = NULL;
    }
  else if (container->first == content)
    {
      content->next->prev = NULL;
      container->first = content->next;
      container->first = index_init(container);
    }
  else if (container->last == content)
    {
      content->prev->next = NULL;
      container->last = content->prev;
    }
  else
    {
      content->prev->next = content->next;
      content->next->prev = content->prev;
      container->first = index_init(container);
    }
}

t_content	*index_init(t_container *container)
{
  t_content	*conte1;
  int		i;

  i = 1;
  conte1 = container->first;
  while (i <= container->nb_elem)
    {
      conte1->index = i;
      if (conte1->next != NULL)
	conte1 = conte1->next;
      i = i + 1;
    }
  while (i > 1)
    {
      if (conte1->prev != NULL)
	conte1 = conte1->prev;
      i = i - 1;
    }
  return (conte1);
}

t_content	*recherche_by_index(t_container *container, int index)
{
  int		i;
  t_content	*conte1;

  i = 1;
  conte1 = container->first;
  while (i <= container->nb_elem)
    {
      if (conte1->index == index)
	return(conte1);
      if (conte1->next != NULL)
	conte1 = conte1->next;
      i = i + 1;
    }
  return (NULL);
}

t_content	*recherche_by_item(t_container *container, void *item)
{
  int		i;
  t_content	*conte1;

  i = 1;
  conte1 = container->first;
  while (i <= container->nb_elem)
    {
      if (conte1->item == item)
	return(conte1);
      if (conte1->next != NULL)
	conte1 = conte1->next;
      i = i + 1;
    }
  return (NULL);
}
