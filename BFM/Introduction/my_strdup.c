/*
** my_strdup.c for my_strdup.c in /Users/macbook/Battle For Midgard
** 
** Made by JONDOT Barbara
** Login   <jondot_b@etna-alternance.net>
** 
** Started on  Mon Dec  5 16:20:57 2016 JONDOT Barbara
** Last update Mon Dec  5 16:20:58 2016 JONDOT Barbara
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "BFM.h"

char	*my_strdup(char *str)
{
	char	*new_str;
	int		i;

	new_str = malloc((my_strlen(str) + 1) *(sizeof(char*)));
	i = 0;
	if (new_str == NULL)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
