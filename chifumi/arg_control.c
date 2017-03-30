/*
** arg_control.c for c in /home/camille/chifumi
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Oct 27 15:52:05 2016 VRIGNAUD camille
** Last update Sat Oct 29 12:49:23 2016 VRIGNAUD camille
*/

int	arg_control(int argc, char **argv)
{
  int	code;

  code = 99;
  if (argc != 5)
    code = 0;
  else if (argv[1][0] != '-' || argv[1][1] != 'v')
    code = 1;
  else if (argv[3][0] != '-' || argv[3][1] != 'm')
    code = 2;
  else if (argv[2][0] != 'e' && argv[2][0] != 'n')
    code = 3;
  else if (argv[4][0] != '3' && argv[4][0] != '5')
    code = 4;
  if (code == 99)
    {
      if (argv[2][0] == 'n' && argv[4][0] == '3' && code == 99)
	code = 11;
      else if (argv[2][0] == 'n' && argv[4][0] == '5' && code == 99)
	code = 12;
      else if (argv[2][0] == 'e' && argv[4][0] == '3' && code == 99)
	code = 21;
      else if (argv[2][0] == 'e' && argv[4][0] == '5' && code == 99)
	code = 22;
    }
  return (code);
}
