/*
** begin.c for c in /home/camille/Downloads/Partie 1
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Dec  8 10:41:30 2016 VRIGNAUD camille
** Last update Fri Dec  9 08:45:29 2016 VRIGNAUD camille
*/

#include "BFM.h"

static const t_begin begin[] = {
	{"magic catch", &magic},
	{"help me !!!", &help},
	{NULL, NULL}
};

void	info_creature(t_creature *creature)
{
  my_putstr("\nHo regarde un ");
  my_putstr(creature->name);
  my_putstr(" sauvage apparait \n");
  my_putstr("C'est stats sont de : \nlvl : ");
  my_put_nbr(creature->lvl);
  my_putstr("\npv : ");
  my_put_nbr(creature->pv);
  my_putstr("\npv max : ");
  my_put_nbr(creature->pvmax);
  my_putstr("\npm : ");
  my_put_nbr(creature->pm);
  my_putstr("\npm max : ");
  my_put_nbr(creature->pmmax);
  my_putstr("\n\n");
}

int 	beginning_loop(char *tab , int *i , t_creature *creature, t_player *player)
{
  int	n = 1;

  while (begin[*i].write != NULL)
    {
      if (my_strcmp(tab, "quit") == 0)
	return (0);
      if (my_strcmp(tab, begin[*i].write) == 0)
	{
	  if(begin[*i].fct_capture(creature , player) == 1)
    return (0);

	  n = 5;
	}
      *i = *i + 1;
    }
  return (n);
}

int		beginning(t_player *player)
{
  char		*tab;
  int		i;
  int		n;
  t_creature	*creature;

  n = 0;
  i = 0;
  while (42)
    {
      creature = getCreature();
      if (creature == NULL)
	return (0);
      info_creature(creature);
      aff_begin(player);
      tab = readLine();
      n = beginning_loop(tab , &i , creature , player);
      if (my_strcmp(tab , "") == 0 || n == 0 ||
        (tab[0] <= 65 || tab[0] >= 122))
	return (0);
      if (n != 5)
	my_putstr("commande inconnue");
      n = 0;
      i = 0;
    }
  return (0);
}


int		magic(t_creature *creature , t_player *player)
{
  int		random;
  t_content	*content;

  affiche_team(player);
  my_putstr("Vous lancez une Poke B... Magic Box !\n");
  random = (rand() % 3) + 1;
  my_putchar('\n');
  if (random == 1)
    {
      content = add_content(creature);
      add_content_to_team(player,content);
      my_putstr("Vous l'avez attrapé\n");
      if(oob(player) == 0)
        return (1);
    }
  else if (random > 1)
    {
      my_putstr("RATÉ\n");
      my_putstr("La créature lance charge-violente-qui-tue, vous fuyez !\n");
    }
  return (0);
}

int		help()
{
  my_putstr("Vous fuyez lâchement le combat... NOOB.\n");
  return (0);
}
