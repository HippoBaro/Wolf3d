/*
** my_getnbr.c for wolf3d in /home/barrau_h/Desktop/Wolf3D/library/source_libmy
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:24:51 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:24:52 2015 Hippolyte Barraud
*/

#include	"library.h"

int		my_getnbr(char *str)
{
  int		i;
  unsigned int	nbr;
  int		multi;
  int		signe;

  signe = 1;
  multi = 1;
  nbr = 0;
  i = 0;
  if (str[0] == '-')
    {
      signe = -1;
      str = &str[1];
    }
  i = -1;
  while (str[++i] != '\0' && str[i] >= '0' && str[i] <= '9');
  while ((i - 1) >= 0)
    {
      nbr = nbr + (str[i - 1] - '0') * multi;
      multi = multi * 10;
      i--;
    }
  if (nbr > 2147483647 || (my_strlen(str) >= 10 && str[0] > '2'))
    return (0);
  return ((nbr * signe));
}
