/*
** IB.c for IB.c in /Users/macbook/Battle For Midgard
** 
** Made by JONDOT Barbara
** Login   <jondot_b@etna-alternance.net>
** 
** Started on  Mon Dec  5 16:17:45 2016 JONDOT Barbara
** Last update Fri Dec  9 09:07:01 2016 VRIGNAUD camille
*/

#include "BFM.h"

static const t_IB IB[] = {
	{"slash", &slash},
	{"fire", &fire},
	{"gamble", &gamble},
	{"rest", &rest},
	{"\0", NULL}
};

void    ib_end(t_creature *crea2, t_content *content, t_player *player)
{
  int gain;

  gain = rand() % (120 - 91) + 90;
  my_putstr("\n --------------------------------\n");
  if (crea2->pv == -99)
    my_putstr("\n Bien attraper\n");
  else if (crea2->pv <= 0)
    {
      my_putstr("\nBravo vous avez tuer ");
      my_putstr(crea2->name);
      my_putstr("\n Vous gagner :");
      my_put_nbr(gain);
      player->rupees += gain;
      my_putstr("\n");
    }
  if (content->item->pv <= 0)
    {
      my_putstr("Non votre créature c'est fait tuer ");
      my_putstr(", elle ne fait maintenant plus partit de votre team\n\n");
      del_content_from_container(player, content);
    }
}

void	ib_catch(char *tab, t_player *player , t_creature *crea2)
{
  if (my_strcmp(tab, "catch") == 0)
    {
      if (catch_ib(player , crea2) != 0)
	crea2->pv = -99;
    }
}

int 	ib_loop(t_content *content, t_creature *crea2, t_player *player, int *i)
{
  char	*tab;

  while (content->item->pv > 0 && crea2->pv > 0)
    {
      my_putstr("IB - A l'attaque ! ~ ");
      tab = readLine();
      while (my_strcmp(IB[*i].write, "\0") != 0)
	{
	  if (my_strcmp(tab, "quit") == 0)
	    return (0);
	  if (my_strcmp(tab, IB[*i].write) == 0)
	    {
	      IB[*i].function(crea2 , content->item);
	      attack(content->item, crea2);
	    }
	  *i = *i + 1;
	}
      ib_catch(tab, player, crea2);
      *i = 0;
    }
  return (0);
}

int		ib(t_content *content , t_player *player)
{
  int		i;
  t_creature *crea2;

  crea2 = getCreature();
  info_creature(crea2);
  i = 0;
  ib_loop(content, crea2, player, &i);
  ib_end(crea2, content, player);
  return (0);
}

