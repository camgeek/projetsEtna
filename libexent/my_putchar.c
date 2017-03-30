/*
** my_putchar.c for c in /home/camille/projet/libxtend/vrigna_c/libexent/liblist
**
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
**
** Started on  Thu Feb  2 22:10:54 2017 VRIGNAUD camille
** Last update Sat Feb 11 12:45:26 2017 VRIGNAUD camille
*/

#include <unistd.h>
#include "LIBLIST.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}
