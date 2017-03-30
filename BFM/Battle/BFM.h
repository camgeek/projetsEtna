/*
** BFM.h for BFM.h in /Users/macbook/Battle For Midgard
** 
** Made by JONDOT Barbara
** Login   <jondot_b@etna-alternance.net>
** 
** Started on  Mon Dec  5 16:17:25 2016 JONDOT Barbara
** Last update Thu Dec  8 10:49:51 2016 VRIGNAUD camille
*/

#ifndef __BFM_H__
# define __BFM_H__

#include <time.h>
#include <stdlib.h>


typedef struct	s_creature
{
  char		*name;
  int		lvl;
  int		pv;
  int		pvmax;
  int		pm;
  int		pmmax;
}		t_creature;

typedef struct		s_content
{
  t_creature		*item;
  struct s_content	*next;
  struct s_content	*prev;
}			t_content;

typedef struct	s_container
{
  t_content	*first;
  t_content	*last;
  int		nb_elem;
}		t_container;

typedef struct	s_player
{
  char		*name;
  t_container	*team;
}		t_player;


typedef struct	s_capture
{
	char	*write;
	int	(*fct_capture)();
}		 t_begin;

typedef struct	s_OoB
{
  char		*write;
  int		(*fctn)();
}		t_OoB;

typedef struct	s_IB
{
  char		*write;
  int		(*function)();
}		t_IB;

int		my_strcmp(char *s1, char *s2);
char		*my_strdup(char *str);
int		my_strlen(char *str);
void		my_putstr(char *str);
void		my_putchar(char c);
char		*readLine();
void		my_put_nbr(int n);
int		beginning(t_player *player);
int		magic();
int		help();
int		test();
t_creature	*getCreature();
int		arg_control(int argc, char **argv);
void		info_creature(t_creature *creature);
t_player	*add_player(char **argv);
void		Start(char **argv);
int		add_team_to_player(t_player *player);
t_content	*add_content(t_creature *creature);
void		add_content_to_team(t_player *player, t_content *content);
void		affiche_team(t_player *player);
t_player	*add_player(char **argv);
void		aff_begin(t_player *player);
int		oob(t_player *player);
int		team();
int		choosen();
int		fight(t_player *player);
int		ib(t_content *content, t_player *player);
int		slash(t_creature *crea1, t_creature *crea2);
int		fire(t_creature *crea1, t_creature *crea2);
int		gamble(t_creature *crea1, t_creature *crea2);
int		rest(t_creature *crea1, t_creature *crea2);
int		attack(t_creature *crea1, t_creature *crea2);
void		del_content_from_container(t_player *player, t_content *content);
int		catch_ib(t_player *player , t_creature *crea2);
void		info_crea2(t_creature *crea2);

#endif
