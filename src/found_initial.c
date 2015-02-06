/*
** found_initial.c for wolf3d in /home/barrau_h/Desktop/Wolf3D/source
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Thu Jan 15 17:04:30 2015 Hippolyte Barraud
** Last update Thu Jan 15 17:04:31 2015 Hippolyte Barraud
*/

#include	<stdio.h>
#include	"library.h"

float	*check_others(float *result, char **tab)
{
  if (result[0] == -1)
    {
      result[1] = (float) my_tablen(tab) / 2;
      result[0] = (float) my_strlen(tab[(int)result[1]]) / 2;
    }
  return (result);
}

float	*found_initial(char **tab)
{
  float	*result;
  int	i;
  int	j;

  i = -1;
  result = xmalloc(sizeof(float) * 2);
  result[0] = -1;
  while (++i < my_tablen(tab))
    {
      j = 0;
      while (j < my_strlen(tab[i]))
	{
	  if (tab[i][j] == '4')
	    {
	      tab[i][j] = '0';
	      if (result[0] == -1)
		{
		  result[0] = j + 0.5;
		  result[1] = i + 0.5;
		}
	    }
	  j++;
	}
    }
  return (check_others(result, tab));
}
