/*
** my_swap.c for c in //home/camille/Jour03C/ex4
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Oct 20 11:49:40 2016 VRIGNAUD camille
** Last update Thu Oct 20 11:51:47 2016 VRIGNAUD camille
*/

void	my_swap(int *a, int *b)
{
  int i;

  i = *a;
  *a = *b;
  *b = i;
}
