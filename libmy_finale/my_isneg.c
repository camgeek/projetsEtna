/*
** my_isneg.c for c in /home/camille/ex8
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Mon Oct 17 16:09:48 2016 VRIGNAUD camille
** Last update Wed Oct 26 08:28:37 2016 VRIGNAUD camille
*/

int	my_isneg(int n)
{
  char	result;

  if( n < 0 )
    {
      result = 0;
    }
  else
    {
      result = 1;
    }
  return (result);
}
