/*
** competences.c for competences.c in /Users/macbook/Battle For Midgard
** 
** Made by JONDOT Barbara
** Login   <jondot_b@etna-alternance.net>
** 
** Started on  Mon Dec  8 17:25:45 2016 JONDOT Barbara
** Last update Mon Dec  8 22:44:10 2016 JONDOT Barbara
*/

#include "BFM.h"

int	slash(t_creature *crea1, t_creature *crea2)
{

  if (crea2->pm > 0)
    {
      crea1->pv -= 15;
      my_putstr(crea2->name);
      my_putstr(" inflige 15 points de dégats à ");
      my_putstr(crea1->name);
      crea2->pm -= 3;
      my_putstr("\n");
      my_putstr(crea2->name);
      my_putstr(" Perd 3 PM\n");
    }
  else
    my_putstr("\n Pas assez de mana !");
  return (0);
}

int	fire(t_creature *crea1, t_creature *crea2)
{
  if (crea2->pm > 0)
    {
      crea1->pv -= 30;
      my_putstr(crea2->name);
      my_putstr(" inflige 30 points de dégats à ");
      my_putstr(crea1->name);
      crea2->pm -= 7;
      my_putstr("\n");
      my_putstr(crea1->name);
      my_putstr(" Perd 7 PM\n");
    }
  else
    my_putstr("\n Pas assez de mana !");
  return (0);
}

int	gamble(t_creature *crea1, t_creature *crea2)
{
  int	random;
  int	alea;

  random = (rand() % 100) + 1;
  if (random <= 50)
    {
      alea = (rand() % 20);
      crea1->pv -= alea;
      my_put_nbr(alea);
      my_putstr(" points de dégats ont été infligés à ");
      my_putstr(crea1->name);
      my_putstr("\n");
    }
  else if (random > 50)
    {
      alea = (rand() % 20);
      crea2->pv -= alea;
      my_put_nbr(alea);
      my_putstr(" points de dégats ont été infligés à\n");
      my_putstr(crea2->name);
      my_putstr("\n");
    }
  return (0);
}

int	rest(t_creature *crea1, t_creature *crea2)
{
  int	i;

  i = crea1->pv;
  crea1->pv = i;
  crea2->pm += 10;
  my_putstr(crea2->name);
  my_putstr(" Restaure 10 PM\n");
  return (0);
}
