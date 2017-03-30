/*
** IB.c for IB.c in /Users/macbook/Battle For Midgard
** 
** Made by JONDOT Barbara
** Login   <jondot_b@etna-alternance.net>
** 
** Started on  Mon Dec  8 20:01:02 2016 JONDOT Barbara
** Last update Fri Dec  9 08:45:55 2016 VRIGNAUD camille
*/

#include "BFM.h"

int	buy_champi(t_player *player)
{
  if(player->rupees > 30)
    {
      player->rupees -= 30;
      player->champi += 1;
      my_putstr("Vous avez acheter un champignon\n");
      my_putstr("Il vous reste :");
      my_put_nbr(player->rupees);
      my_putstr(" rupees\n");
    }
  else
    my_putstr("Plus assez de Rupees, Allez combatre un peut \n");
  return(0);
}

int	buy_magic_box(t_player *player)
{
  if(player->rupees > 90)
    {
      player->rupees -= 90;
      player->magicbox += 1;
      my_putstr("Vous avez acheter une magic_box\n");
      my_putstr("Il vous reste :");
      my_put_nbr(player->rupees);
      my_putstr(" rupees\n");
    }
  else
    my_putstr("Plus assez de Rupees, Allez combatre un peut \n");
  return(0);
}

int	use_champi(t_player *player)
{
  char *str;
  int	i;
  t_content *content;
  int random;

  content = player->team->first;
  i = 0;
  my_putstr("Sur quelle pokémon voulez-vous utiliser ce champignon ?");
  str = readLine();
  random = rand() % (content->item->pvmax / 5) + 1;
  while (i < player->team->nb_elem)
    {
      if (my_strcmp(content->item->name , str) == 0)
	{
	  content->item->pv += random;
	}
      content = content->next;
      i++;
    }
  return(0);
}
