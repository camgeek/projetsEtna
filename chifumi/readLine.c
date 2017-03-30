/*
** readLine.c for c in /home/camille/roulette
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Sat Oct 22 09:05:08 2016 VRIGNAUD camille
** Last update Fri Oct 28 12:12:06 2016 VRIGNAUD camille
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

char	*readLine()
{
  ssize_t ret;
  char	  *buff;

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
