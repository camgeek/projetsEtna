/*
** my_strcmp.c for my_strcmp.c in /Users/macbook/Battle For Midgard
** 
** Made by JONDOT Barbara
** Login   <jondot_b@etna-alternance.net>
** 
** Started on  Mon Dec  5 16:20:14 2016 JONDOT Barbara
** Last update Mon Dec  5 16:20:16 2016 JONDOT Barbara
*/

int	my_strcmp(char *s1, char *s2)
{
  int	a;

  a = 0;
  while (s1[a])
    {
      if (s1[a] > s2[a])
	{
	  return (1);
	}
      else if (s1[a] < s2[a])
	{
	  return (-1);
	}
      a++;
    }
  if (s2[a] != '\0')
    return (-1);
  return (0);
}
