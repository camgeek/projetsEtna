/*
** my_put_nbr.c for my_put_nbr.c in /Users/macbook/Battle For Midgard
** 
** Made by JONDOT Barbara
** Login   <jondot_b@etna-alternance.net>
** 
** Started on  Mon Dec  5 16:19:04 2016 JONDOT Barbara
** Last update Mon Dec  5 16:19:05 2016 JONDOT Barbara
*/

#include <unistd.h>
#include <stdio.h>

void	my_putchar(char c);

void	my_put_nbr(int n)
{
	int	save;
	int	d;

	d = 1;
	if (n < 0)
	{
		n = n * (-1);
		my_putchar('-');
	}
	save = n;
	while (save >= 10)
	{
		d = d * 10;
		save = save / 10;
	}
	while (d > 0)
	{
		my_putchar((n / d) + 48);
		n = n % d;
		d = d / 10;
	}
}
