/*
** my_strstr.c for  in /home/camille/Jour04C/ex9
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Sat Oct 22 17:49:34 2016 VRIGNAUD camille
** Last update Sat Oct 22 18:02:48 2016 VRIGNAUD camille
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;

  if (str[0] != '\0')
    {
      i = 0;
      while (to_find[i] != '\0')
	{
	  if (to_find[i] != str[i])
	    return (my_strstr(str + 1, to_find));
	  i = i + 1;
	}
      return (str);
    }
  else
    return (0);
}
