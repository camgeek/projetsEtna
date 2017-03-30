/*
** put_stroke.c for c in /home/camille/chifumi
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Fri Oct 28 10:11:46 2016 VRIGNAUD camille
** Last update Sat Oct 29 09:48:12 2016 VRIGNAUD camille
*/

#include "my_struct.h"

void	put_stroke(t_joueur *joueur)
{
  t_joueur *temp;

  temp = joueur;
  while (temp != 0)
    {
      my_putstr("Coup : ");
      my_putstr(temp->stroke);
      my_putstr("\n");
      temp = temp->next;
    }
}

char	*get_chaine(int a)
{
  char	*str;

  if (a == 1)
    str = "pierre";
  if (a == 2)
    str = "feuille";
  if (a == 3)
    str = "ciseaux";
  if (a == 4)
    str = "lezard";
  if (a == 5)
    str = "spocke";
  return (str);
}
