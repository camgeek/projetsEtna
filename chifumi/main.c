/*
** main.c for c in /home/camille/chifumi
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Oct 27 15:24:47 2016 VRIGNAUD camille
** Last update Sat Oct 29 10:39:44 2016 VRIGNAUD camille
*/

#include "my_struct.h"

int		arg_control(int argc, char **argv);
void		aff_error(int error);
t_joueur	*add_item(t_joueur *joueur, int score, char *stroke);

int		main(int argc, char **argv)
{
  if (arg_control(argc, argv) < 5)
    aff_error(arg_control(argc, argv));
  else
    {
      if (argv[2][0] == 'n')
	fill_game(argv[4][0]);
      else if (argv[2][0] == 'e')
	{
	  fill_game_e(argv[4][0]);
	}
    }
  return (0);
}
