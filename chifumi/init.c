/*
** init.c for c in /home/camille/chifumi
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Fri Oct 28 22:57:17 2016 VRIGNAUD camille
** Last update Sat Oct 29 15:55:37 2016 VRIGNAUD camille
*/

#include "my_struct.h"

void	init(int *score_a, int *score_b)
{
  *score_a = 0;
  *score_b = 0;
}

void	init_a(int *a, int *b, int *i, char *entry)
{
  *a = my_random();
  aff_res(control_game_n(entry_control(entry), *a));
  *b = control_game_n(entry_control(entry), *a);
  *i = *i + 1;
}

void	init_b(int *a, int *b, int *i, char *entry)
{
  *a = my_random_e();
  *b = control_game_n(entry_control(entry), *a);
  if ( *b == 99)
    *b = control_game_e(entry_control(entry), *a);
  aff_res(*b);
  *i = *i + 1;
}

void	aff_a()
{
  my_putstr("======================================\n");
  my_putstr("Vous devez utiliser soit pierre , feuille ou ");
  my_putstr("ciseaux Bonne chance :)  \n");
  my_putstr("Pour quitter taper q\n");
  my_putstr("======================================\n");
}

void	aff_b()
{
  my_putstr("======================================\n");
  my_putstr("Vous devez utiliser soit pierre, feuille ,");
  my_putstr("ciseaux, lezard ou spocke Bonne chance :)  \n");
  my_putstr("Pour quitter taper q\n");
  my_putstr("======================================\n");
}
