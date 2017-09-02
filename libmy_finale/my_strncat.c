/*
** my_strncat.c for c in /home/camille/Jour04C/ex6
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Fri Oct 21 17:09:12 2016 VRIGNAUD camille
** Last update Tue Oct 25 17:03:01 2016 VRIGNAUD camille
*/

int	my_strlen(char *str);

char	*my_strncat(char *dest, char *src, int n)
{
  int i;
  int j;

  i = 0;
  j = my_strlen(dest);
      while (i < n)
	{
	  dest[j] = src[i];
	  j = j + 1;
	  i = i + 1;
	}
  dest[my_strlen(dest)] = '\0';
  return (dest);
}
