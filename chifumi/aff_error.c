/*
** aff_error.c for c in /home/camille/chifumi
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Oct 27 18:19:47 2016 VRIGNAUD camille
** Last update Sat Oct 29 15:48:54 2016 VRIGNAUD camille
*/

//#include <stdio.h>
//void	my_putstr(char *str);
#include "my_struct.h"

void	aff_error(int error)
{
  my_putstr("Pour utiliser le jeux taper -v (e ou n) -m (3 ou 5)\n");
  if (error == 0)
    my_putstr("\033[31mVous n'avez les 5 arguments obligatoires\n");
  if (error == 1)
    my_putstr("\033[31mle premier paramètre doit être -v\n");
  if (error == 2)
    my_putstr("\033[31mle 3éme paramètre doit être -m\n");
  if (error == 3)
    my_putstr("\033[31mOn ne peut choisir que n (normal) ou e (expert)\n");
  if (error == 4)
    my_putstr("\033[31mOn ne peut choisir que 3 ou 5\n");
}
