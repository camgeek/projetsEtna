/*
** my_getnbr.c for c in /home/camille/Jour05C/ex2
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Sat Oct 22 15:57:08 2016 VRIGNAUD camille
** Last update Tue Oct 25 16:58:45 2016 VRIGNAUD camille
*/

char	my_putchar(char c);

int	my_getnbr(char *str)
{
  int	i;
  int	result;
  int	mark;

  mark = 1;
  result = 0;
  i = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      i = i + 1;
      mark = mark * -1;

    }
  while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    {
      result = result * 10 + str[i] - 48;
      i = i + 1;
    }
  if (mark == -1)
    result = result * -1;
  return (result);
}
