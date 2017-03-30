/*
** my_strcmp.c for c in /home/camille/projet/libxtend/vrigna_c/libexent/liblist
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Feb  2 22:11:37 2017 VRIGNAUD camille
** Last update Sat Feb 11 12:47:12 2017 VRIGNAUD camille
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
