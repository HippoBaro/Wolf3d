/*
** my_getnbr_base.c for libmy in /home/barrau_h/Desktop/Wolf3D/library/source_libmy
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:25:04 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:25:05 2015 Hippolyte Barraud
*/

#include	"library.h"

int	my_getnbr_base(char *str, char *base)
{
  int	i;
  int	b;
  int	nbr;
  int	multi;
  int	signe;

  nbr = 0;
  multi = 1;
  signe = 1;
  if (str[0] == '-')
    {
      signe = signe *  -1;
      str = &str[1];
    }
  i = my_strlen(str) - 1;
  while (i >= 0)
    {
      b = 0;
      while (str [i] != base [b])
	b = b + 1;
      nbr = nbr + b * multi;
      multi = multi * my_strlen(base);
      i--;
    }
  return (nbr * signe);
}
