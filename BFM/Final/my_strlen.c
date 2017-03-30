/*
** my_strlen.c for my_strlen.c in /Users/macbook/Battle For Midgard
** 
** Made by JONDOT Barbara
** Login   <jondot_b@etna-alternance.net>
** 
** Started on  Mon Dec  5 16:21:11 2016 JONDOT Barbara
** Last update Mon Dec  5 16:21:13 2016 JONDOT Barbara
*/

#include "BFM.h"

int		my_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}
