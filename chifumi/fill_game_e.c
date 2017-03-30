/*
** main.c for c in /home/camille/chifumi
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Oct 27 15:24:47 2016 VRIGNAUD camille
** Last update Sat Oct 29 15:54:51 2016 VRIGNAUD camille
*/

#include "my_struct.h"
#include <stdlib.h>
#include <time.h>

void	fill_game_e(char x)
{
  t_joueur	*joueur;
  t_joueur	*joueur_a;
  int		i;
  char		*choix;

  choix = "x";
  while (choix[0] != 'q')
    {
      i = 1;
      joueur = 0;
      joueur_a = 0;
      my_putstr("\033[H\033[J");
      aff_b();
      fill_list_e(x, joueur, joueur_a, i);
      my_putstr("\n Fin de la partie,taper q pour quitter ou n'importe ");
      my_putstr("quelle touche pour rejouer");
      choix = readLine();
    }
}

void	fill_list_e(char x, t_joueur *human, t_joueur *bot, int i)
{
  char		*entry;
  int		a;
  int		score_a;
  int		score_b;
  int		b;

  init(&score_a, &score_b);
  while (i <= x - 48)
    {
      entry = loop_entry_e();
      if (entry[0] != 'q')
	{
	  init_b(&a, &b, &i, entry);
	  score_a = (b == 1) ? score_a + 1 :score_a;
	  score_b = (b == 2) ? score_b + 1 :score_b;
	  human =  add_item(human, score_a, entry);
	  entry = get_chaine(a);
	  bot = add_item(bot, score_b, entry);
	}
      else
	i = 66;
    }
  if (i != 66)
  put_end(human, bot);
}

int	my_random_e()
{
  int random;

  srand (time (NULL));
  random = (rand()% 5) + 1;
  return (random);
}

char	*loop_entry_e()
{
  char	*str;

  str = readLine();
  while (entry_control(str) == 99)
    {
      my_putstr("\033[31mERREUR !!!, Pour rapelle vous devez taper soit : ");
      my_putstr(" feuille");
      my_putstr(", ciseaux, pierre, lezard  ou spocke ");
      my_putstr("q pour quitter la partie\033[00m\n");
      str = readLine();
    }
  return (str);
}
