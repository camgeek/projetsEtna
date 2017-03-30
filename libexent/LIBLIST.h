/*
** LIBLIST.h for  in /home/camille/projet/libxtend/vrigna_c/libexent/liblist
**
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
**
** Started on  Thu Feb  2 22:09:17 2017 VRIGNAUD camille
** Last update Sat Feb 11 12:48:25 2017 VRIGNAUD camille
*/

#ifndef __LIBLIST_H__
#define __LIBLIST_H__

#include <time.h>
#include <stdlib.h>

typedef struct			s_content
{
  void			*item;
  int			 index;
  struct s_content		*next;
  struct s_content		*prev;
}				t_content;

typedef struct			s_container
{
  t_content			*first;
  t_content			*last;
  int				nb_elem;
}				t_container;

typedef struct   		s_conflog
{
  char 				*chemin;
  int 				niveau;
}				t_conflog;


char	*my_strdup(char *str);
void	my_putstr(char *str);
void	my_putchar(char c);
int	my_strlen(char *str);
int		my_strcmp(char *s1, char *s2);
t_container		*add_liste();
void	add_content_to_container(t_container *container, t_content *content);
void  del_content_from_container(t_container *container, t_content *content);
t_content *index_init(t_container *container);
t_content *recherche_by_index(t_container *container, int index);
t_content *recherche_by_item(t_container *container, void *item);
void	del_liste(t_container *container);
t_container  *list_arg(int argc, char **argv);
void    add_content(t_container *container, void * item);
void	my_put_nbr(int n);
int create_log (char *message, int niveaux, t_conflog *conflog);
char	*my_strcat(char *dest, char *src);
char *mise_form(char *niveau, char *message);
char	*niveau_log_suite(int niv, char *message, t_conflog *conflog);
char *niveau_log(int niv, char *message, t_conflog *conflog);
void my_putstr_color(char *color,char *str);
void	free_conflog(t_conflog *conflog);

#endif
