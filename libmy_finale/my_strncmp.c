/*
** my_strncmp.c for c in /home/camille/Jour04C/ex5
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Fri Oct 21 15:14:45 2016 VRIGNAUD camille
** Last update Tue Oct 25 18:18:11 2016 VRIGNAUD camille
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	value;
  int	i;

  value = 0;
  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
    i = i + 1;
  if (s1[i] > s2[i])
    value = 1;
  else if (s1[i] < s2[i])
    value = -1;
  return (value);
}
