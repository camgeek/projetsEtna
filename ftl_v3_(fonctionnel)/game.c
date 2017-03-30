
/*
** game.c for c in /home/camille/ftl
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Wed Nov  9 17:19:06 2016 VRIGNAUD camille
** Last update Fri Nov 11 10:26:09 2016 VRIGNAUD camille
*/

#include "ftl.h"

void	catch_err_repair(t_ship *ship)
{
  if(system_repair(ship) == 1)
    my_putstr("tous c'est bien passer commandant\n");
  else
    my_putstr("ERREUR QUITTER LES NAVIRE\n");
}

static const t_game_command g_game_command[] =
  {
    {"jump",&jump},
    {"stat",&stat},
    {"detect",&detect},
    {"attack",&attack_IA},
    {"system_control",&system_control},
    {"get_bonus",&get_bonus},
    {"system_repair",&catch_err_repair},
    {"help",&help},
    {"cheat",&cheat},
    {NULL, NULL}
  };

void	game_loop(t_ship *ship, t_enemy *enemy, int *i, char *str)
{
  int	test;

  test = 0;
  while (g_game_command[*i].str != NULL)
    {
      if (my_strcmp(g_game_command[*i].str, str) == 0)
	{
	  g_game_command[*i].f(ship, enemy);
	  test = 1;
	}
      *i = *i + 1;
    }
  if (test == 0)
    my_putstr_color("red", "[SYSTEM] commade inconnue\n");
  if (enemy->life > 0 && ship->navigation->sector <= 9)
    IA_attack_ME(ship, enemy);
}

void	end(t_ship *ship)
{
  if (ship->hull <= 0)
    {
      my_putstr_color("red", "\n******************\n");
      my_putstr_color("red", "Notre vaisseau prend feu mon commandant\n");
      my_putstr_color("red", "*Bruit d'explosion*\n");
      my_putstr_color("red", "Votre vaisseau à exploser dans le vide\n");
      my_putstr_color("red", "GAME OVER\n");
      my_putstr_color("red", "******************\n");
    }
  if (ship->drive->energy <= 0)
    {
      my_putstr_color("red", "\n******************\n");
      my_putstr_color("red", "Nous n'avons plus d'ernegie nous somme ");
      my_putstr_color("red", "condamner a une mort certaine\n");
      my_putstr_color("red", "GAME OVER\n");
      my_putstr_color("red", "******************\n");
    }
  else if(ship->navigation->sector >= 10)
    {
      my_putstr_color("green", "\n******************\n");
      my_putstr_color("green", "BRAVO nous avons atteint le nouveau monde\n");
      my_putstr_color("green", "Vous avez gagner pour le moment\n");
      my_putstr_color("green", "******************\n");
    }
}

void		game(t_ship *ship)
{
  t_enemy	*enemy;
  int		i;
  char		*str;

  i = 0;
  enemy = malloc(sizeof(*enemy));
  enemy->life = 0;
  while ((ship->navigation->sector <= 9) && (ship->hull > 0) &&
	 (ship->drive->energy > 0))
    {
      srand (time (NULL));
      my_putstr_color("magenta","\nVos ordes->");
      str = readLine();
      if (str == NULL)
	my_putstr("[SYSTEM FAILURE]: le lecteur de commande est bloque");
      else
	{
	  game_loop(ship, enemy, &i, str);
	}
      i = 0;
    }
  end(ship);
  free(enemy);
}
