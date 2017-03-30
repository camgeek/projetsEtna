/*
** gest_log.c for c in /home/camille/repertoire_rendu/libextend/vrigna_c/libexent
** 
** Made by VRIGNAUD camille
** Login   <vrigna_c@etna-alternance.net>
** 
** Started on  Sat Feb 11 12:39:35 2017 VRIGNAUD camille
** Last update Thu Feb 23 23:36:27 2017 VRIGNAUD camille
*/

#include "LIBLIST.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	create_log (char *message, int niveaux, t_conflog *conflog)
{
  int	file;
  int	ret_val;
  int	ret_code;
  char	*envoie;

  file=open(conflog->chemin,O_CREAT | O_WRONLY | O_APPEND,0640);
  if (file < 0)
    file=open("journal.log",O_CREAT | O_WRONLY | O_APPEND,0640);
  if (file > 0)
    {
      if (niveaux > 0 && niveaux <= 4)
	{
	  envoie = niveau_log(niveaux, message, conflog);
	  ret_val = write(file,envoie,my_strlen(envoie));
	  if (ret_val != -1)
	    ret_code = EXIT_SUCCESS;
	  else
	    ret_code = EXIT_FAILURE;
	}
    }
  close(file);

  return (ret_code);
}
char	*niveau_log(int niv, char *message, t_conflog *conflog)
{
  char	*niveau;

  if (niv == 1 && niv >= conflog->niveau)
    {
      niveau = my_strdup("DEBUG");
      niveau = mise_form(niveau,message);
      my_putstr_color("green", niveau);
    }
  else if(niv == 2 && niv >= conflog->niveau)
    {
      niveau = my_strdup("INFO");
      niveau = mise_form(niveau,message);
      my_putstr_color("blue", niveau);
    }
  else
    niveau = niveau_log_suite(niv, message, conflog);

  return (niveau);
}

char	*niveau_log_suite(int niv, char *message, t_conflog *conflog)
{
  char	*niveau;

  if(niv == 3 && niv >= conflog->niveau)
    {
      niveau = my_strdup("WARNING");
      niveau = mise_form(niveau,message);
      my_putstr_color("yellow", niveau);
    }
  else if(niv == 4 && niv >= conflog->niveau)
    {
      niveau = my_strdup("DANGER");
      niveau = mise_form(niveau,message);
      my_putstr_color("red", niveau);
    }
  return (niveau);
}

char	*mise_form(char *niveau, char *message)
{
  char	*envoie;
  envoie = my_strdup("[");
  my_strcat(envoie,niveau);
  my_strcat(envoie, "] ");
  my_strcat(envoie, message);
  return (envoie);
}

void	free_conflog(t_conflog *conflog)
{
  free(conflog->chemin);
  free(conflog);
}
