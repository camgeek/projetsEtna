/*
** my_strncpy.c for c in /home/camille/Jour04C/ex3
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Fri Oct 21 11:28:01 2016 VRIGNAUD camille
** Last update Tue Oct 25 17:03:56 2016 VRIGNAUD camille
*/
int	my_strlen(char *str);

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;
  int	length_tab;

  length_tab = my_strlen(src);
  i = 0;
  while (i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (length_tab < n)
    {
      while (n < length_tab)
	{
	  dest[n] = 0;
	  n = n + 1;
	}
    }
  return (dest);
}
