/*
** attack.c for c in /home/camille/ftl
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Wed Nov  9 17:52:08 2016 VRIGNAUD camille
** Last update Thu Nov 10 18:35:03 2016 VRIGNAUD camille
*/

#include "ftl.h"

void	attack_IA(t_ship *ship, t_enemy *enemy)
{
  if (enemy->life == 0)
    my_putstr_color("yellow","Aucun pirates au alentours pourquoi tirer ?!\n");
  else
    {
      if (enemy->life > 0)
	{
	  aff_enemy(enemy);
	  att_enemy(enemy, ship);
	  check_life_enemy(enemy);
	}
      if (enemy->life == 0)
	{
	  if(my_random(2,1) == 1)
	    {
	      ship->drive->energy -= 1;
	      my_putstr_color("magenta", "Nous avons perdu une energie");
	    }
	}
    }
}

void	random_offline(t_ship *ship, int i)
{
   if (my_random(100,1) < 20)
	{
	  if (i == 1)
	    {
	      ship->drive->system_state = my_strdup("offline");
	      my_putstr_color("red","Votre réacteur a été toucher\n");
	    }
	 else if (i == 2)
	   {
	     ship->navigation->system_state = my_strdup("offline");
	     my_putstr_color("red","Votre systeme de navigation a été ");
	     my_putstr_color("red","toucher\n");
	   }
	 else
	   {
	     ship->weapon->system_state = my_strdup("offline");
	     my_putstr_color("red","votre laser est Hors Service\n");
	   }
	}
}

void	IA_attack_ME(t_ship *ship, t_enemy *enemy)
{
  int	i;

  i = my_random(3,1);
  if (my_random(100,1) < ship->navigation->evade)
    my_putstr_color("green","Nous avons esquiver le laser ennemi!!!\n");
  else
    {
      ship->hull -= enemy->attack;
      my_putstr("\033[31mLes pirates nous on toucher on a perdu :");
      my_put_nbr(enemy->attack);
      my_putstr(" Points de vie\033[00m\n");
      random_offline(ship , i);
    }
}


