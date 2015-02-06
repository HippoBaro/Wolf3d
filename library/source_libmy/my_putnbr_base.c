/*
** my_putnbr_base.c for libmy in /home/barrau_h/Desktop/Wolf3D/library/source_libmy
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:26:54 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:26:55 2015 Hippolyte Barraud
*/

#include	"library.h"

void	my_putnbr_base(int nbr, char *base)
{
  if (nbr < 0)
    {
      nbr = nbr * -1;
      if (nbr > 0)
	my_putchar('-');
    }
  if (nbr > (my_strlen(base) - 1) || nbr < -(my_strlen(base) - 1))
    my_putnbr_base((nbr / my_strlen(base)), base);
  if (nbr % 10 >= 0)
    my_putchar(base[nbr % my_strlen(base)]);
  else
    my_putchar(base[nbr % my_strlen(base) * -1]);
}
