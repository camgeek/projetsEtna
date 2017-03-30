/*
** ftl.h for c in /home/camille/ftl
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Mon Nov  7 09:37:03 2016 VRIGNAUD camille
** Last update Fri Nov 11 10:25:49 2016 VRIGNAUD camille
*/

#ifndef	_FTL_H_
#define	_FTL_H_
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <time.h>

typedef	struct			s_ship
{
  int				hull;
  struct s_weapon		*weapon;
  struct s_navigation_tools	*navigation;
  struct s_ftl_drive		*drive;
  struct s_container		*container;
}				t_ship;
typedef struct			s_weapon
{
  char				*system_state;
  int				damage;
}				t_weapon;
typedef struct			s_ftl_drive
{
  char				*system_state;
  int				energy;
}				t_ftl_drive;
typedef struct			s_navigation_tools
{
  char				*system_state;
  int				sector;
  int				evade;
}				t_navigation_tools;
typedef struct			s_freight
{
  char				*item;
  struct s_freight		*next;
  struct s_freight		*prev;
}				t_freight;
typedef struct			s_container
{
  t_freight			*first;
  t_freight			*last;
  int				nb_elem;
}				t_container;
typedef struct			s_repair_command
{
  char				*repar;
  int			        (*fonction)(t_ship *ship);
}				t_repair_command;
typedef	struct			s_enemy
{
  int				life;
  int				attack;
}				t_enemy;
typedef struct			s_game_command
{
  char				*str;
  void				(*f)();
}				t_game_command;

t_ship	*create_ship();
int	add_weapon_to_ship(t_ship *ship);
void	my_putchar(const char c);
int	my_strlen(const char *str);
void	my_putstr(const char *str);
int	my_strcmp(const char *s1, const char *s2);
char	*my_strdup(const char *str);
void	my_putstr_color(const char *color, const char *str);
int	add_ftl_drive_to_ship(t_ship *ship);
int	add_navigation_tools_to_ship(t_ship *ship);
int	add_container_to_ship(t_ship *ship);
void	add_freight_to_container(t_ship *ship, t_freight *freight);
void	del_freight_from_container(t_ship *ship, t_freight *freight);
void	get_bonus(t_ship *ship);
void	ftl_drive_system_check(t_ship *ship);
void	navigation_tools_system_check(t_ship *ship);
void	weapon_system_check(t_ship *ship);
void	system_control(t_ship *ship);
int	ftl_drive_system_repair(t_ship *ship);
int	navigation_tools_system_repair(t_ship *ship);
int	weapon_system_repair(t_ship *ship);
char	*readLine();
int	system_repair(t_ship *ship);
void	add_enemy(t_enemy *enemy);
int	att_enemy(t_enemy *enemy, t_ship *ship);
int	check_life_enemy(t_enemy *enemy);
void	aff_enemy(t_enemy *enemy);
void	my_put_nbr(int n);
int	my_random(int nb1, int nb2);
void	jump(t_ship *ship, t_enemy *enemy);
char	*tranform_item();
void	detect(t_ship *ship);
void	stat(t_ship *ship);
void	attack_IA(t_ship *ship, t_enemy *enemy);
void	IA_attack_ME(t_ship *ship, t_enemy *enemy);
void	game(t_ship *ship);
void	help();
void	cheat(t_ship *ship);

#endif
