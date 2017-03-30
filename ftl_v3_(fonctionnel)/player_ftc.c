/*
** player_ftc.c for c in /home/camille/ftl
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Wed Nov  9 14:45:02 2016 VRIGNAUD camille
** Last update Fri Nov 11 09:46:25 2016 VRIGNAUD camille
*/

#include "ftl.h"

static int detect_test = 0;
void	jump(t_ship *ship, t_enemy *enemy)
{
  my_putstr_color("yellow", "Tentative de JUMP *-*-*-*-*-*-*\n");
  if (enemy->life > 0)
    {
      my_putstr_color("red","Un vaisseau pirate nous tire dessus nous ");
      my_putstr_color("red","ne pouvons pas partir A L'ATTAQUE!!!!\n");
    }
  else if(my_strcmp(ship->drive->system_state, "online") != 0)
    my_putstr_color("red","Ho notre réacteur est cassé chef\n");
  else
    {
      ship->navigation->sector += 1;
      ship->drive->energy -= 1;
      if(my_random(100,1) <= 30 && ship->navigation->sector <= 9)
	{
	  add_enemy(enemy);
	  my_putstr_color("magenta","Un vaisseau pirate est apparue !!!!!\n");
	}
      else
	{
	  my_putstr_color("green" ,"Nous avons atteint le nouveau sector ");
	  my_putstr_color("green", "sans encombre capitaine \n");
	}
      detect_test = 0;
    }
}

char	*transform_item()
{
  int	value;

  value = my_random(100,1);
  if (value <= 30)
    {
      value = my_random(100,1);
      if (value >= 1 && value <= 33)
	return ("energy");
      else if (value >=34 && value <=65)
	return ("attackbonus");
      else if (value >=66 && value <= 99)
	return ("evadebonus");
      else
	return ("scrap");
    }
  else
    return ("srcap");
}

void		aff_detect()
{
  my_putstr_color("yellow", "Récupération des freight en cour ...\n");
  my_putstr_color("green", "Ajout des freight OK\n");
  my_putstr_color("green", "Le conteneur a été mis à jour\n");
}

void		detect(t_ship *ship)
{
  int		i;
  t_freight	*freight;

  if (my_strcmp(ship->navigation->system_state, "online") == 0 &&
      detect_test == 0)
    {
      i = 0;
      while (i <= 10)
	{
	  freight = malloc(sizeof(*freight));
	  freight->item = my_strdup(transform_item());
	  add_freight_to_container(ship, freight);
	  i = i + 1;
	}
      detect_test = 1;
      aff_detect();
    }
  else if(detect_test == 1)
    {
      my_putstr_color("red", "\n[SYSTEM] Vous ne pouvez pas detect deux foit");
      my_putstr_color("red", " dans la même zone\n");
    }
  else
    my_putstr_color("red", "SYSTEM DE NAVIGATION HS");
}

void	stat(t_ship *ship)
{
  my_putstr("Il vous reste : ");
  my_put_nbr(ship->hull);
  my_putstr(" point de vie\n Votre laser fait : ");
  my_put_nbr(ship->weapon->damage);
  my_putstr(" de dommage\n Votre esquive est de : ");
  my_put_nbr(ship->navigation->evade);
  my_putstr("\n Votre energie est de : ");
  my_put_nbr(ship->drive->energy);
  my_putstr("\n Vous êtes au sector : ");
  my_put_nbr(ship->navigation->sector);
  my_putstr("\n");
}
