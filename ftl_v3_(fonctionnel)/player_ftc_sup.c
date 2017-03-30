/*
** player_ftc_sup.c for c in /home/camille/ftl
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Nov 10 16:45:09 2016 VRIGNAUD camille
** Last update Fri Nov 11 10:30:33 2016 VRIGNAUD camille
*/

#include "ftl.h"

void	help()
{
  my_putstr_color("blue", "jump  [Avance au prochain sector]\n");
  my_putstr_color("blue", "detect  [Trouve des composants]\n");
  my_putstr_color("blue", "attack  [Envoie un tir de laser]\n");
  my_putstr_color("blue", "get_bonus  [Ajoute les composants a votre");
  my_putstr_color("blue", " vaisseau]\n");
  my_putstr_color("blue", "help  [Affiche l'aide]\n");
  my_putstr_color("blue", "system_repair [Repare un élément]\n");
  my_putstr_color("blue", "system_control  [Controlles éléments]\n");
}

void	cheat(t_ship *ship)
{
  char	*str;

  my_putstr_color("yellow", "cheat_code~>");
  str = readLine();
  if (my_strcmp(str, "attack") == 0)
    {
      ship->weapon->damage += 100;
      my_putstr_color("green", "Vous avez augmenter la puissance de ");
      my_putstr_color("green", " votre laser de 100\n");
    }
  else if (my_strcmp(str, "life") == 0)
    {
      ship->hull += 100;
      my_putstr_color("green", "Vous avez augmenter votre vie de 100\n");
    }
  else if(my_strcmp(str, "energy") == 0)
    {
      ship->drive->energy += 100;
      my_putstr_color("green", "Vous avez augmenter votre energie de 100\n");
    }
  else
    my_putstr_color("red", "[SYSTEM] Erreur ce code de cheat n'existe pas");
}
