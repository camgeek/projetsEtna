/*
** my_struct.h for c in /home/camille/chifumi
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Thu Oct 27 18:44:27 2016 VRIGNAUD camille
** Last update Sat Oct 29 12:46:50 2016 VRIGNAUD camille
*/
#ifndef _MY_STRUCT_H_
# define MY_STRUCT_H_

typedef struct		 s_joueur
{
  int			score;
  char			*stroke;
  struct s_joueur	*next;
}			t_joueur;

char	*my_strcpy(char *dest, char *src);
char	*readLine();
char	my_putstr(char *str);
void	put_stroke(t_joueur *joueur);
int	my_strcmp(char *s1, char *s2);
int	entry_control(char *str);
int	control_game_n(int human, int bot);
void	aff_res(int res);
int	arg_control(int argc, char **argv);
void	aff_error(int error);
t_joueur *add_item(t_joueur *joueur, int score, char *stroke);
void	fill_list(char x, t_joueur *human, t_joueur *bot, int i);
int	my_random();
void	put_end(t_joueur *human, t_joueur *bot);
char	*loop_entry();
char	*get_chaine(int a);
void	my_put_nbr(int n);
void	init(int *score_a, int *score_b);
void	fill_game_e(char x);
void	fill_game(char x);
void	init_a(int *a, int *b, int *i, char *entry);
void	aff_a();
void	init_b(int *a, int *b, int *i, char *entry);
int	my_random_e();
void	fill_list_e(char x, t_joueur *human, t_joueur *bot, int i);
char	*loop_entry_e();
void	aff_b();
int	control_game_e(int human, int bot);
char	my_putchar(char c);

#endif /* !_MY_STRUCT_H_ */
