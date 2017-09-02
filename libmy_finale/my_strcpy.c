/*
** my_strcpy.c for c in /home/camille/Jour04C/ex2
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Fri Oct 21 10:41:59 2016 VRIGNAUD camille
** Last update Tue Oct 25 17:02:04 2016 VRIGNAUD camille
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i  = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
