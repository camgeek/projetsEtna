/*
** IB.c for IB.c in /Users/macbook/Battle For Midgard
** 
** Made by JONDOT Barbara
** Login   <jondot_b@etna-alternance.net>
** 
** Started on  Mon Dec  5 16:17:45 2016 JONDOT Barbara
** Last update Fri Dec  9 08:48:01 2016 VRIGNAUD camille
*/

#include "BFM.h"

t_OoB OoB[] = {
	{"team", &team},
	{"choosen", &choosen},
	{"fight", &fight},
	{"buy champi", &buy_champi},
	{"buy magic box", &buy_magic_box},
	{"use champi", &use_champi},
	{"\0", NULL}
};

int		oob(t_player *player)
{
  char	*tab;
  int		i;

  i = 0;
  while (42)
    {
      my_putstr("OoB - Que faire ? ~ ");
      tab = readLine();
      while (my_strcmp(OoB[i].write, "\0") != 0)
	{
	  if (my_strcmp(tab, "quit") == 0)
	    return (0);
	  if (my_strcmp(tab, OoB[i].write) == 0)
	    {
	      OoB[i].fctn(player);
	    }
	  i++;
	}
      i = 0;
    }
  return (0);
}

int		team(t_player *player)
{
  affiche_team(player);
  return (0);
}

void   choosen_end(t_content *chose, t_player *player, int n)
{
if (n == 0)
	my_putstr("\n Il n'y a aucun pokemon avec ce nom \n");
else
	ib(chose, player);
}

int		choosen(t_player *player)
{
  char *str;
  int i;
  t_content *content;
  t_content *chose;
  int n;

  n = 0;
  content = player->team->first;
  i = 0;
  my_putstr("Choisir votre créature\n");
  affiche_team(player);
  my_putstr("\n Taper le nom du pokemon que vous voulez envoyez au combat : ");
  str = readLine();
  while (i < player->team->nb_elem)
    {
      if (my_strcmp(content->item->name , str) == 0)
	{
	  chose = content;
	  n = 1;
	}
      content = content->next;
      i++;
    }
  choosen_end(chose, player, n);
  return (n);
}

int		fight(t_player *player)
{
	if (player->team->last != NULL)
	ib(player->team->last , player);
else
	my_putstr("\n Tous vos pokemon sont mort :O !!! \n");
	return (0);
}
