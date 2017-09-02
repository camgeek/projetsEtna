/*
** my_putstr.c for c in //home/camille/Jour03C
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Oct 20 10:26:45 2016 VRIGNAUD camille
** Last update Tue Oct 25 17:00:55 2016 VRIGNAUD camille
*/

char	my_putchar(char c);

void	my_putstr(char *str)
{
  while ( *str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}
