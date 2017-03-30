/*
** my_strcmp.c for c in /home/camille/Jour04C/ex4
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Fri Oct 21 13:35:42 2016 VRIGNAUD camille
** Last update Tue Oct 25 17:45:18 2016 VRIGNAUD camille
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	value;

  value = 0;
  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    i = i + 1;
  if (s1[i] == '\0' && s2[i] == '\0')
    value = 0;
  if (s1[i] < s2[i])
    value = -1;
  else if (s1[i] > s2[i])
    value = 1;
  return (value);
}
