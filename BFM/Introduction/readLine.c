/*
** readLine.c for readLine.c in /Users/macbook/Battle For Midgard
** 
** Made by JONDOT Barbara
** Login   <jondot_b@etna-alternance.net>
** 
** Started on  Mon Dec  5 16:21:25 2016 JONDOT Barbara
** Last update Mon Dec  5 16:21:26 2016 JONDOT Barbara
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "BFM.h"

char	*readLine()
{
	ssize_t	ret;
	char	*buff;

	if ((buff = malloc(sizeof(*buff) * (50 + 1))) == NULL)
		return (NULL);
	if ((ret = read(0, buff, 50)) > 1)
	{
		buff[ret - 1] = '\0';
		return (buff);
	}
	buff[0] = '\0';
	return (buff);
}
