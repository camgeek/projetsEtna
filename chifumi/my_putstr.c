/*
** my_putstr.c for c in //home/camille/Jour03C
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Oct 20 10:26:45 2016 VRIGNAUD camille
** Last update Sat Oct 29 10:47:15 2016 VRIGNAUD camille
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
