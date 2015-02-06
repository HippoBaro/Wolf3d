/*
** get_values.c for wolf3d in /home/barrau_h/Desktop/Wolf3D/source
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:15:15 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:15:17 2015 Hippolyte Barraud
*/

#include	<math.h>
#include	"library.h"
#include	"wolf3D.h"

double	*get_the_cos()
{
  double	*result;
  double	i;

  i = 0;
  result = xmalloc(sizeof(double) * 360);
  while (i <= 360)
    {
      result[(int)i] = cos(i / 180 * PI);
      i++;
    }
  return (result);
}

double	*get_the_sin()
{
  double	*result;
  double	i;

  i = 0;
  printf("sinus:");
  result = xmalloc(sizeof(double) * 360);
  while (i <= 360)
    {
      result[(int)i] = sin(i / 180 * PI);
      i++;
    }
  return (result);
}
