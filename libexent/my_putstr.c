/*
** my_putstr.c for  in /home/camille/projet/libxtend/vrigna_c/libexent/liblist
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Feb  2 22:11:18 2017 VRIGNAUD camille
** Last update Fri Feb  3 15:41:52 2017 VRIGNAUD camille
*/

#include "LIBLIST.h"

void	my_putstr(char *str)
{
  if (str != NULL)
    {
      while (*str != '\0')
	{
	  my_putchar(*str);
	  str++;
	}
    }
}
