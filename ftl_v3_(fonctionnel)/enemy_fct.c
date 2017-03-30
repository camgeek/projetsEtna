/*
** enemy_fct.c for c in /home/camille/ftl
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Wed Nov  9 11:03:17 2016 VRIGNAUD camille
** Last update Fri Nov 11 09:24:44 2016 VRIGNAUD camille
*/

#include "ftl.h"

static int	enemy_life = 20;
static int	enemy_attack = 10;

void		add_enemy(t_enemy *enemy)
{
      enemy->life = enemy_life;
      enemy->attack = enemy_attack;
      enemy_life *= 1.5;
      enemy_attack *= 1.5;
      aff_enemy(enemy);
}

int	att_enemy(t_enemy *enemy, t_ship *ship)
{
  if (my_strcmp(ship->weapon->system_state, "online") != 0)
    {
      my_putstr_color("magenta", "Vous ne pouvez pas attaquer notre ");
      my_putstr_color("magenta", " arme est H.S\n");
      return (0);
    }
  else
    {
      enemy->life -= ship->weapon->damage;
      return (1);
    }
}

int	check_life_enemy(t_enemy *enemy)
{
  if (enemy->life <= 0)
    {
      my_putstr_color("cyan", "\nVous avez exploser le vaisseau pirate\n");
      enemy->life = 0;
      enemy->attack = 0;
      return (0);
    }
  else
    {
      my_putstr("\033[32m\nNotre laser touche le vaisseau pirate");
      my_putstr("\nL'ennemie a encore :");
      my_put_nbr(enemy->life);
      my_putstr(" Point de vie\033[00m\n");
      return (1);
    }
}

void	aff_enemy(t_enemy *enemy)
{
  my_putstr("\n--------------------------\n");
  my_putstr("Vaisseau pirate\n");
  my_putstr("Point de vie : ");
  my_put_nbr(enemy->life);
  my_putstr("\n Force du laser : ");
  my_put_nbr(enemy->attack);
  my_putstr("\n--------------------------\n");
}
