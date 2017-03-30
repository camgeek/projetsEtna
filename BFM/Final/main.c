/*
** main.c for main.c in /Users/macbook/Battle For Midgard
** 
** Made by JONDOT Barbara
** Login   <jondot_b@etna-alternance.net>
** 
** Started on  Mon Dec  5 16:18:41 2016 JONDOT Barbara
** Last update Thu Dec  8 10:57:31 2016 VRIGNAUD camille
*/
#include "BFM.h"

int	main(int argc, char **argv)
{
  srand(time(NULL));
  if (arg_control(argc, argv) == 99)
    {
      Start(argv);
    }
  return (0);
}
