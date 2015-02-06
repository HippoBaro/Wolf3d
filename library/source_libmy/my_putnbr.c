/*
** my_putnbr.c for libmy in /home/barrau_h/Desktop/Wolf3D/library/source_libmy
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:26:41 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:26:42 2015 Hippolyte Barraud
*/

#include	"library.h"

void	my_putnbr(int nbr)
{
  if (nbr < 0)
    {
      nbr = nbr * -1;
      if (nbr > 0)
	my_putchar('-');
    }
  if (nbr > 9 || nbr < -9)
    my_putnbr(nbr / 10);
  if (nbr % 10 >= 0)
    my_putchar(nbr % 10 + 48);
  else
    my_putchar(nbr % 10 * -1 + 48);
}
