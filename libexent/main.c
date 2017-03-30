/*
** main.c for c in /home/camille/projet/libxtend/vrigna_c/libexent/liblist
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Feb  2 22:09:39 2017 VRIGNAUD camille
** Last update Thu Feb 23 23:37:21 2017 VRIGNAUD camille
*/

#include "LIBLIST.h"

void	loop_main(t_content *conte1)
{
  while (conte1 != NULL)
    {
      my_putstr(conte1->item);
      my_putstr("\n");
      my_put_nbr(conte1->index);
      conte1 = conte1->next;
    }
}

void	add_content_all(t_container *container)
{
  add_content(container, "objetA");
  add_content(container, "objetB");
  add_content(container, "objetC");
  add_content(container, "objetD");
}

void		test_argc(int argc, char **argv)
{
  t_container	*container1;
  t_content	*conte1;

  container1 = list_arg(argc, argv);
  conte1 = container1->first;
  while (conte1 != NULL)
    {
      my_putstr(conte1->item);
      my_putstr("\n");
      conte1 = conte1->next;
    }
}

void		test_conf_log()
{
  t_conflog   *conflog;
  int	      test;

  conflog = malloc(sizeof(*conflog));
  conflog->niveau = 1;
  conflog->chemin = my_strdup("journal1.log");
  create_log("ligne 80\n", 1, conflog);
  create_log("ligne 55 \n", 3, conflog);
  create_log("bug bug bug\n", 2, conflog);
  test = create_log("camille vrignaud\n", 4, conflog);
  my_put_nbr(test);
  free_conflog(conflog);
}

int		main(int argc, char **argv)
{
  t_container	*container;
  t_content	*content;
  t_content	*conte1;

  container = add_liste();
  add_content_all(container);
  content = malloc(sizeof(*content));
  if (recherche_by_item(container, "objetB") == NULL)
    return (0);
  content = recherche_by_item(container, "objetB");
  del_content_from_container(container,content);
  conte1 = container->first;
  loop_main(conte1);
  if (recherche_by_index(container, 2) == NULL)
    return (0);
  content = recherche_by_index(container, 2);
  my_putstr(content->item);
  del_liste(container);
  test_argc(argc, argv);
  test_conf_log();
  return (0);
}
