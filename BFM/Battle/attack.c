/*
** attack.c for c in /home/camille/Downloads/Partie 1
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Dec  8 10:40:24 2016 VRIGNAUD camille
** Last update Thu Dec  8 10:57:51 2016 VRIGNAUD camille
*/

#include "BFM.h"

int	attack(t_creature *crea1, t_creature *crea2)
{
  int	random;

  random = (rand() % 4) + 1;
  if (random == 1)
    {
      slash(crea1, crea2);
    }
  else if (random == 2)
    {
      fire(crea1, crea2);
    }
  else if (random == 3)
    {
      gamble(crea1, crea2);
    }
  else if (random == 4)
    {
      rest(crea1, crea2);
    }
  return (0);
}

int   copie_ib(t_creature *crea_copie, t_creature *crea2 , t_player *player)
{
  t_content *content;


  crea_copie->lvl = crea2->lvl;
    crea_copie->pvmax = crea2->pvmax;
    crea_copie->pmmax = crea2->pmmax;
    crea_copie->pv = crea_copie->pvmax;
    crea_copie->pm = crea_copie->pmmax;
    info_crea2(crea_copie);
    content = add_content(crea_copie);
    add_content_to_team(player, content);
    my_putstr("\n La créature à été ajouter a la team");
    return (1);
}


int		catch_ib(t_player *player , t_creature *crea2)
{
  t_creature	*crea_copie;
  int		random;

  random = (rand() % crea2->pv) + 1;
  if (random > 1 && random < 5)
    {
      if ((crea_copie = malloc(sizeof(t_creature))) == NULL)
	return(0);

      my_putstr("\n Vous attrapez : ");
      my_putstr(crea2->name);
      crea_copie->name = my_strdup(crea2->name);
      if (crea2->name == NULL)
	return(0);
      return (copie_ib(crea_copie, crea2, player));
    }
  else
    {
      my_putstr("\nDommage vous n'avez pas capturé la créature !\n");
      return(0);
    }
}

void	info_crea2(t_creature *crea2)
{
	my_putstr("\n---------------");
	my_putstr("\nINFO CREATURE :");
	my_putstr("NOM : \n");
	my_putstr(crea2->name);
	my_putstr("\n lvl :");
	my_put_nbr(crea2->lvl);
	my_putstr("\npv : ");
	my_put_nbr(crea2->pv);
	my_putstr("\npv max : ");
	my_put_nbr(crea2->pvmax);
	my_putstr("\npm : ");
	my_put_nbr(crea2->pm);
	my_putstr("\npm max : ");
	my_put_nbr(crea2->pmmax);
	my_putstr("\n\n");
}
