/*
** my_printf_extend.c for libmy in /home/barrau_h/Desktop/Wolf3D/library/source_libmy
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:25:33 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:25:34 2015 Hippolyte Barraud
*/

#include	"library.h"

void	manage_sign(int nbr, char *base)
{
  if (nbr < 0)
    my_putnbr_base((unsigned int) nbr, base);
  else
    my_putnbr_base(nbr, base);
}
void	my_put_unsigned_nbr(unsigned int nbr)
{
  if (nbr > 9)
    my_putnbr(nbr/10);
  my_putchar(nbr % 10 + 48);
}
