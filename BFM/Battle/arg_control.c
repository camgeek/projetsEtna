/*
** arg_control.c for c in /home/camille/Downloads/Partie 1
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Dec  8 10:40:24 2016 VRIGNAUD camille
** Last update Thu Dec  8 10:57:51 2016 VRIGNAUD camille
*/

#include "BFM.h"

int	arg_control(int argc, char **argv)
{
  int	code;

  code = 99;
  if (argc != 3)
    {
      my_putstr("Vous ne pouvez taper qu'un argument [./sta -n VotreLogin]\n");
      code = 1;
    }
  else
    {
      if (argv[1][0] != '-' && argv[1][1] != 'n')
	{
	  my_putstr("Erreur: vous n'avez pas entré [./sta -n VotreLogin]\n");
	  code = 2;
	}
    }
  return (code);
}
