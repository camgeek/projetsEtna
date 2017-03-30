#include <stdlib.h>
#include <string.h>
#include "BFM.h"

#define NBCREA 10

static t_creature g_creatures[] =
  {
    {"Koopa", 1, 10, 10, 20, 20},
    {"Bob bomb", 1, 30, 30, 20, 20},
    {"Yoshi", 1, 50, 50, 20, 20},
    {"Maskas", 1, 10, 10, 20, 20},
    {"Kucco", 1, 100, 100, 20, 20},
    {"Pikatchoume", 1, 35, 35, 20, 20},
    {"Segmentationnn Fake", 42, 42, 42, 42, 42},
    {"Dofi", 1, 20, 20, 20, 20},
    {"SanGroku", 5, 55, 55, 20, 20},
    {"Mr Satan", 1, 5, 5, 20, 20},
    {NULL, 0, 0, 0, 0, 0}
  };


t_creature	*getCreature()
{
  int		rnd;
  t_creature	*crea;

  rnd = rand() % NBCREA;
  if ((crea = malloc(sizeof(t_creature))) == NULL)
    return (NULL);
  crea->name = strdup(g_creatures[rnd].name);
  if (!crea->name)
    return (NULL);
  crea->lvl = g_creatures[rnd].lvl;
  crea->pv = g_creatures[rnd].pv;
  crea->pvmax = g_creatures[rnd].pvmax;
  crea->pm = g_creatures[rnd].pm;
  crea->pmmax = g_creatures[rnd].pmmax;
  return (crea);
}
